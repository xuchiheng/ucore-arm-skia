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


#include "GrDrawTarget.h"
#include "GrGpuVertex.h"
#include "GrTexture.h"

// recursive helper for creating mask with all the tex coord bits set for
// one stage
template <int N>
static int stage_mask_recur(int stage) {
    return GrDrawTarget::StageTexCoordVertexLayoutBit(stage, N) |
           stage_mask_recur<N+1>(stage);
}
template<> // linux build doesn't like static on specializations
int stage_mask_recur<GrDrawTarget::kNumStages>(int) { return 0; }

// mask of all tex coord indices for one stage
static int stage_tex_coord_mask(int stage) {
    return stage_mask_recur<0>(stage);
}

// mask of all bits relevant to one stage
static int stage_mask(int stage) {
    return stage_tex_coord_mask(stage) |
           GrDrawTarget::StagePosAsTexCoordVertexLayoutBit(stage);
}

// recursive helper for creating mask of with all bits set relevant to one
// texture coordinate index
template <int N>
static int tex_coord_mask_recur(int texCoordIdx) {
    return GrDrawTarget::StageTexCoordVertexLayoutBit(N, texCoordIdx) |
           tex_coord_mask_recur<N+1>(texCoordIdx);
}
template<> // linux build doesn't like static on specializations
int tex_coord_mask_recur<GrDrawTarget::kMaxTexCoords>(int) { return 0; }

// mask of all bits relevant to one texture coordinate index
static int tex_coord_idx_mask(int texCoordIdx) {
    return tex_coord_mask_recur<0>(texCoordIdx);
}

bool check_layout(GrVertexLayout layout) {
    // can only have 1 or 0 bits set for each stage.
    for (int s = 0; s < GrDrawTarget::kNumStages; ++s) {
        int stageBits = layout & stage_mask(s);
        if (stageBits && !GrIsPow2(stageBits)) {
            return false;
        }
    }
    return true;
}

size_t GrDrawTarget::VertexSize(GrVertexLayout vertexLayout) {
    GrAssert(check_layout(vertexLayout));

    size_t vecSize = (vertexLayout & kTextFormat_VertexLayoutBit) ?
                        sizeof(GrGpuTextVertex) :
                        sizeof(GrPoint);

    size_t size = vecSize; // position
    for (int t = 0; t < kMaxTexCoords; ++t) {
        if (tex_coord_idx_mask(t) & vertexLayout) {
            size += vecSize;
        }
    }
    if (vertexLayout & kColor_VertexLayoutBit) {
        size += sizeof(GrColor);
    }
    return size;
}

int GrDrawTarget::VertexStageCoordOffset(int stage, GrVertexLayout vertexLayout) {
    GrAssert(check_layout(vertexLayout));
    if (StagePosAsTexCoordVertexLayoutBit(stage) & vertexLayout) {
        return 0;
    }
    int tcIdx = VertexTexCoordsForStage(stage, vertexLayout);
    if (tcIdx >= 0) {

        int vecSize = (vertexLayout & kTextFormat_VertexLayoutBit) ?
                                    sizeof(GrGpuTextVertex) :
                                    sizeof(GrPoint);
        int offset = vecSize; // position
        // figure out how many tex coordinates are present and precede this one.
        for (int t = 0; t < tcIdx; ++t) {
            if (tex_coord_idx_mask(t) & vertexLayout) {
                offset += vecSize;
            }
        }
        return offset;
    }

    return -1;
}

int  GrDrawTarget::VertexColorOffset(GrVertexLayout vertexLayout) {
    GrAssert(check_layout(vertexLayout));

    if (vertexLayout & kColor_VertexLayoutBit) {
        int vecSize = (vertexLayout & kTextFormat_VertexLayoutBit) ?
                                    sizeof(GrGpuTextVertex) :
                                    sizeof(GrPoint);
        int offset = vecSize; // position
        // figure out how many tex coordinates are present and precede this one.
        for (int t = 0; t < kMaxTexCoords; ++t) {
            if (tex_coord_idx_mask(t) & vertexLayout) {
                offset += vecSize;
            }
        }
        return offset;
    }
    return -1;
}

