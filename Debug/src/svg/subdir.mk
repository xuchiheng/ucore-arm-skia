################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/svg/SkSVG.cpp \
../src/svg/SkSVGCircle.cpp \
../src/svg/SkSVGClipPath.cpp \
../src/svg/SkSVGDefs.cpp \
../src/svg/SkSVGElements.cpp \
../src/svg/SkSVGEllipse.cpp \
../src/svg/SkSVGFeColorMatrix.cpp \
../src/svg/SkSVGFilter.cpp \
../src/svg/SkSVGG.cpp \
../src/svg/SkSVGGradient.cpp \
../src/svg/SkSVGGroup.cpp \
../src/svg/SkSVGImage.cpp \
../src/svg/SkSVGLine.cpp \
../src/svg/SkSVGLinearGradient.cpp \
../src/svg/SkSVGMask.cpp \
../src/svg/SkSVGMetadata.cpp \
../src/svg/SkSVGPaintState.cpp \
../src/svg/SkSVGParser.cpp \
../src/svg/SkSVGPath.cpp \
../src/svg/SkSVGPolygon.cpp \
../src/svg/SkSVGPolyline.cpp \
../src/svg/SkSVGRadialGradient.cpp \
../src/svg/SkSVGRect.cpp \
../src/svg/SkSVGSVG.cpp \
../src/svg/SkSVGStop.cpp \
../src/svg/SkSVGSymbol.cpp \
../src/svg/SkSVGText.cpp \
../src/svg/SkSVGUse.cpp 

OBJS += \
./src/svg/SkSVG.o \
./src/svg/SkSVGCircle.o \
./src/svg/SkSVGClipPath.o \
./src/svg/SkSVGDefs.o \
./src/svg/SkSVGElements.o \
./src/svg/SkSVGEllipse.o \
./src/svg/SkSVGFeColorMatrix.o \
./src/svg/SkSVGFilter.o \
./src/svg/SkSVGG.o \
./src/svg/SkSVGGradient.o \
./src/svg/SkSVGGroup.o \
./src/svg/SkSVGImage.o \
./src/svg/SkSVGLine.o \
./src/svg/SkSVGLinearGradient.o \
./src/svg/SkSVGMask.o \
./src/svg/SkSVGMetadata.o \
./src/svg/SkSVGPaintState.o \
./src/svg/SkSVGParser.o \
./src/svg/SkSVGPath.o \
./src/svg/SkSVGPolygon.o \
./src/svg/SkSVGPolyline.o \
./src/svg/SkSVGRadialGradient.o \
./src/svg/SkSVGRect.o \
./src/svg/SkSVGSVG.o \
./src/svg/SkSVGStop.o \
./src/svg/SkSVGSymbol.o \
./src/svg/SkSVGText.o \
./src/svg/SkSVGUse.o 

CPP_DEPS += \
./src/svg/SkSVG.d \
./src/svg/SkSVGCircle.d \
./src/svg/SkSVGClipPath.d \
./src/svg/SkSVGDefs.d \
./src/svg/SkSVGElements.d \
./src/svg/SkSVGEllipse.d \
./src/svg/SkSVGFeColorMatrix.d \
./src/svg/SkSVGFilter.d \
./src/svg/SkSVGG.d \
./src/svg/SkSVGGradient.d \
./src/svg/SkSVGGroup.d \
./src/svg/SkSVGImage.d \
./src/svg/SkSVGLine.d \
./src/svg/SkSVGLinearGradient.d \
./src/svg/SkSVGMask.d \
./src/svg/SkSVGMetadata.d \
./src/svg/SkSVGPaintState.d \
./src/svg/SkSVGParser.d \
./src/svg/SkSVGPath.d \
./src/svg/SkSVGPolygon.d \
./src/svg/SkSVGPolyline.d \
./src/svg/SkSVGRadialGradient.d \
./src/svg/SkSVGRect.d \
./src/svg/SkSVGSVG.d \
./src/svg/SkSVGStop.d \
./src/svg/SkSVGSymbol.d \
./src/svg/SkSVGText.d \
./src/svg/SkSVGUse.d 


# Each subdirectory must supply rules for building sources it contributes
src/svg/%.o: ../src/svg/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


