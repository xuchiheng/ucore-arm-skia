################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../third_party/harfbuzz/src/harfbuzz-indic.cpp \
../third_party/harfbuzz/src/harfbuzz-shaper-all.cpp \
../third_party/harfbuzz/src/harfbuzz-shaper.cpp 

C_SRCS += \
../third_party/harfbuzz/src/harfbuzz-arabic.c \
../third_party/harfbuzz/src/harfbuzz-buffer.c \
../third_party/harfbuzz/src/harfbuzz-dump-main.c \
../third_party/harfbuzz/src/harfbuzz-dump.c \
../third_party/harfbuzz/src/harfbuzz-gdef.c \
../third_party/harfbuzz/src/harfbuzz-gpos.c \
../third_party/harfbuzz/src/harfbuzz-gsub.c \
../third_party/harfbuzz/src/harfbuzz-hangul.c \
../third_party/harfbuzz/src/harfbuzz-hebrew.c \
../third_party/harfbuzz/src/harfbuzz-impl.c \
../third_party/harfbuzz/src/harfbuzz-khmer.c \
../third_party/harfbuzz/src/harfbuzz-myanmar.c \
../third_party/harfbuzz/src/harfbuzz-open.c \
../third_party/harfbuzz/src/harfbuzz-stream.c \
../third_party/harfbuzz/src/harfbuzz-thai.c \
../third_party/harfbuzz/src/harfbuzz-tibetan.c \
../third_party/harfbuzz/src/harfbuzz.c 

OBJS += \
./third_party/harfbuzz/src/harfbuzz-arabic.o \
./third_party/harfbuzz/src/harfbuzz-buffer.o \
./third_party/harfbuzz/src/harfbuzz-dump-main.o \
./third_party/harfbuzz/src/harfbuzz-dump.o \
./third_party/harfbuzz/src/harfbuzz-gdef.o \
./third_party/harfbuzz/src/harfbuzz-gpos.o \
./third_party/harfbuzz/src/harfbuzz-gsub.o \
./third_party/harfbuzz/src/harfbuzz-hangul.o \
./third_party/harfbuzz/src/harfbuzz-hebrew.o \
./third_party/harfbuzz/src/harfbuzz-impl.o \
./third_party/harfbuzz/src/harfbuzz-indic.o \
./third_party/harfbuzz/src/harfbuzz-khmer.o \
./third_party/harfbuzz/src/harfbuzz-myanmar.o \
./third_party/harfbuzz/src/harfbuzz-open.o \
./third_party/harfbuzz/src/harfbuzz-shaper-all.o \
./third_party/harfbuzz/src/harfbuzz-shaper.o \
./third_party/harfbuzz/src/harfbuzz-stream.o \
./third_party/harfbuzz/src/harfbuzz-thai.o \
./third_party/harfbuzz/src/harfbuzz-tibetan.o \
./third_party/harfbuzz/src/harfbuzz.o 

C_DEPS += \
./third_party/harfbuzz/src/harfbuzz-arabic.d \
./third_party/harfbuzz/src/harfbuzz-buffer.d \
./third_party/harfbuzz/src/harfbuzz-dump-main.d \
./third_party/harfbuzz/src/harfbuzz-dump.d \
./third_party/harfbuzz/src/harfbuzz-gdef.d \
./third_party/harfbuzz/src/harfbuzz-gpos.d \
./third_party/harfbuzz/src/harfbuzz-gsub.d \
./third_party/harfbuzz/src/harfbuzz-hangul.d \
./third_party/harfbuzz/src/harfbuzz-hebrew.d \
./third_party/harfbuzz/src/harfbuzz-impl.d \
./third_party/harfbuzz/src/harfbuzz-khmer.d \
./third_party/harfbuzz/src/harfbuzz-myanmar.d \
./third_party/harfbuzz/src/harfbuzz-open.d \
./third_party/harfbuzz/src/harfbuzz-stream.d \
./third_party/harfbuzz/src/harfbuzz-thai.d \
./third_party/harfbuzz/src/harfbuzz-tibetan.d \
./third_party/harfbuzz/src/harfbuzz.d 

CPP_DEPS += \
./third_party/harfbuzz/src/harfbuzz-indic.d \
./third_party/harfbuzz/src/harfbuzz-shaper-all.d \
./third_party/harfbuzz/src/harfbuzz-shaper.d 


# Each subdirectory must supply rules for building sources it contributes
third_party/harfbuzz/src/%.o: ../third_party/harfbuzz/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

third_party/harfbuzz/src/%.o: ../third_party/harfbuzz/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


