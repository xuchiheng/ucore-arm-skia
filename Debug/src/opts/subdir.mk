################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/opts/SkBitmapProcState_opts_SSE2.cpp \
../src/opts/SkBitmapProcState_opts_arm.cpp \
../src/opts/SkBitmapProcState_opts_none.cpp \
../src/opts/SkBlitRow_opts_SSE2.cpp \
../src/opts/SkBlitRow_opts_arm.cpp \
../src/opts/SkBlitRow_opts_none.cpp \
../src/opts/SkUtils_opts_SSE2.cpp \
../src/opts/SkUtils_opts_none.cpp \
../src/opts/opts_check_SSE2.cpp \
../src/opts/opts_check_arm.cpp \
../src/opts/opts_check_arm_neon.cpp 

S_UPPER_SRCS += \
../src/opts/memset.arm.S \
../src/opts/memset16_neon.S \
../src/opts/memset32_neon.S 

OBJS += \
./src/opts/SkBitmapProcState_opts_SSE2.o \
./src/opts/SkBitmapProcState_opts_arm.o \
./src/opts/SkBitmapProcState_opts_none.o \
./src/opts/SkBlitRow_opts_SSE2.o \
./src/opts/SkBlitRow_opts_arm.o \
./src/opts/SkBlitRow_opts_none.o \
./src/opts/SkUtils_opts_SSE2.o \
./src/opts/SkUtils_opts_none.o \
./src/opts/memset.arm.o \
./src/opts/memset16_neon.o \
./src/opts/memset32_neon.o \
./src/opts/opts_check_SSE2.o \
./src/opts/opts_check_arm.o \
./src/opts/opts_check_arm_neon.o 

CPP_DEPS += \
./src/opts/SkBitmapProcState_opts_SSE2.d \
./src/opts/SkBitmapProcState_opts_arm.d \
./src/opts/SkBitmapProcState_opts_none.d \
./src/opts/SkBlitRow_opts_SSE2.d \
./src/opts/SkBlitRow_opts_arm.d \
./src/opts/SkBlitRow_opts_none.d \
./src/opts/SkUtils_opts_SSE2.d \
./src/opts/SkUtils_opts_none.d \
./src/opts/opts_check_SSE2.d \
./src/opts/opts_check_arm.d \
./src/opts/opts_check_arm_neon.d 


# Each subdirectory must supply rules for building sources it contributes
src/opts/%.o: ../src/opts/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/opts/%.o: ../src/opts/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Assembler'
	as  -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


