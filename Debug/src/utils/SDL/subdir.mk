################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/utils/SDL/SkOSWindow_SDL.cpp 

OBJS += \
./src/utils/SDL/SkOSWindow_SDL.o 

CPP_DEPS += \
./src/utils/SDL/SkOSWindow_SDL.d 


# Each subdirectory must supply rules for building sources it contributes
src/utils/SDL/%.o: ../src/utils/SDL/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


