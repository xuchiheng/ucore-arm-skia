################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../vs/SampleApp/SampleApp.cpp \
../vs/SampleApp/stdafx.cpp 

OBJS += \
./vs/SampleApp/SampleApp.o \
./vs/SampleApp/stdafx.o 

CPP_DEPS += \
./vs/SampleApp/SampleApp.d \
./vs/SampleApp/stdafx.d 


# Each subdirectory must supply rules for building sources it contributes
vs/SampleApp/%.o: ../vs/SampleApp/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


