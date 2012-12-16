################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../forth/Forth.cpp \
../forth/ForthTests.cpp \
../forth/SampleForth.cpp \
../forth/StdWords.cpp 

OBJS += \
./forth/Forth.o \
./forth/ForthTests.o \
./forth/SampleForth.o \
./forth/StdWords.o 

CPP_DEPS += \
./forth/Forth.d \
./forth/ForthTests.d \
./forth/SampleForth.d \
./forth/StdWords.d 


# Each subdirectory must supply rules for building sources it contributes
forth/%.o: ../forth/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


