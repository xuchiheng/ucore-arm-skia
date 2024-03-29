/*
    Copyright 2010 Google Inc.

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

         http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
 */

#include "GrBufferAllocPool.h"
#include "GrTypes.h"
#include "GrVertexBuffer.h"
#include "GrIndexBuffer.h"
#include "GrGpu.h"

#if GR_DEBUG
    #define VALIDATE validate
#else
    #define VALIDATE()
#endif

#define GrBufferAllocPool_MIN_BLOCK_SIZE ((size_t)1 << 12)

GrBufferAllocPool::GrBufferAllocPool(GrGpu* gpu,
                                     BufferType bufferType,
                                     bool frequentResetHint,
                                     size_t blockSize,
                                     int preallocBufferCnt) :
        fBlocks(GrMax(8, 2*preallocBufferCnt)) {

    GrAssert(NULL != gpu);
    fGpu = gpu;
    fGpu->ref();
    fGpuIsReffed = true;

    fBufferType = bufferType;
    fFrequentResetHint = frequentResetHint;
    fBufferPtr = NULL;
    fMinBlockSize = GrMax(GrBufferAllocPool_MIN_BLOCK_SIZE, blockSize);

    fPreallocBuffersInUse = 0;
    fFirstPreallocBuffer = 0;
    for (int i = 0; i < preallocBufferCnt; ++i) {
        GrGeometryBuffer* buffer = this->createBuffer(fMinBlockSize);
        if (NULL != buffer) {
            *fPreallocBuffers.append() = buffer;
            buffer->ref();
        }
    }
}

GrBufferAllocPool::~GrBufferAllocPool() {
    VALIDATE();
    if (fBlocks.count()) {
        GrGeometryBuffer* buffer = fBlocks.back().fBuffer;
        if (buffer->isLocked()) {
            buffer->unlock();
        }
    }
    while (!fBlocks.empty()) {
        destroyBlock();
    }
    fPreallocBuffers.unrefAll();
    releaseGpuRef();
}

void GrBufferAllocPool::releaseGpuRef() {
    if (fGpuIsReffed) {
        fGpu->unref();
        fGpuIsReffed = false;
    }
}

void GrBufferAllocPool::reset() {
    VALIDATE();
    if (fBlocks.count()) {
        GrGeometryBuffer* buffer = fBlocks.back().fBuffer;
        if (buffer->isLocked()) {
            buffer->unlock();
        }
    }
    while (!fBlocks.empty()) {
        destroyBlock();
    }
    if (fPreallocBuffers.count()) {
        // must set this after above loop.
        fFirstPreallocBuffer = (fFirstPreallocBuffer + fPreallocBuffersInUse) %
                               fPreallocBuffers.count();
    }
    fCpuData.realloc(fGpu->supportsBufferLocking() ? 0 : fMinBlockSize);
    GrAssert(0 == fPreallocBuffersInUse);
    VALIDATE();
}

void GrBufferAllocPool::unlock() {
    VALIDATE();

    if (NULL != fBufferPtr) {
        BufferBlock& block = fBlocks.back();
        if (block.fBuffer->isLocked()) {
            block.fBuffer->unlock();
        } else {
            size_t flushSize = block.fBuffer->size() - block.fBytesFree;
            flushCpuData(fBlocks.back().fBuffer, flushSize);
        }
        fBufferPtr = NULL;
    }
    VALIDATE();
}

#if GR_DEBUG
void GrBufferAllocPool::validate() const {
    if (NULL != fBufferPtr) {
        GrAssert(!fBlocks.empty());
        if (fBlocks.back().fBuffer->isLocked()) {
            GrGeometryBuffer* buf = fBlocks.back().fBuffer;
            GrAssert(buf->lockPtr() == fBufferPtr);
        } else {
            GrAssert(fCpuData.get() == fBufferPtr);
            GrAssert(fCpuData.size() == fBlocks.back().fBuffer->size());
        }
    } else {
        GrAssert(fBlocks.empty() || !fBlocks.back().fBuffer->isLocked());
    }
    for (int i = 0; i < fBlocks.count() - 1; ++i) {
        GrAssert(!fBlocks[i].fBuffer->isLocked());
    }
}
#endif

void* GrBufferAllocPool::makeSpace(size_t size,
                                   size_t alignment,
                                   const GrGeometryBuffer** buffer,
                                   size_t* offset) {
    VALIDATE();

    GrAssert(NULL != buffer);
    GrAssert(NULL != offset);

    if (NULL != fBufferPtr) {
        BufferBlock& back = fBlocks.back();
        size_t usedBytes = back.fBuffer->size() - back.fBytesFree;
        size_t pad = GrSizeAlignUpPad(usedBytes,
                                      alignment);
        if ((size + pad) <= back.fBytesFree) {
            usedBytes += pad;
            *offset = usedBytes;
            *buffer = back.fBuffer;
            back.fBytesFree -= size + pad;
            return (void*)(reinterpret_cast<intptr_t>(fBufferPtr) + usedBytes);
        }
    }

    if (!createBlock(size)) {
        return NULL;
    }
    VALIDATE();
    GrAssert(NULL != fBufferPtr);

    *offset = 0;
    BufferBlock& back = fBlocks.back();
    *buffer = back.fBuffer;
    back.fBytesFree -= size;
    return fBufferPtr;
}

