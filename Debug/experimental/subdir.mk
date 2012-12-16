################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../experimental/SkMatrix44.cpp \
../experimental/SkSetPoly3To3.cpp \
../experimental/SkSetPoly3To3_A.cpp \
../experimental/SkSetPoly3To3_D.cpp 

C_SRCS += \
../experimental/CiCarbonSampleMain.c 

OBJS += \
./experimental/CiCarbonSampleMain.o \
./experimental/SkMatrix44.o \
./experimental/SkSetPoly3To3.o \
./experimental/SkSetPoly3To3_A.o \
./experimental/SkSetPoly3To3_D.o 

C_DEPS += \
./experimental/CiCarbonSampleMain.d 

CPP_DEPS += \
./experimental/SkMatrix44.d \
./experimental/SkSetPoly3To3.d \
./experimental/SkSetPoly3To3_A.d \
./experimental/SkSetPoly3To3_D.d 


# Each subdirectory must supply rules for building sources it contributes
experimental/%.o: ../experimental/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

experimental/%.o: ../experimental/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