int GrDrawTarget::VertexSizeAndOffsetsByIdx(GrVertexLayout vertexLayout,
                                             int texCoordOffsetsByIdx[kMaxTexCoords],
                                             int* colorOffset) {
    GrAssert(check_layout(vertexLayout));

    GrAssert(NULL != texCoordOffsetsByIdx);
    GrAssert(NULL != colorOffset);

    int vecSize = (vertexLayout & kTextFormat_VertexLayoutBit) ?
                                                    sizeof(GrGpuTextVertex) :
                                                    sizeof(GrPoint);
    int size = vecSize; // position

    for (int t = 0; t < kMaxTexCoords; ++t) {
        if (tex_coord_idx_mask(t) & vertexLayout) {
            texCoordOffsetsByIdx[t] = size;
            size += vecSize;
        } else {
            texCoordOffsetsByIdx[t] = -1;
        }
    }
    if (kColor_VertexLayoutBit & vertexLayout) {
        *colorOffset = size;
        size += sizeof(GrColor);
    } else {
        *colorOffset = -1;
    }
    return size;
}

int GrDrawTarget::VertexSizeAndOffsetsByStage(GrVertexLayout vertexLayout,
                                              int texCoordOffsetsByStage[kNumStages],
                                              int* colorOffset) {
    GrAssert(check_layout(vertexLayout));

    GrAssert(NULL != texCoordOffsetsByStage);
    GrAssert(NULL != colorOffset);

    int texCoordOffsetsByIdx[kMaxTexCoords];
    int size = VertexSizeAndOffsetsByIdx(vertexLayout,
                                         texCoordOffsetsByIdx,
                                         colorOffset);
    for (int s = 0; s < kNumStages; ++s) {
        int tcIdx;
        if (StagePosAsTexCoordVertexLayoutBit(s) & vertexLayout) {
            texCoordOffsetsByStage[s] = 0;
        } else if ((tcIdx = VertexTexCoordsForStage(s, vertexLayout)) >= 0) {
            texCoordOffsetsByStage[s] = texCoordOffsetsByIdx[tcIdx];
        } else {
            texCoordOffsetsByStage[s] = -1;
        }
    }
    return size;
}

bool GrDrawTarget::VertexUsesStage(int stage, GrVertexLayout vertexLayout) {
    GrAssert(stage < kNumStages);
    GrAssert(check_layout(vertexLayout));
    return !!(stage_mask(stage) & vertexLayout);
}

bool GrDrawTarget::VertexUsesTexCoordIdx(int coordIndex,
                                         GrVertexLayout vertexLayout) {
    GrAssert(coordIndex < kMaxTexCoords);
    GrAssert(check_layout(vertexLayout));
    return !!(tex_coord_idx_mask(coordIndex) & vertexLayout);
}

int GrDrawTarget::VertexTexCoordsForStage(int stage, GrVertexLayout vertexLayout) {
    GrAssert(stage < kNumStages);
    GrAssert(check_layout(vertexLayout));
    int bit = vertexLayout & stage_tex_coord_mask(stage);
    if (bit) {
        // figure out which set of texture coordates is used
        // bits are ordered T0S0, T0S1, T0S2, ..., T1S0, T1S1, ...
        // and start at bit 0.
        GR_STATIC_ASSERT(sizeof(GrVertexLayout) <= sizeof(uint32_t));
        return (32 - Gr_clz(bit) - 1) / kNumStages;
    }
    return -1;
}

