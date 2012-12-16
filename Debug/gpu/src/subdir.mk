################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../gpu/src/FlingState.cpp \
../gpu/src/GrAllocPool.cpp \
../gpu/src/GrAtlas.cpp \
../gpu/src/GrBufferAllocPool.cpp \
../gpu/src/GrClip.cpp \
../gpu/src/GrContext.cpp \
../gpu/src/GrCreatePathRenderer_none.cpp \
../gpu/src/GrCreatePathRenderer_tesselated.cpp \
../gpu/src/GrDrawMesh.cpp \
../gpu/src/GrDrawTarget.cpp \
../gpu/src/GrGLDefaultInterface_none.cpp \
../gpu/src/GrGLIndexBuffer.cpp \
../gpu/src/GrGLInterface.cpp \
../gpu/src/GrGLProgram.cpp \
../gpu/src/GrGLTexture.cpp \
../gpu/src/GrGLUtil.cpp \
../gpu/src/GrGLVertexBuffer.cpp \
../gpu/src/GrGpu.cpp \
../gpu/src/GrGpuFactory.cpp \
../gpu/src/GrGpuGL.cpp \
../gpu/src/GrGpuGLFixed.cpp \
../gpu/src/GrGpuGLShaders.cpp \
../gpu/src/GrGpuGLShaders2.cpp \
../gpu/src/GrInOrderDrawBuffer.cpp \
../gpu/src/GrMatrix.cpp \
../gpu/src/GrMemory.cpp \
../gpu/src/GrPath.cpp \
../gpu/src/GrPathRenderer.cpp \
../gpu/src/GrPathUtils.cpp \
../gpu/src/GrPrintf_printf.cpp \
../gpu/src/GrRectanizer.cpp \
../gpu/src/GrRectanizer_fifo.cpp \
../gpu/src/GrResource.cpp \
../gpu/src/GrStencil.cpp \
../gpu/src/GrTesselatedPathRenderer.cpp \
../gpu/src/GrTextContext.cpp \
../gpu/src/GrTextStrike.cpp \
../gpu/src/GrTexture.cpp \
../gpu/src/GrTextureCache.cpp \
../gpu/src/GrTouchGesture.cpp \
../gpu/src/app-android.cpp \
../gpu/src/gr_hello_world.cpp \
../gpu/src/gr_unittests.cpp 

OBJS += \
./gpu/src/FlingState.o \
./gpu/src/GrAllocPool.o \
./gpu/src/GrAtlas.o \
./gpu/src/GrBufferAllocPool.o \
./gpu/src/GrClip.o \
./gpu/src/GrContext.o \
./gpu/src/GrCreatePathRenderer_none.o \
./gpu/src/GrCreatePathRenderer_tesselated.o \
./gpu/src/GrDrawMesh.o \
./gpu/src/GrDrawTarget.o \
./gpu/src/GrGLDefaultInterface_none.o \
./gpu/src/GrGLIndexBuffer.o \
./gpu/src/GrGLInterface.o \
./gpu/src/GrGLProgram.o \
./gpu/src/GrGLTexture.o \
./gpu/src/GrGLUtil.o \
./gpu/src/GrGLVertexBuffer.o \
./gpu/src/GrGpu.o \
./gpu/src/GrGpuFactory.o \
./gpu/src/GrGpuGL.o \
./gpu/src/GrGpuGLFixed.o \
./gpu/src/GrGpuGLShaders.o \
./gpu/src/GrGpuGLShaders2.o \
./gpu/src/GrInOrderDrawBuffer.o \
./gpu/src/GrMatrix.o \
./gpu/src/GrMemory.o \
./gpu/src/GrPath.o \
./gpu/src/GrPathRenderer.o \
./gpu/src/GrPathUtils.o \
./gpu/src/GrPrintf_printf.o \
./gpu/src/GrRectanizer.o \
./gpu/src/GrRectanizer_fifo.o \
./gpu/src/GrResource.o \
./gpu/src/GrStencil.o \
./gpu/src/GrTesselatedPathRenderer.o \
./gpu/src/GrTextContext.o \
./gpu/src/GrTextStrike.o \
./gpu/src/GrTexture.o \
./gpu/src/GrTextureCache.o \
./gpu/src/GrTouchGesture.o \
./gpu/src/app-android.o \
./gpu/src/gr_hello_world.o \
./gpu/src/gr_unittests.o 

CPP_DEPS += \
./gpu/src/FlingState.d \
./gpu/src/GrAllocPool.d \
./gpu/src/GrAtlas.d \
./gpu/src/GrBufferAllocPool.d \
./gpu/src/GrClip.d \
./gpu/src/GrContext.d \
./gpu/src/GrCreatePathRenderer_none.d \
./gpu/src/GrCreatePathRenderer_tesselated.d \
./gpu/src/GrDrawMesh.d \
./gpu/src/GrDrawTarget.d \
./gpu/src/GrGLDefaultInterface_none.d \
./gpu/src/GrGLIndexBuffer.d \
./gpu/src/GrGLInterface.d \
./gpu/src/GrGLProgram.d \
./gpu/src/GrGLTexture.d \
./gpu/src/GrGLUtil.d \
./gpu/src/GrGLVertexBuffer.d \
./gpu/src/GrGpu.d \
./gpu/src/GrGpuFactory.d \
./gpu/src/GrGpuGL.d \
./gpu/src/GrGpuGLFixed.d \
./gpu/src/GrGpuGLShaders.d \
./gpu/src/GrGpuGLShaders2.d \
./gpu/src/GrInOrderDrawBuffer.d \
./gpu/src/GrMatrix.d \
./gpu/src/GrMemory.d \
./gpu/src/GrPath.d \
./gpu/src/GrPathRenderer.d \
./gpu/src/GrPathUtils.d \
./gpu/src/GrPrintf_printf.d \
./gpu/src/GrRectanizer.d \
./gpu/src/GrRectanizer_fifo.d \
./gpu/src/GrResource.d \
./gpu/src/GrStencil.d \
./gpu/src/GrTesselatedPathRenderer.d \
./gpu/src/GrTextContext.d \
./gpu/src/GrTextStrike.d \
./gpu/src/GrTexture.d \
./gpu/src/GrTextureCache.d \
./gpu/src/GrTouchGesture.d \
./gpu/src/app-android.d \
./gpu/src/gr_hello_world.d \
./gpu/src/gr_unittests.d 


# Each subdirectory must supply rules for building sources it contributes
gpu/src/%.o: ../gpu/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


