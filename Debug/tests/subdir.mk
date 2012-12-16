################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../tests/BitmapCopyTest.cpp \
../tests/BitmapGetColorTest.cpp \
../tests/BlitRowTest.cpp \
../tests/ClipCubicTest.cpp \
../tests/ClipStackTest.cpp \
../tests/ClipperTest.cpp \
../tests/DequeTest.cpp \
../tests/DrawBitmapRectTest.cpp \
../tests/FillPathTest.cpp \
../tests/FlateTest.cpp \
../tests/GeometryTest.cpp \
../tests/InfRectTest.cpp \
../tests/MathTest.cpp \
../tests/MatrixTest.cpp \
../tests/MetaDataTest.cpp \
../tests/PDFPrimitivesTest.cpp \
../tests/PackBitsTest.cpp \
../tests/PaintTest.cpp \
../tests/ParsePathTest.cpp \
../tests/PathMeasureTest.cpp \
../tests/PathTest.cpp \
../tests/RefDictTest.cpp \
../tests/RegionTest.cpp \
../tests/Sk64Test.cpp \
../tests/SortTest.cpp \
../tests/SrcOverTest.cpp \
../tests/StreamTest.cpp \
../tests/StringTest.cpp \
../tests/Test.cpp \
../tests/TestSize.cpp \
../tests/TriangulationTest.cpp \
../tests/UtilsTest.cpp \
../tests/XfermodeTest.cpp \
../tests/skia_test.cpp 

OBJS += \
./tests/BitmapCopyTest.o \
./tests/BitmapGetColorTest.o \
./tests/BlitRowTest.o \
./tests/ClipCubicTest.o \
./tests/ClipStackTest.o \
./tests/ClipperTest.o \
./tests/DequeTest.o \
./tests/DrawBitmapRectTest.o \
./tests/FillPathTest.o \
./tests/FlateTest.o \
./tests/GeometryTest.o \
./tests/InfRectTest.o \
./tests/MathTest.o \
./tests/MatrixTest.o \
./tests/MetaDataTest.o \
./tests/PDFPrimitivesTest.o \
./tests/PackBitsTest.o \
./tests/PaintTest.o \
./tests/ParsePathTest.o \
./tests/PathMeasureTest.o \
./tests/PathTest.o \
./tests/RefDictTest.o \
./tests/RegionTest.o \
./tests/Sk64Test.o \
./tests/SortTest.o \
./tests/SrcOverTest.o \
./tests/StreamTest.o \
./tests/StringTest.o \
./tests/Test.o \
./tests/TestSize.o \
./tests/TriangulationTest.o \
./tests/UtilsTest.o \
./tests/XfermodeTest.o \
./tests/skia_test.o 

CPP_DEPS += \
./tests/BitmapCopyTest.d \
./tests/BitmapGetColorTest.d \
./tests/BlitRowTest.d \
./tests/ClipCubicTest.d \
./tests/ClipStackTest.d \
./tests/ClipperTest.d \
./tests/DequeTest.d \
./tests/DrawBitmapRectTest.d \
./tests/FillPathTest.d \
./tests/FlateTest.d \
./tests/GeometryTest.d \
./tests/InfRectTest.d \
./tests/MathTest.d \
./tests/MatrixTest.d \
./tests/MetaDataTest.d \
./tests/PDFPrimitivesTest.d \
./tests/PackBitsTest.d \
./tests/PaintTest.d \
./tests/ParsePathTest.d \
./tests/PathMeasureTest.d \
./tests/PathTest.d \
./tests/RefDictTest.d \
./tests/RegionTest.d \
./tests/Sk64Test.d \
./tests/SortTest.d \
./tests/SrcOverTest.d \
./tests/StreamTest.d \
./tests/StringTest.d \
./tests/Test.d \
./tests/TestSize.d \
./tests/TriangulationTest.d \
./tests/UtilsTest.d \
./tests/XfermodeTest.d \
./tests/skia_test.d 


# Each subdirectory must supply rules for building sources it contributes
tests/%.o: ../tests/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


