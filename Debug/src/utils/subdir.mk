################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/utils/SkBoundaryPatch.cpp \
../src/utils/SkCamera.cpp \
../src/utils/SkColorMatrix.cpp \
../src/utils/SkCubicInterval.cpp \
../src/utils/SkCullPoints.cpp \
../src/utils/SkDumpCanvas.cpp \
../src/utils/SkEGLContext_none.cpp \
../src/utils/SkInterpolator.cpp \
../src/utils/SkLayer.cpp \
../src/utils/SkMeshUtils.cpp \
../src/utils/SkNWayCanvas.cpp \
../src/utils/SkNinePatch.cpp \
../src/utils/SkOSFile.cpp \
../src/utils/SkParse.cpp \
../src/utils/SkParseColor.cpp \
../src/utils/SkParsePath.cpp \
../src/utils/SkProxyCanvas.cpp \
../src/utils/SkSfntUtils.cpp \
../src/utils/SkUnitMappers.cpp 

OBJS += \
./src/utils/SkBoundaryPatch.o \
./src/utils/SkCamera.o \
./src/utils/SkColorMatrix.o \
./src/utils/SkCubicInterval.o \
./src/utils/SkCullPoints.o \
./src/utils/SkDumpCanvas.o \
./src/utils/SkEGLContext_none.o \
./src/utils/SkInterpolator.o \
./src/utils/SkLayer.o \
./src/utils/SkMeshUtils.o \
./src/utils/SkNWayCanvas.o \
./src/utils/SkNinePatch.o \
./src/utils/SkOSFile.o \
./src/utils/SkParse.o \
./src/utils/SkParseColor.o \
./src/utils/SkParsePath.o \
./src/utils/SkProxyCanvas.o \
./src/utils/SkSfntUtils.o \
./src/utils/SkUnitMappers.o 

CPP_DEPS += \
./src/utils/SkBoundaryPatch.d \
./src/utils/SkCamera.d \
./src/utils/SkColorMatrix.d \
./src/utils/SkCubicInterval.d \
./src/utils/SkCullPoints.d \
./src/utils/SkDumpCanvas.d \
./src/utils/SkEGLContext_none.d \
./src/utils/SkInterpolator.d \
./src/utils/SkLayer.d \
./src/utils/SkMeshUtils.d \
./src/utils/SkNWayCanvas.d \
./src/utils/SkNinePatch.d \
./src/utils/SkOSFile.d \
./src/utils/SkParse.d \
./src/utils/SkParseColor.d \
./src/utils/SkParsePath.d \
./src/utils/SkProxyCanvas.d \
./src/utils/SkSfntUtils.d \
./src/utils/SkUnitMappers.d 


# Each subdirectory must supply rules for building sources it contributes
src/utils/%.o: ../src/utils/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


