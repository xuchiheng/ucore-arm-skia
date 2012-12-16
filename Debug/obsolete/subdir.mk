################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../obsolete/SkGL.cpp \
../obsolete/SkGLCanvas.cpp \
../obsolete/SkGLDevice.cpp \
../obsolete/SkGLDevice_FBO.cpp \
../obsolete/SkGLDevice_SWLayer.cpp \
../obsolete/SkGLState.cpp \
../obsolete/SkGLTextCache.cpp \
../obsolete/SkTextureCache.cpp 

OBJS += \
./obsolete/SkGL.o \
./obsolete/SkGLCanvas.o \
./obsolete/SkGLDevice.o \
./obsolete/SkGLDevice_FBO.o \
./obsolete/SkGLDevice_SWLayer.o \
./obsolete/SkGLState.o \
./obsolete/SkGLTextCache.o \
./obsolete/SkTextureCache.o 

CPP_DEPS += \
./obsolete/SkGL.d \
./obsolete/SkGLCanvas.d \
./obsolete/SkGLDevice.d \
./obsolete/SkGLDevice_FBO.d \
./obsolete/SkGLDevice_SWLayer.d \
./obsolete/SkGLState.d \
./obsolete/SkGLTextCache.d \
./obsolete/SkTextureCache.d 


# Each subdirectory must supply rules for building sources it contributes
obsolete/%.o: ../obsolete/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


