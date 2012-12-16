################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../third_party/harfbuzz/tests/shaping/main.cpp 

OBJS += \
./third_party/harfbuzz/tests/shaping/main.o 

CPP_DEPS += \
./third_party/harfbuzz/tests/shaping/main.d 


# Each subdirectory must supply rules for building sources it contributes
third_party/harfbuzz/tests/shaping/%.o: ../third_party/harfbuzz/tests/shaping/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


