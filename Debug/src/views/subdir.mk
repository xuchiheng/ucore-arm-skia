################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/views/SkBGViewArtist.cpp \
../src/views/SkBorderView.cpp \
../src/views/SkEvent.cpp \
../src/views/SkEventSink.cpp \
../src/views/SkImageView.cpp \
../src/views/SkListView.cpp \
../src/views/SkListWidget.cpp \
../src/views/SkOSMenu.cpp \
../src/views/SkParsePaint.cpp \
../src/views/SkProgressBarView.cpp \
../src/views/SkProgressView.cpp \
../src/views/SkScrollBarView.cpp \
../src/views/SkStackViewLayout.cpp \
../src/views/SkStaticTextView.cpp \
../src/views/SkTagList.cpp \
../src/views/SkTextBox.cpp \
../src/views/SkTouchGesture.cpp \
../src/views/SkView.cpp \
../src/views/SkViewInflate.cpp \
../src/views/SkViewPriv.cpp \
../src/views/SkWidget.cpp \
../src/views/SkWidgetViews.cpp \
../src/views/SkWidgets.cpp \
../src/views/SkWindow.cpp 

OBJS += \
./src/views/SkBGViewArtist.o \
./src/views/SkBorderView.o \
./src/views/SkEvent.o \
./src/views/SkEventSink.o \
./src/views/SkImageView.o \
./src/views/SkListView.o \
./src/views/SkListWidget.o \
./src/views/SkOSMenu.o \
./src/views/SkParsePaint.o \
./src/views/SkProgressBarView.o \
./src/views/SkProgressView.o \
./src/views/SkScrollBarView.o \
./src/views/SkStackViewLayout.o \
./src/views/SkStaticTextView.o \
./src/views/SkTagList.o \
./src/views/SkTextBox.o \
./src/views/SkTouchGesture.o \
./src/views/SkView.o \
./src/views/SkViewInflate.o \
./src/views/SkViewPriv.o \
./src/views/SkWidget.o \
./src/views/SkWidgetViews.o \
./src/views/SkWidgets.o \
./src/views/SkWindow.o 

CPP_DEPS += \
./src/views/SkBGViewArtist.d \
./src/views/SkBorderView.d \
./src/views/SkEvent.d \
./src/views/SkEventSink.d \
./src/views/SkImageView.d \
./src/views/SkListView.d \
./src/views/SkListWidget.d \
./src/views/SkOSMenu.d \
./src/views/SkParsePaint.d \
./src/views/SkProgressBarView.d \
./src/views/SkProgressView.d \
./src/views/SkScrollBarView.d \
./src/views/SkStackViewLayout.d \
./src/views/SkStaticTextView.d \
./src/views/SkTagList.d \
./src/views/SkTextBox.d \
./src/views/SkTouchGesture.d \
./src/views/SkView.d \
./src/views/SkViewInflate.d \
./src/views/SkViewPriv.d \
./src/views/SkWidget.d \
./src/views/SkWidgetViews.d \
./src/views/SkWidgets.d \
./src/views/SkWindow.d 


# Each subdirectory must supply rules for building sources it contributes
src/views/%.o: ../src/views/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


