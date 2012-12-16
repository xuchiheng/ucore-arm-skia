################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../xcode/sampleapp_sdl/skia_sdl_main.cpp 

OBJS += \
./xcode/sampleapp_sdl/skia_sdl_main.o 

CPP_DEPS += \
./xcode/sampleapp_sdl/skia_sdl_main.d 


# Each subdirectory must supply rules for building sources it contributes
xcode/sampleapp_sdl/%.o: ../xcode/sampleapp_sdl/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


