################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../gpu/src/mac/GrGLDefaultInterface_mac.cpp 

OBJS += \
./gpu/src/mac/GrGLDefaultInterface_mac.o 

CPP_DEPS += \
./gpu/src/mac/GrGLDefaultInterface_mac.d 


# Each subdirectory must supply rules for building sources it contributes
gpu/src/mac/%.o: ../gpu/src/mac/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


