################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../tools/skhello.cpp \
../tools/skimage_main.cpp 

OBJS += \
./tools/skhello.o \
./tools/skimage_main.o 

CPP_DEPS += \
./tools/skhello.d \
./tools/skimage_main.d 


# Each subdirectory must supply rules for building sources it contributes
tools/%.o: ../tools/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