void GrDrawTarget::VertexLayoutUnitTest() {
    // not necessarily exhaustive
    static bool run;
    if (!run) {
        run = true;
        for (int s = 0; s < kNumStages; ++s) {

            GrAssert(!VertexUsesStage(s, 0));
            GrAssert(-1 == VertexStageCoordOffset(s, 0));
            GrVertexLayout stageMask = 0;
            for (int t = 0; t < kMaxTexCoords; ++t) {
                stageMask |= StageTexCoordVertexLayoutBit(s,t);
            }
            GrAssert(1 == kMaxTexCoords || !check_layout(stageMask));
            GrAssert(stage_tex_coord_mask(s) == stageMask);
            stageMask |= StagePosAsTexCoordVertexLayoutBit(s);
            GrAssert(stage_mask(s) == stageMask);
            GrAssert(!check_layout(stageMask));
        }
        for (int t = 0; t < kMaxTexCoords; ++t) {
            GrVertexLayout tcMask = 0;
            GrAssert(!VertexUsesTexCoordIdx(t, 0));
            for (int s = 0; s < kNumStages; ++s) {
                tcMask |= StageTexCoordVertexLayoutBit(s,t);
                GrAssert(VertexUsesStage(s, tcMask));
                GrAssert(sizeof(GrPoint) == VertexStageCoordOffset(s, tcMask));
                GrAssert(VertexUsesTexCoordIdx(t, tcMask));
                GrAssert(2*sizeof(GrPoint) == VertexSize(tcMask));
                GrAssert(t == VertexTexCoordsForStage(s, tcMask));
                for (int s2 = s + 1; s2 < kNumStages; ++s2) {
                    GrAssert(-1 == VertexStageCoordOffset(s2, tcMask));
                    GrAssert(!VertexUsesStage(s2, tcMask));
                    GrAssert(-1 == VertexTexCoordsForStage(s2, tcMask));

                #if GR_DEBUG
                    GrVertexLayout posAsTex = tcMask | StagePosAsTexCoordVertexLayoutBit(s2);
                #endif
                    GrAssert(0 == VertexStageCoordOffset(s2, posAsTex));
                    GrAssert(VertexUsesStage(s2, posAsTex));
                    GrAssert(2*sizeof(GrPoint) == VertexSize(posAsTex));
                    GrAssert(-1 == VertexTexCoordsForStage(s2, posAsTex));
                }
            #if GR_DEBUG
                GrVertexLayout withColor = tcMask | kColor_VertexLayoutBit;
            #endif
                GrAssert(2*sizeof(GrPoint) == VertexColorOffset(withColor));
                GrAssert(2*sizeof(GrPoint) + sizeof(GrColor) == VertexSize(withColor));
            }
            GrAssert(tex_coord_idx_mask(t) == tcMask);
            GrAssert(check_layout(tcMask));

            int stageOffsets[kNumStages];
            int colorOffset;
            int size;
            size = VertexSizeAndOffsetsByStage(tcMask, stageOffsets, &colorOffset);
            GrAssert(2*sizeof(GrPoint) == size);
            GrAssert(-1 == colorOffset);
            for (int s = 0; s < kNumStages; ++s) {
                GrAssert(VertexUsesStage(s, tcMask));
                GrAssert(sizeof(GrPoint) == stageOffsets[s]);
                GrAssert(sizeof(GrPoint) == VertexStageCoordOffset(s, tcMask));
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////////////

GrDrawTarget::GrDrawTarget() {
#if GR_DEBUG
    VertexLayoutUnitTest();
#endif
    fReservedGeometry.fLocked = false;
#if GR_DEBUG
    fReservedGeometry.fVertexCount  = ~0;
    fReservedGeometry.fIndexCount   = ~0;
#endif
    fGeometrySrc.fVertexSrc = kReserved_GeometrySrcType;
    fGeometrySrc.fIndexSrc  = kReserved_GeometrySrcType;
}

void GrDrawTarget::setClip(const GrClip& clip) {
    clipWillBeSet(clip);
    fClip = clip;
}

const GrClip& GrDrawTarget::getClip() const {
    return fClip;
}

void GrDrawTarget::setTexture(int stage, GrTexture* tex) {
    GrAssert(stage >= 0 && stage < kNumStages);
    fCurrDrawState.fTextures[stage] = tex;
}

const GrTexture* GrDrawTarget::getTexture(int stage) const {
    GrAssert(stage >= 0 && stage < kNumStages);
    return fCurrDrawState.fTextures[stage];
}

GrTexture* GrDrawTarget::getTexture(int stage) {
    GrAssert(stage >= 0 && stage < kNumStages);
    return fCurrDrawState.fTextures[stage];
}

void GrDrawTarget::setRenderTarget(GrRenderTarget* target) {
    fCurrDrawState.fRenderTarget = target;
}

const GrRenderTarget* GrDrawTarget::getRenderTarget() const {
    return fCurrDrawState.fRenderTarget;
}

GrRenderTarget* GrDrawTarget::getRenderTarget() {
    return fCurrDrawState.fRenderTarget;
}

void GrDrawTarget::setViewMatrix(const GrMatrix& m) {
    fCurrDrawState.fViewMatrix = m;
}

void GrDrawTarget::preConcatViewMatrix(const GrMatrix& matrix) {
    fCurrDrawState.fViewMatrix.preConcat(matrix);
}

const GrMatrix& GrDrawTarget::getViewMatrix() const {
    return fCurrDrawState.fViewMatrix;
}

bool GrDrawTarget::getViewInverse(GrMatrix* matrix) const {
    // Mike:  Can we cache this somewhere?
    // Brian: Sure, do we use it often?

    GrMatrix inverse;
    if (fCurrDrawState.fViewMatrix.invert(&inverse)) {
        if (matrix) {
            *matrix = inverse;
        }
        return true;
    }
    return false;
}

void GrDrawTarget::setSamplerState(int stage, const GrSamplerState& state) {
    GrAssert(stage >= 0 && stage < kNumStages);
    fCurrDrawState.fSamplerStates[stage] = state;
}

void GrDrawTarget::enableState(uint32_t bits) {
    fCurrDrawState.fFlagBits |= bits;
}

void GrDrawTarget::disableState(uint32_t bits) {
    fCurrDrawState.fFlagBits &= ~(bits);
}

void GrDrawTarget::setBlendFunc(GrBlendCoeff srcCoef,
                                GrBlendCoeff dstCoef) {
    fCurrDrawState.fSrcBlend = srcCoef;
    fCurrDrawState.fDstBlend = dstCoef;
}

void GrDrawTarget::setColor(GrColor c) {
    fCurrDrawState.fColor = c;
}

void GrDrawTarget::setAlpha(uint8_t a) {
    this->setColor((a << 24) | (a << 16) | (a << 8) | a);
}

void GrDrawTarget::saveCurrentDrawState(SavedDrawState* state) const {
    state->fState = fCurrDrawState;
}

void GrDrawTarget::restoreDrawState(const SavedDrawState& state) {
    fCurrDrawState = state.fState;
}

void GrDrawTarget::copyDrawState(const GrDrawTarget& srcTarget) {
    fCurrDrawState = srcTarget.fCurrDrawState;
}


bool GrDrawTarget::reserveAndLockGeometry(GrVertexLayout    vertexLayout,
                                          uint32_t          vertexCount,
                                          uint32_t          indexCount,
                                          void**            vertices,
                                          void**            indices) {
    GrAssert(!fReservedGeometry.fLocked);
    fReservedGeometry.fVertexCount  = vertexCount;
    fReservedGeometry.fIndexCount   = indexCount;

    fReservedGeometry.fLocked = acquireGeometryHelper(vertexLayout,
                                                      vertices,
                                                      indices);
    if (fReservedGeometry.fLocked) {
        if (vertexCount) {
            fGeometrySrc.fVertexSrc = kReserved_GeometrySrcType;
            fGeometrySrc.fVertexLayout = vertexLayout;
        }
        if (indexCount) {
            fGeometrySrc.fIndexSrc = kReserved_GeometrySrcType;
        }
    }
    return fReservedGeometry.fLocked;
}

bool GrDrawTarget::geometryHints(GrVertexLayout vertexLayout,
                                 int32_t* vertexCount,
                                 int32_t* indexCount) const {
    GrAssert(!fReservedGeometry.fLocked);
    if (NULL != vertexCount) {
        *vertexCount = -1;
    }
    if (NULL != indexCount) {
        *indexCount = -1;
    }
    return false;
}

void GrDrawTarget::releaseReservedGeometry() {
    GrAssert(fReservedGeometry.fLocked);
    releaseGeometryHelper();
    fReservedGeometry.fLocked = false;
}

void GrDrawTarget::setVertexSourceToArray(GrVertexLayout vertexLayout,
                                          const void* vertexArray,
                                          int vertexCount) {
    fGeometrySrc.fVertexSrc = kArray_GeometrySrcType;
    fGeometrySrc.fVertexLayout = vertexLayout;
    setVertexSourceToArrayHelper(vertexArray, vertexCount);
}

void GrDrawTarget::setIndexSourceToArray(const void* indexArray,
                                         int indexCount) {
    fGeometrySrc.fIndexSrc = kArray_GeometrySrcType;
    setIndexSourceToArrayHelper(indexArray, indexCount);
}

void GrDrawTarget::setVertexSourceToBuffer(GrVertexLayout vertexLayout,
                                           const GrVertexBuffer* buffer) {
    fGeometrySrc.fVertexSrc    = kBuffer_GeometrySrcType;
    fGeometrySrc.fVertexBuffer = buffer;
    fGeometrySrc.fVertexLayout = vertexLayout;
}

void GrDrawTarget::setIndexSourceToBuffer(const GrIndexBuffer* buffer) {
    fGeometrySrc.fIndexSrc     = kBuffer_GeometrySrcType;
    fGeometrySrc.fIndexBuffer  = buffer;
}

///////////////////////////////////////////////////////////////////////////////

bool GrDrawTarget::canDisableBlend() const {
    if ((kOne_BlendCoeff == fCurrDrawState.fSrcBlend) &&
        (kZero_BlendCoeff == fCurrDrawState.fDstBlend)) {
            return true;
    }

    // If we have vertex color without alpha then we can't force blend off
    if ((fGeometrySrc.fVertexLayout & kColor_VertexLayoutBit) ||
         0xff != GrColorUnpackA(fCurrDrawState.fColor)) {
        return false;
    }

    // If the src coef will always be 1...
    if (kSA_BlendCoeff != fCurrDrawState.fSrcBlend &&
        kOne_BlendCoeff != fCurrDrawState.fSrcBlend) {
        return false;
    }

    // ...and the dst coef is always 0...
    if (kISA_BlendCoeff != fCurrDrawState.fDstBlend &&
        kZero_BlendCoeff != fCurrDrawState.fDstBlend) {
        return false;
    }

    // ...and there isn't a texture with an alpha channel...
    for (int s = 0; s < kNumStages; ++s) {
        if (VertexUsesStage(s, fGeometrySrc.fVertexLayout)) {
            GrAssert(NULL != fCurrDrawState.fTextures[s]);
            GrPixelConfig config = fCurrDrawState.fTextures[s]->config();

            if (kRGB_565_GrPixelConfig != config &&
                kRGBX_8888_GrPixelConfig != config) {
                return false;
            }
        }
    }

    // ...then we disable blend.
    return true;
}
///////////////////////////////////////////////////////////////////////////////
void GrDrawTarget::drawRect(const GrRect& rect, 
                            const GrMatrix* matrix,
                            StageBitfield stageEnableBitfield,
                            const GrRect* srcRects[],
                            const GrMatrix* srcMatrices[]) {
    GrVertexLayout layout = GetRectVertexLayout(stageEnableBitfield, srcRects);

    AutoReleaseGeometry geo(this, layout, 4, 0);

    SetRectVertices(rect, matrix, srcRects, 
                    srcMatrices, layout, geo.vertices());

    drawNonIndexed(kTriangleFan_PrimitiveType, 0, 4);
}

GrVertexLayout GrDrawTarget::GetRectVertexLayout(StageBitfield stageEnableBitfield, 
                                                 const GrRect* srcRects[]) {
    GrVertexLayout layout = 0;

    for (int i = 0; i < kNumStages; ++i) {
        int numTC = 0;
        if (stageEnableBitfield & (1 << i)) {
            if (NULL != srcRects && NULL != srcRects[i]) {
                layout |= StageTexCoordVertexLayoutBit(i, numTC);
                ++numTC;
            } else {
                layout |= StagePosAsTexCoordVertexLayoutBit(i);
            }
        }
    }
    return layout;
}
void GrDrawTarget::SetRectVertices(const GrRect& rect,
                                   const GrMatrix* matrix, 
                                   const GrRect* srcRects[], 
                                   const GrMatrix* srcMatrices[],
                                   GrVertexLayout layout, 
                                   void* vertices) {
#if GR_DEBUG
    // check that the layout and srcRects agree
    for (int i = 0; i < kNumStages; ++i) {
        if (VertexTexCoordsForStage(i, layout) >= 0) {
            GR_DEBUGASSERT(NULL != srcRects && NULL != srcRects[i]);
        } else {
            GR_DEBUGASSERT(NULL == srcRects || NULL == srcRects[i]);
        }
    }
#endif

    int stageOffsets[kNumStages];
    int colorOffset;
    int vsize = VertexSizeAndOffsetsByStage(layout, stageOffsets, &colorOffset);
    GrAssert(-1 == colorOffset);

    GrTCast<GrPoint*>(vertices)->setRectFan(rect.fLeft, rect.fTop, 
                                            rect.fRight, rect.fBottom,
                                            vsize);
    if (NULL != matrix) {
        matrix->mapPointsWithStride(GrTCast<GrPoint*>(vertices), vsize, 4);
    }

    for (int i = 0; i < kNumStages; ++i) {
        if (stageOffsets[i] > 0) {
            GrPoint* coords = GrTCast<GrPoint*>(GrTCast<intptr_t>(vertices) + 
                                                stageOffsets[i]);
            coords->setRectFan(srcRects[i]->fLeft, srcRects[i]->fTop,
                               srcRects[i]->fRight, srcRects[i]->fBottom, 
                               vsize);
            if (NULL != srcMatrices && NULL != srcMatrices[i]) {
                srcMatrices[i]->mapPointsWithStride(coords, vsize, 4);
            }
        }
    }
}

///////////////////////////////////////////////////////////////////////////////

GrDrawTarget::AutoStateRestore::AutoStateRestore(GrDrawTarget* target) {
    fDrawTarget = target;
    if (NULL != fDrawTarget) {
        fDrawTarget->saveCurrentDrawState(&fDrawState);
    }
}

GrDrawTarget::AutoStateRestore::~AutoStateRestore() {
    if (NULL != fDrawTarget) {
        fDrawTarget->restoreDrawState(fDrawState);
    }
}