int GrBufferAllocPool::currentBufferItems(size_t itemSize) const {
    VALIDATE();
    if (NULL != fBufferPtr) {
        const BufferBlock& back = fBlocks.back();
        size_t usedBytes = back.fBuffer->size() - back.fBytesFree;
        size_t pad = GrSizeAlignUpPad(usedBytes, itemSize);
        return (back.fBytesFree - pad) / itemSize;
    } else if (fPreallocBuffersInUse < fPreallocBuffers.count()) {
        return fMinBlockSize / itemSize;
    }
    return 0;
}

int GrBufferAllocPool::preallocatedBuffersRemaining() const {
    return fPreallocBuffers.count() - fPreallocBuffersInUse;
}

int GrBufferAllocPool::preallocatedBufferCount() const {
    return fPreallocBuffers.count();
}

void GrBufferAllocPool::putBack(size_t bytes) {
    VALIDATE();
    if (NULL != fBufferPtr) {
        BufferBlock& back = fBlocks.back();
        size_t bytesUsed = back.fBuffer->size() - back.fBytesFree;
        if (bytes >= bytesUsed) {
            destroyBlock();
            bytes -= bytesUsed;
        } else {
            back.fBytesFree += bytes;
            return;
        }
    }
    VALIDATE();
    GrAssert(NULL == fBufferPtr);
    // we don't partially roll-back buffers because our VB semantics say locking
    // a VB discards its previous content.
    // We could honor it by being sure we use updateSubData and not lock
    // we will roll-back fully released buffers, though.
    while (!fBlocks.empty() &&
           bytes >= fBlocks.back().fBuffer->size()) {
        bytes -= fBlocks.back().fBuffer->size();
        destroyBlock();
    }
    VALIDATE();
}

bool GrBufferAllocPool::createBlock(size_t requestSize) {

    size_t size = GrMax(requestSize, fMinBlockSize);
    GrAssert(size >= GrBufferAllocPool_MIN_BLOCK_SIZE);

    VALIDATE();

    BufferBlock& block = fBlocks.push_back();

    if (size == fMinBlockSize &&
        fPreallocBuffersInUse < fPreallocBuffers.count()) {

        uint32_t nextBuffer = (fPreallocBuffersInUse + fFirstPreallocBuffer) %
                               fPreallocBuffers.count();
        block.fBuffer = fPreallocBuffers[nextBuffer];
        block.fBuffer->ref();
        ++fPreallocBuffersInUse;
    } else {
        block.fBuffer = this->createBuffer(size);
        if (NULL == block.fBuffer) {
            fBlocks.pop_back();
            return false;
        }
    }

    block.fBytesFree = size;
    if (NULL != fBufferPtr) {
        GrAssert(fBlocks.count() > 1);
        BufferBlock& prev = fBlocks.fromBack(1);
        if (prev.fBuffer->isLocked()) {
            prev.fBuffer->unlock();
        } else {
            flushCpuData(prev.fBuffer,
                         prev.fBuffer->size() - prev.fBytesFree);
        }
        fBufferPtr = NULL;
    }

    GrAssert(NULL == fBufferPtr);

    if (fGpu->supportsBufferLocking() &&
        size > GR_GEOM_BUFFER_LOCK_THRESHOLD &&
        (!fFrequentResetHint || requestSize > GR_GEOM_BUFFER_LOCK_THRESHOLD)) {
        fBufferPtr = block.fBuffer->lock();
    }

    if (NULL == fBufferPtr) {
        fBufferPtr = fCpuData.realloc(size);
    }

    VALIDATE();

    return true;
}

void GrBufferAllocPool::destroyBlock() {
    GrAssert(!fBlocks.empty());

    BufferBlock& block = fBlocks.back();
    if (fPreallocBuffersInUse > 0) {
        uint32_t prevPreallocBuffer = (fPreallocBuffersInUse +
                                       fFirstPreallocBuffer +
                                       (fPreallocBuffers.count() - 1)) %
                                      fPreallocBuffers.count();
        if (block.fBuffer == fPreallocBuffers[prevPreallocBuffer]) {
            --fPreallocBuffersInUse;
        }
    }
    GrAssert(!block.fBuffer->isLocked());
    block.fBuffer->unref();
    fBlocks.pop_back();
    fBufferPtr = NULL;
}

