################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../unix_test_app/DrawBlueSample.cpp \
../unix_test_app/main.cpp 

OBJS += \
./unix_test_app/DrawBlueSample.o \
./unix_test_app/main.o 

CPP_DEPS += \
./unix_test_app/DrawBlueSample.d \
./unix_test_app/main.d 


# Each subdirectory must supply rules for building sources it contributes
unix_test_app/%.o: ../unix_test_app/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


