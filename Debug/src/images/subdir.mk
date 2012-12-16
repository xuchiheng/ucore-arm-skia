################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/images/SkCreateRLEPixelRef.cpp \
../src/images/SkFDStream.cpp \
../src/images/SkFlipPixelRef.cpp \
../src/images/SkImageDecoder.cpp \
../src/images/SkImageDecoder_Factory.cpp \
../src/images/SkImageDecoder_libbmp.cpp \
../src/images/SkImageDecoder_libgif.cpp \
../src/images/SkImageDecoder_libico.cpp \
../src/images/SkImageDecoder_libjpeg.cpp \
../src/images/SkImageDecoder_libpng.cpp \
../src/images/SkImageDecoder_libpvjpeg.cpp \
../src/images/SkImageDecoder_wbmp.cpp \
../src/images/SkImageEncoder.cpp \
../src/images/SkImageEncoder_Factory.cpp \
../src/images/SkImageRef.cpp \
../src/images/SkImageRefPool.cpp \
../src/images/SkImageRef_GlobalPool.cpp \
../src/images/SkJpegUtility.cpp \
../src/images/SkMovie.cpp \
../src/images/SkMovie_gif.cpp \
../src/images/SkPageFlipper.cpp \
../src/images/SkScaledBitmapSampler.cpp \
../src/images/bmpdecoderhelper.cpp 

OBJS += \
./src/images/SkCreateRLEPixelRef.o \
./src/images/SkFDStream.o \
./src/images/SkFlipPixelRef.o \
./src/images/SkImageDecoder.o \
./src/images/SkImageDecoder_Factory.o \
./src/images/SkImageDecoder_libbmp.o \
./src/images/SkImageDecoder_libgif.o \
./src/images/SkImageDecoder_libico.o \
./src/images/SkImageDecoder_libjpeg.o \
./src/images/SkImageDecoder_libpng.o \
./src/images/SkImageDecoder_libpvjpeg.o \
./src/images/SkImageDecoder_wbmp.o \
./src/images/SkImageEncoder.o \
./src/images/SkImageEncoder_Factory.o \
./src/images/SkImageRef.o \
./src/images/SkImageRefPool.o \
./src/images/SkImageRef_GlobalPool.o \
./src/images/SkJpegUtility.o \
./src/images/SkMovie.o \
./src/images/SkMovie_gif.o \
./src/images/SkPageFlipper.o \
./src/images/SkScaledBitmapSampler.o \
./src/images/bmpdecoderhelper.o 

CPP_DEPS += \
./src/images/SkCreateRLEPixelRef.d \
./src/images/SkFDStream.d \
./src/images/SkFlipPixelRef.d \
./src/images/SkImageDecoder.d \
./src/images/SkImageDecoder_Factory.d \
./src/images/SkImageDecoder_libbmp.d \
./src/images/SkImageDecoder_libgif.d \
./src/images/SkImageDecoder_libico.d \
./src/images/SkImageDecoder_libjpeg.d \
./src/images/SkImageDecoder_libpng.d \
./src/images/SkImageDecoder_libpvjpeg.d \
./src/images/SkImageDecoder_wbmp.d \
./src/images/SkImageEncoder.d \
./src/images/SkImageEncoder_Factory.d \
./src/images/SkImageRef.d \
./src/images/SkImageRefPool.d \
./src/images/SkImageRef_GlobalPool.d \
./src/images/SkJpegUtility.d \
./src/images/SkMovie.d \
./src/images/SkMovie_gif.d \
./src/images/SkPageFlipper.d \
./src/images/SkScaledBitmapSampler.d \
./src/images/bmpdecoderhelper.d 


# Each subdirectory must supply rules for building sources it contributes
src/images/%.o: ../src/images/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