void GrBufferAllocPool::flushCpuData(GrGeometryBuffer* buffer,
                                     size_t flushSize) {
    GrAssert(NULL != buffer);
    GrAssert(!buffer->isLocked());
    GrAssert(fCpuData.get() == fBufferPtr);
    GrAssert(fCpuData.size() == buffer->size());
    GrAssert(flushSize <= buffer->size());

    bool updated = false;
    if (fGpu->supportsBufferLocking() &&
        flushSize > GR_GEOM_BUFFER_LOCK_THRESHOLD) {
        void* data = buffer->lock();
        if (NULL != data) {
            memcpy(data, fBufferPtr, flushSize);
            buffer->unlock();
            updated = true;
        }
    }
    buffer->updateData(fBufferPtr, flushSize);
}

GrGeometryBuffer* GrBufferAllocPool::createBuffer(size_t size) {
    if (kIndex_BufferType == fBufferType) {
        return fGpu->createIndexBuffer(size, true);
    } else {
        GrAssert(kVertex_BufferType == fBufferType);
        return fGpu->createVertexBuffer(size, true);
    }
}

////////////////////////////////////////////////////////////////////////////////

GrVertexBufferAllocPool::GrVertexBufferAllocPool(GrGpu* gpu,
                                                 bool frequentResetHint,
                                                 size_t bufferSize,
                                                 int preallocBufferCnt)
: GrBufferAllocPool(gpu,
                    kVertex_BufferType,
                    frequentResetHint,
                    bufferSize,
                    preallocBufferCnt) {
}

void* GrVertexBufferAllocPool::makeSpace(GrVertexLayout layout,
                                         int vertexCount,
                                         const GrVertexBuffer** buffer,
                                         int* startVertex) {

    GrAssert(vertexCount >= 0);
    GrAssert(NULL != buffer);
    GrAssert(NULL != startVertex);

    size_t vSize = GrDrawTarget::VertexSize(layout);
    size_t offset;
    const GrGeometryBuffer* geomBuffer;
    void* ptr = INHERITED::makeSpace(vSize * vertexCount,
                                     vSize,
                                     &geomBuffer,
                                     &offset);

    *buffer = (const GrVertexBuffer*) geomBuffer;
    GrAssert(0 == offset % vSize);
    *startVertex = offset / vSize;
    return ptr;
}

bool GrVertexBufferAllocPool::appendVertices(GrVertexLayout layout,
                                             int vertexCount,
                                             const void* vertices,
                                             const GrVertexBuffer** buffer,
                                             int* startVertex) {
    void* space = makeSpace(layout, vertexCount, buffer, startVertex);
    if (NULL != space) {
        memcpy(space,
               vertices,
               GrDrawTarget::VertexSize(layout) * vertexCount);
        return true;
    } else {
        return false;
    }
}

int GrVertexBufferAllocPool::preallocatedBufferVertices(GrVertexLayout layout) const {
    return INHERITED::preallocatedBufferSize() /
            GrDrawTarget::VertexSize(layout);
}

int GrVertexBufferAllocPool::currentBufferVertices(GrVertexLayout layout) const {
    return currentBufferItems(GrDrawTarget::VertexSize(layout));
}

////////////////////////////////////////////////////////////////////////////////

GrIndexBufferAllocPool::GrIndexBufferAllocPool(GrGpu* gpu,
                                               bool frequentResetHint,
                                               size_t bufferSize,
                                               int preallocBufferCnt)
: GrBufferAllocPool(gpu,
                    kIndex_BufferType,
                    frequentResetHint,
                    bufferSize,
                    preallocBufferCnt) {
}

void* GrIndexBufferAllocPool::makeSpace(int indexCount,
                                        const GrIndexBuffer** buffer,
                                        int* startIndex) {

    GrAssert(indexCount >= 0);
    GrAssert(NULL != buffer);
    GrAssert(NULL != startIndex);

    size_t offset;
    const GrGeometryBuffer* geomBuffer;
    void* ptr = INHERITED::makeSpace(indexCount * sizeof(uint16_t),
                                     sizeof(uint16_t),
                                     &geomBuffer,
                                     &offset);

    *buffer = (const GrIndexBuffer*) geomBuffer;
    GrAssert(0 == offset % sizeof(uint16_t));
    *startIndex = offset / sizeof(uint16_t);
    return ptr;
}

bool GrIndexBufferAllocPool::appendIndices(int indexCount,
                                           const void* indices,
                                           const GrIndexBuffer** buffer,
                                           int* startIndex) {
    void* space = makeSpace(indexCount, buffer, startIndex);
    if (NULL != space) {
        memcpy(space, indices, sizeof(uint16_t) * indexCount);
        return true;
    } else {
        return false;
    }
}

int GrIndexBufferAllocPool::preallocatedBufferIndices() const {
    return INHERITED::preallocatedBufferSize() / sizeof(uint16_t);
}

int GrIndexBufferAllocPool::currentBufferIndices() const {
    return currentBufferItems(sizeof(uint16_t));
}
