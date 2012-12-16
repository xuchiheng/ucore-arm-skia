################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/gpu/GrPrintf_skia.cpp \
../src/gpu/SkGpuCanvas.cpp \
../src/gpu/SkGpuDevice.cpp \
../src/gpu/SkGr.cpp \
../src/gpu/SkGrFontScaler.cpp \
../src/gpu/SkGrTexturePixelRef.cpp 

OBJS += \
./src/gpu/GrPrintf_skia.o \
./src/gpu/SkGpuCanvas.o \
./src/gpu/SkGpuDevice.o \
./src/gpu/SkGr.o \
./src/gpu/SkGrFontScaler.o \
./src/gpu/SkGrTexturePixelRef.o 

CPP_DEPS += \
./src/gpu/GrPrintf_skia.d \
./src/gpu/SkGpuCanvas.d \
./src/gpu/SkGpuDevice.d \
./src/gpu/SkGr.d \
./src/gpu/SkGrFontScaler.d \
./src/gpu/SkGrTexturePixelRef.d 


# Each subdirectory must supply rules for building sources it contributes
src/gpu/%.o: ../src/gpu/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


