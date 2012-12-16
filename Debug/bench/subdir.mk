################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../bench/BitmapBench.cpp \
../bench/DecodeBench.cpp \
../bench/FPSBench.cpp \
../bench/RectBench.cpp \
../bench/RepeatTileBench.cpp \
../bench/SkBenchmark.cpp \
../bench/TextBench.cpp \
../bench/benchmain.cpp 

OBJS += \
./bench/BitmapBench.o \
./bench/DecodeBench.o \
./bench/FPSBench.o \
./bench/RectBench.o \
./bench/RepeatTileBench.o \
./bench/SkBenchmark.o \
./bench/TextBench.o \
./bench/benchmain.o 

CPP_DEPS += \
./bench/BitmapBench.d \
./bench/DecodeBench.d \
./bench/FPSBench.d \
./bench/RectBench.d \
./bench/RepeatTileBench.d \
./bench/SkBenchmark.d \
./bench/TextBench.d \
./bench/benchmain.d 


# Each subdirectory must supply rules for building sources it contributes
bench/%.o: ../bench/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


