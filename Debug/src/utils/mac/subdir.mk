################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/utils/mac/SkBitmap_Mac.cpp \
../src/utils/mac/SkCreateCGImageRef.cpp \
../src/utils/mac/SkEGLContext_mac.cpp \
../src/utils/mac/SkOSWindow_Mac.cpp \
../src/utils/mac/skia_mac.cpp 

OBJS += \
./src/utils/mac/SkBitmap_Mac.o \
./src/utils/mac/SkCreateCGImageRef.o \
./src/utils/mac/SkEGLContext_mac.o \
./src/utils/mac/SkOSWindow_Mac.o \
./src/utils/mac/skia_mac.o 

CPP_DEPS += \
./src/utils/mac/SkBitmap_Mac.d \
./src/utils/mac/SkCreateCGImageRef.d \
./src/utils/mac/SkEGLContext_mac.d \
./src/utils/mac/SkOSWindow_Mac.d \
./src/utils/mac/skia_mac.d 


# Each subdirectory must supply rules for building sources it contributes
src/utils/mac/%.o: ../src/utils/mac/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


