################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/text/SkTextLayout.cpp 

OBJS += \
./src/text/SkTextLayout.o 

CPP_DEPS += \
./src/text/SkTextLayout.d 


# Each subdirectory must supply rules for building sources it contributes
src/text/%.o: ../src/text/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


