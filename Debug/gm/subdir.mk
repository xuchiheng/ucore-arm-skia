################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../gm/bitmapfilters.cpp \
../gm/blurs.cpp \
../gm/complexclip.cpp \
../gm/filltypes.cpp \
../gm/gmmain.cpp \
../gm/gradients.cpp \
../gm/points.cpp \
../gm/poly2poly.cpp \
../gm/shadertext.cpp \
../gm/shadows.cpp \
../gm/shapes.cpp \
../gm/strokerects.cpp \
../gm/tilemodes.cpp \
../gm/xfermodes.cpp 

OBJS += \
./gm/bitmapfilters.o \
./gm/blurs.o \
./gm/complexclip.o \
./gm/filltypes.o \
./gm/gmmain.o \
./gm/gradients.o \
./gm/points.o \
./gm/poly2poly.o \
./gm/shadertext.o \
./gm/shadows.o \
./gm/shapes.o \
./gm/strokerects.o \
./gm/tilemodes.o \
./gm/xfermodes.o 

CPP_DEPS += \
./gm/bitmapfilters.d \
./gm/blurs.d \
./gm/complexclip.d \
./gm/filltypes.d \
./gm/gmmain.d \
./gm/gradients.d \
./gm/points.d \
./gm/poly2poly.d \
./gm/shadertext.d \
./gm/shadows.d \
./gm/shapes.d \
./gm/strokerects.d \
./gm/tilemodes.d \
./gm/xfermodes.d 


# Each subdirectory must supply rules for building sources it contributes
gm/%.o: ../gm/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


