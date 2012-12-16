################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include xcode/sampleapp_sdl/subdir.mk
-include xcode/hostapp/subdir.mk
-include xch/subdir.mk
-include vs/SampleApp/subdir.mk
-include unix_test_app/subdir.mk
-include tools/subdir.mk
-include third_party/harfbuzz/tests/shaping/subdir.mk
-include third_party/harfbuzz/tests/linebreaking/subdir.mk
-include third_party/harfbuzz/src/subdir.mk
-include third_party/harfbuzz/contrib/subdir.mk
-include third_party/glu/libtess/subdir.mk
-include tests/subdir.mk
-include src/xml/subdir.mk
-include src/views/subdir.mk
-include src/utils/win/subdir.mk
-include src/utils/unix/subdir.mk
-include src/utils/mac/subdir.mk
-include src/utils/SDL/subdir.mk
-include src/utils/subdir.mk
-include src/text/subdir.mk
-include src/svg/subdir.mk
-include src/ports/subdir.mk
-include src/pdf/subdir.mk
-include src/opts/subdir.mk
-include src/images/subdir.mk
-include src/gpu/subdir.mk
-include src/effects/subdir.mk
-include src/core/subdir.mk
-include src/animator/subdir.mk
-include samplecode/subdir.mk
-include out/src/utils/subdir.mk
-include out/src/ports/subdir.mk
-include out/src/opts/subdir.mk
-include out/src/images/subdir.mk
-include out/src/effects/subdir.mk
-include out/src/core/subdir.mk
-include out/gpu/src/subdir.mk
-include obsolete/subdir.mk
-include gpu/src/win/subdir.mk
-include gpu/src/mac/subdir.mk
-include gpu/src/subdir.mk
-include gm/subdir.mk
-include forth/subdir.mk
-include experimental/subdir.mk
-include bench/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: skia

# Tool invocations
skia: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross G++ Linker'
	g++  -o "skia" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C++_DEPS)$(OBJS)$(C_DEPS)$(CC_DEPS)$(CPP_DEPS)$(EXECUTABLES)$(CXX_DEPS)$(C_UPPER_DEPS) skia
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
