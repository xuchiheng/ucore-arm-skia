################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/effects/Sk1DPathEffect.cpp \
../src/effects/Sk2DPathEffect.cpp \
../src/effects/SkAvoidXfermode.cpp \
../src/effects/SkBitmapCache.cpp \
../src/effects/SkBlurDrawLooper.cpp \
../src/effects/SkBlurMask.cpp \
../src/effects/SkBlurMaskFilter.cpp \
../src/effects/SkColorFilters.cpp \
../src/effects/SkColorMatrixFilter.cpp \
../src/effects/SkCornerPathEffect.cpp \
../src/effects/SkDashPathEffect.cpp \
../src/effects/SkDiscretePathEffect.cpp \
../src/effects/SkEmbossMask.cpp \
../src/effects/SkEmbossMaskFilter.cpp \
../src/effects/SkGradientShader.cpp \
../src/effects/SkGroupShape.cpp \
../src/effects/SkKernel33MaskFilter.cpp \
../src/effects/SkLayerDrawLooper.cpp \
../src/effects/SkLayerRasterizer.cpp \
../src/effects/SkPaintFlagsDrawFilter.cpp \
../src/effects/SkPixelXorXfermode.cpp \
../src/effects/SkPorterDuff.cpp \
../src/effects/SkRectShape.cpp \
../src/effects/SkTableMaskFilter.cpp \
../src/effects/SkTransparentShader.cpp 

OBJS += \
./src/effects/Sk1DPathEffect.o \
./src/effects/Sk2DPathEffect.o \
./src/effects/SkAvoidXfermode.o \
./src/effects/SkBitmapCache.o \
./src/effects/SkBlurDrawLooper.o \
./src/effects/SkBlurMask.o \
./src/effects/SkBlurMaskFilter.o \
./src/effects/SkColorFilters.o \
./src/effects/SkColorMatrixFilter.o \
./src/effects/SkCornerPathEffect.o \
./src/effects/SkDashPathEffect.o \
./src/effects/SkDiscretePathEffect.o \
./src/effects/SkEmbossMask.o \
./src/effects/SkEmbossMaskFilter.o \
./src/effects/SkGradientShader.o \
./src/effects/SkGroupShape.o \
./src/effects/SkKernel33MaskFilter.o \
./src/effects/SkLayerDrawLooper.o \
./src/effects/SkLayerRasterizer.o \
./src/effects/SkPaintFlagsDrawFilter.o \
./src/effects/SkPixelXorXfermode.o \
./src/effects/SkPorterDuff.o \
./src/effects/SkRectShape.o \
./src/effects/SkTableMaskFilter.o \
./src/effects/SkTransparentShader.o 

CPP_DEPS += \
./src/effects/Sk1DPathEffect.d \
./src/effects/Sk2DPathEffect.d \
./src/effects/SkAvoidXfermode.d \
./src/effects/SkBitmapCache.d \
./src/effects/SkBlurDrawLooper.d \
./src/effects/SkBlurMask.d \
./src/effects/SkBlurMaskFilter.d \
./src/effects/SkColorFilters.d \
./src/effects/SkColorMatrixFilter.d \
./src/effects/SkCornerPathEffect.d \
./src/effects/SkDashPathEffect.d \
./src/effects/SkDiscretePathEffect.d \
./src/effects/SkEmbossMask.d \
./src/effects/SkEmbossMaskFilter.d \
./src/effects/SkGradientShader.d \
./src/effects/SkGroupShape.d \
./src/effects/SkKernel33MaskFilter.d \
./src/effects/SkLayerDrawLooper.d \
./src/effects/SkLayerRasterizer.d \
./src/effects/SkPaintFlagsDrawFilter.d \
./src/effects/SkPixelXorXfermode.d \
./src/effects/SkPorterDuff.d \
./src/effects/SkRectShape.d \
./src/effects/SkTableMaskFilter.d \
./src/effects/SkTransparentShader.d 


# Each subdirectory must supply rules for building sources it contributes
src/effects/%.o: ../src/effects/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


