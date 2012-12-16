################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../third_party/glu/libtess/dict.c \
../third_party/glu/libtess/geom.c \
../third_party/glu/libtess/memalloc.c \
../third_party/glu/libtess/mesh.c \
../third_party/glu/libtess/normal.c \
../third_party/glu/libtess/priorityq-heap.c \
../third_party/glu/libtess/priorityq.c \
../third_party/glu/libtess/render.c \
../third_party/glu/libtess/sweep.c \
../third_party/glu/libtess/tess.c \
../third_party/glu/libtess/tessmono.c 

OBJS += \
./third_party/glu/libtess/dict.o \
./third_party/glu/libtess/geom.o \
./third_party/glu/libtess/memalloc.o \
./third_party/glu/libtess/mesh.o \
./third_party/glu/libtess/normal.o \
./third_party/glu/libtess/priorityq-heap.o \
./third_party/glu/libtess/priorityq.o \
./third_party/glu/libtess/render.o \
./third_party/glu/libtess/sweep.o \
./third_party/glu/libtess/tess.o \
./third_party/glu/libtess/tessmono.o 

C_DEPS += \
./third_party/glu/libtess/dict.d \
./third_party/glu/libtess/geom.d \
./third_party/glu/libtess/memalloc.d \
./third_party/glu/libtess/mesh.d \
./third_party/glu/libtess/normal.d \
./third_party/glu/libtess/priorityq-heap.d \
./third_party/glu/libtess/priorityq.d \
./third_party/glu/libtess/render.d \
./third_party/glu/libtess/sweep.d \
./third_party/glu/libtess/tess.d \
./third_party/glu/libtess/tessmono.d 


# Each subdirectory must supply rules for building sources it contributes
third_party/glu/libtess/%.o: ../third_party/glu/libtess/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


