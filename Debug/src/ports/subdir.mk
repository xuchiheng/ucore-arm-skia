################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/ports/SkDebug_android.cpp \
../src/ports/SkDebug_brew.cpp \
../src/ports/SkDebug_stdio.cpp \
../src/ports/SkFontHost_FONTPATH.cpp \
../src/ports/SkFontHost_FreeType.cpp \
../src/ports/SkFontHost_FreeType_Subpixel.cpp \
../src/ports/SkFontHost_android.cpp \
../src/ports/SkFontHost_ascender.cpp \
../src/ports/SkFontHost_fontconfig.cpp \
../src/ports/SkFontHost_gamma.cpp \
../src/ports/SkFontHost_gamma_none.cpp \
../src/ports/SkFontHost_linux.cpp \
../src/ports/SkFontHost_mac.cpp \
../src/ports/SkFontHost_mac_atsui.cpp \
../src/ports/SkFontHost_mac_coretext.cpp \
../src/ports/SkFontHost_none.cpp \
../src/ports/SkFontHost_simple.cpp \
../src/ports/SkFontHost_tables.cpp \
../src/ports/SkFontHost_win.cpp \
../src/ports/SkGlobals_global.cpp \
../src/ports/SkHarfBuzzFont.cpp \
../src/ports/SkImageDecoder_CG.cpp \
../src/ports/SkImageDecoder_empty.cpp \
../src/ports/SkImageRef_ashmem.cpp \
../src/ports/SkMemory_brew.cpp \
../src/ports/SkMemory_malloc.cpp \
../src/ports/SkOSEvent_android.cpp \
../src/ports/SkOSEvent_dummy.cpp \
../src/ports/SkOSFile_brew.cpp \
../src/ports/SkOSFile_stdio.cpp \
../src/ports/SkThread_none.cpp \
../src/ports/SkThread_pthread.cpp \
../src/ports/SkThread_win.cpp \
../src/ports/SkTime_Unix.cpp \
../src/ports/SkTime_win.cpp \
../src/ports/SkXMLParser_empty.cpp \
../src/ports/SkXMLParser_expat.cpp \
../src/ports/SkXMLParser_tinyxml.cpp \
../src/ports/SkXMLPullParser_expat.cpp 

OBJS += \
./src/ports/SkDebug_android.o \
./src/ports/SkDebug_brew.o \
./src/ports/SkDebug_stdio.o \
./src/ports/SkFontHost_FONTPATH.o \
./src/ports/SkFontHost_FreeType.o \
./src/ports/SkFontHost_FreeType_Subpixel.o \
./src/ports/SkFontHost_android.o \
./src/ports/SkFontHost_ascender.o \
./src/ports/SkFontHost_fontconfig.o \
./src/ports/SkFontHost_gamma.o \
./src/ports/SkFontHost_gamma_none.o \
./src/ports/SkFontHost_linux.o \
./src/ports/SkFontHost_mac.o \
./src/ports/SkFontHost_mac_atsui.o \
./src/ports/SkFontHost_mac_coretext.o \
./src/ports/SkFontHost_none.o \
./src/ports/SkFontHost_simple.o \
./src/ports/SkFontHost_tables.o \
./src/ports/SkFontHost_win.o \
./src/ports/SkGlobals_global.o \
./src/ports/SkHarfBuzzFont.o \
./src/ports/SkImageDecoder_CG.o \
./src/ports/SkImageDecoder_empty.o \
./src/ports/SkImageRef_ashmem.o \
./src/ports/SkMemory_brew.o \
./src/ports/SkMemory_malloc.o \
./src/ports/SkOSEvent_android.o \
./src/ports/SkOSEvent_dummy.o \
./src/ports/SkOSFile_brew.o \
./src/ports/SkOSFile_stdio.o \
./src/ports/SkThread_none.o \
./src/ports/SkThread_pthread.o \
./src/ports/SkThread_win.o \
./src/ports/SkTime_Unix.o \
./src/ports/SkTime_win.o \
./src/ports/SkXMLParser_empty.o \
./src/ports/SkXMLParser_expat.o \
./src/ports/SkXMLParser_tinyxml.o \
./src/ports/SkXMLPullParser_expat.o 

CPP_DEPS += \
./src/ports/SkDebug_android.d \
./src/ports/SkDebug_brew.d \
./src/ports/SkDebug_stdio.d \
./src/ports/SkFontHost_FONTPATH.d \
./src/ports/SkFontHost_FreeType.d \
./src/ports/SkFontHost_FreeType_Subpixel.d \
./src/ports/SkFontHost_android.d \
./src/ports/SkFontHost_ascender.d \
./src/ports/SkFontHost_fontconfig.d \
./src/ports/SkFontHost_gamma.d \
./src/ports/SkFontHost_gamma_none.d \
./src/ports/SkFontHost_linux.d \
./src/ports/SkFontHost_mac.d \
./src/ports/SkFontHost_mac_atsui.d \
./src/ports/SkFontHost_mac_coretext.d \
./src/ports/SkFontHost_none.d \
./src/ports/SkFontHost_simple.d \
./src/ports/SkFontHost_tables.d \
./src/ports/SkFontHost_win.d \
./src/ports/SkGlobals_global.d \
./src/ports/SkHarfBuzzFont.d \
./src/ports/SkImageDecoder_CG.d \
./src/ports/SkImageDecoder_empty.d \
./src/ports/SkImageRef_ashmem.d \
./src/ports/SkMemory_brew.d \
./src/ports/SkMemory_malloc.d \
./src/ports/SkOSEvent_android.d \
./src/ports/SkOSEvent_dummy.d \
./src/ports/SkOSFile_brew.d \
./src/ports/SkOSFile_stdio.d \
./src/ports/SkThread_none.d \
./src/ports/SkThread_pthread.d \
./src/ports/SkThread_win.d \
./src/ports/SkTime_Unix.d \
./src/ports/SkTime_win.d \
./src/ports/SkXMLParser_empty.d \
./src/ports/SkXMLParser_expat.d \
./src/ports/SkXMLParser_tinyxml.d \
./src/ports/SkXMLPullParser_expat.d 


# Each subdirectory must supply rules for building sources it contributes
src/ports/%.o: ../src/ports/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


