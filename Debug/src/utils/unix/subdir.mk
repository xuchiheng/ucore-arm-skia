################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/utils/unix/SkOSWindow_Unix.cpp 

C_SRCS += \
../src/utils/unix/keysym2ucs.c 

OBJS += \
./src/utils/unix/SkOSWindow_Unix.o \
./src/utils/unix/keysym2ucs.o 

C_DEPS += \
./src/utils/unix/keysym2ucs.d 

CPP_DEPS += \
./src/utils/unix/SkOSWindow_Unix.d 


# Each subdirectory must supply rules for building sources it contributes
src/utils/unix/%.o: ../src/utils/unix/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/utils/unix/%.o: ../src/utils/unix/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


