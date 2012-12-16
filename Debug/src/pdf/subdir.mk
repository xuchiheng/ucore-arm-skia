################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/pdf/SkPDFCatalog.cpp \
../src/pdf/SkPDFDevice.cpp \
../src/pdf/SkPDFDocument.cpp \
../src/pdf/SkPDFFont.cpp \
../src/pdf/SkPDFFormXObject.cpp \
../src/pdf/SkPDFGraphicState.cpp \
../src/pdf/SkPDFImage.cpp \
../src/pdf/SkPDFPage.cpp \
../src/pdf/SkPDFShader.cpp \
../src/pdf/SkPDFStream.cpp \
../src/pdf/SkPDFTypes.cpp \
../src/pdf/SkPDFUtils.cpp 

OBJS += \
./src/pdf/SkPDFCatalog.o \
./src/pdf/SkPDFDevice.o \
./src/pdf/SkPDFDocument.o \
./src/pdf/SkPDFFont.o \
./src/pdf/SkPDFFormXObject.o \
./src/pdf/SkPDFGraphicState.o \
./src/pdf/SkPDFImage.o \
./src/pdf/SkPDFPage.o \
./src/pdf/SkPDFShader.o \
./src/pdf/SkPDFStream.o \
./src/pdf/SkPDFTypes.o \
./src/pdf/SkPDFUtils.o 

CPP_DEPS += \
./src/pdf/SkPDFCatalog.d \
./src/pdf/SkPDFDevice.d \
./src/pdf/SkPDFDocument.d \
./src/pdf/SkPDFFont.d \
./src/pdf/SkPDFFormXObject.d \
./src/pdf/SkPDFGraphicState.d \
./src/pdf/SkPDFImage.d \
./src/pdf/SkPDFPage.d \
./src/pdf/SkPDFShader.d \
./src/pdf/SkPDFStream.d \
./src/pdf/SkPDFTypes.d \
./src/pdf/SkPDFUtils.d 


# Each subdirectory must supply rules for building sources it contributes
src/pdf/%.o: ../src/pdf/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


