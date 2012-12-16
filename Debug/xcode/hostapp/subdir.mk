################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../xcode/hostapp/test.cpp 

C_SRCS += \
../xcode/hostapp/main.c 

OBJS += \
./xcode/hostapp/main.o \
./xcode/hostapp/test.o 

C_DEPS += \
./xcode/hostapp/main.d 

CPP_DEPS += \
./xcode/hostapp/test.d 


# Each subdirectory must supply rules for building sources it contributes
xcode/hostapp/%.o: ../xcode/hostapp/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

xcode/hostapp/%.o: ../xcode/hostapp/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


