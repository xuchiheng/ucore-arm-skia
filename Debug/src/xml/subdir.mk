################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/xml/SkBML_XMLParser.cpp \
../src/xml/SkDOM.cpp \
../src/xml/SkJS.cpp \
../src/xml/SkJSDisplayable.cpp \
../src/xml/SkXMLParser.cpp \
../src/xml/SkXMLPullParser.cpp \
../src/xml/SkXMLWriter.cpp 

OBJS += \
./src/xml/SkBML_XMLParser.o \
./src/xml/SkDOM.o \
./src/xml/SkJS.o \
./src/xml/SkJSDisplayable.o \
./src/xml/SkXMLParser.o \
./src/xml/SkXMLPullParser.o \
./src/xml/SkXMLWriter.o 

CPP_DEPS += \
./src/xml/SkBML_XMLParser.d \
./src/xml/SkDOM.d \
./src/xml/SkJS.d \
./src/xml/SkJSDisplayable.d \
./src/xml/SkXMLParser.d \
./src/xml/SkXMLPullParser.d \
./src/xml/SkXMLWriter.d 


# Each subdirectory must supply rules for building sources it contributes
src/xml/%.o: ../src/xml/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


