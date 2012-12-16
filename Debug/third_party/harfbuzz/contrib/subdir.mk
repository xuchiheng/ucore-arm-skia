################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../third_party/harfbuzz/contrib/harfbuzz-freetype.c \
../third_party/harfbuzz/contrib/harfbuzz-unicode-glib.c \
../third_party/harfbuzz/contrib/harfbuzz-unicode-tables.c \
../third_party/harfbuzz/contrib/harfbuzz-unicode.c 

OBJS += \
./third_party/harfbuzz/contrib/harfbuzz-freetype.o \
./third_party/harfbuzz/contrib/harfbuzz-unicode-glib.o \
./third_party/harfbuzz/contrib/harfbuzz-unicode-tables.o \
./third_party/harfbuzz/contrib/harfbuzz-unicode.o 

C_DEPS += \
./third_party/harfbuzz/contrib/harfbuzz-freetype.d \
./third_party/harfbuzz/contrib/harfbuzz-unicode-glib.d \
./third_party/harfbuzz/contrib/harfbuzz-unicode-tables.d \
./third_party/harfbuzz/contrib/harfbuzz-unicode.d 


# Each subdirectory must supply rules for building sources it contributes
third_party/harfbuzz/contrib/%.o: ../third_party/harfbuzz/contrib/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


