################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../gpu/src/win/GrGLDefaultInterface_win.cpp 

OBJS += \
./gpu/src/win/GrGLDefaultInterface_win.o 

CPP_DEPS += \
./gpu/src/win/GrGLDefaultInterface_win.d 


# Each subdirectory must supply rules for building sources it contributes
gpu/src/win/%.o: ../gpu/src/win/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


