################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/utils/win/SkOSWindow_Win.cpp \
../src/utils/win/skia_win.cpp 

OBJS += \
./src/utils/win/SkOSWindow_Win.o \
./src/utils/win/skia_win.o 

CPP_DEPS += \
./src/utils/win/SkOSWindow_Win.d \
./src/utils/win/skia_win.d 


# Each subdirectory must supply rules for building sources it contributes
src/utils/win/%.o: ../src/utils/win/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


