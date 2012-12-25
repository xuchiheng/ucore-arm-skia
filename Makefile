# Simple makefile for skia library and test apps

# setup our defaults
CC := arm-linux-androideabi-gcc
GPP := arm-linux-androideabi-g++
#CC := gcc
#GPP := g++
C_INCLUDES := -Iinclude/config -Iinclude/core -Iinclude/effects -Iinclude/images -Iinclude/ports -Iinclude/pdf
C_INCLUDES +=  -Iinclude/gpu -Iinclude/utils -Igpu/include -Isrc/core

CFLAGS := -Wall -fstrict-aliasing
#CFLAGS += -W -Wextra -Wcast-align -Wchar-subscripts -Wformat -Wformat-security -Wno-format-y2k -Wno-parentheses -Wno-unused-parameter -Wpointer-arith  -Wreturn-type -Wundef -Wwrite-strings
CFLAGS_SSE2 = $(CFLAGS) -msse2
LINKER_OPTS := -lpthread -lz
DEFINES := -DSK_CAN_USE_FLOAT
HIDE = @

ifeq ($(SKIA_SCALAR),fixed)
	DEFINES += -DSK_SCALAR_IS_FIXED
else
	DEFINES += -DSK_SCALAR_IS_FLOAT
endif

ifeq ($(SKIA_DEBUG),true)
 	DEFINES += -DSK_DEBUG -DSK_SUPPORT_UNIT -DGR_DEBUG=1
	CFLAGS += -g
else
	CFLAGS += -O2
	DEFINES += -DSK_RELEASE -DGR_DEBUG=0
endif

DEFINES += -DGR_IMPLEMENTATION=1

DEFINES += -DSK_SUPPORT_LCDTEXT

ifneq ($(SKIA_PDF_SUPPORT),false)
	DEFINES += -DSK_SUPPORT_PDF
	DEFINES += -DSK_ZLIB_INCLUDE="<zlib.h>"
endif

# start with the core (required)
include src/core/core_files.mk
SRC_LIST := $(addprefix src/core/, $(SOURCE))

# add the opts (optimizations)
#include src/opts/opts_sse2_files.mk
include src/opts/opts_files.mk
SRC_LIST += $(addprefix src/opts/, $(SOURCE))

# we usually need ports
include src/ports/ports_files.mk
SRC_LIST += $(addprefix src/ports/, $(SOURCE))

# do we want effects?
include src/effects/effects_files.mk
SRC_LIST += $(addprefix src/effects/, $(SOURCE))

# core image files
include src/images/images_files.mk
SRC_LIST += $(addprefix src/images/, $(SOURCE))

# core util files
include src/utils/utils_files.mk
SRC_LIST += $(addprefix src/utils/, $(SOURCE))

	LINKER_OPTS += -lGL -lpng
	DEFINES += -DSK_ENABLE_LIBPNG

    # these are our registry-based factories
	SRC_LIST += src/ports/SkFontHost_none.cpp
	SRC_LIST += src/images/SkImageDecoder_Factory.cpp
	SRC_LIST += src/images/SkImageEncoder_Factory.cpp
        SRC_LIST += src/images/SkImageDecoder_libpng.cpp
    # support files
	SRC_LIST += src/images/SkScaledBitmapSampler.cpp
	
	SRC_LIST += gpu/src/GrGLDefaultInterface_none.cpp


out/%.o : %.cpp
	@mkdir -p $(dir $@)
	$(HIDE)$(CC) $(C_INCLUDES) $(CFLAGS) $(DEFINES) -c $< -o $@
	@echo "compiling $@"

%.s : %.cpp
	@mkdir -p $(dir $@)
	$(CC) $(C_INCLUDES) $(CFLAGS) $(DEFINES) -S -c $< -o $@

# now build out objects
OBJ_LIST := $(SRC_LIST:.cpp=.o)
OBJ_LIST := $(addprefix out/, $(OBJ_LIST))

# we want to compile these, but we don't actually link them
JUST_COMPILE_OBJS := $(JUST_COMPILE_LIST:.cpp=.o)
JUST_COMPILE_OBJS := $(addprefix out/, $(JUST_COMPILE_OBJS))

out/libskia.a: Makefile $(OBJ_LIST) $(JUST_COMPILE_OBJS)
	$(HIDE)$(AR) ru $@ $(OBJ_LIST)
	$(HIDE)ranlib $@


# we let tests cheat and see private headers, so we can unittest modules
C_INCLUDES += -Isrc/core

include tests/tests_files.mk
TESTS_SRCS := $(addprefix tests/, $(SOURCE))

TESTS_OBJS := $(TESTS_SRCS:.cpp=.o)
TESTS_OBJS := $(addprefix out/, $(TESTS_OBJS))

tests: $(TESTS_OBJS) out/libskia.a
	@echo "linking tests..."
	$(HIDE)$(GPP) $(TESTS_OBJS) out/libskia.a -o out/tests/tests lib/libz.a -T bionic.ld
	cp out/tests/tests ~/ucore_plus/ucore/src/user-ucore/_initial/

.PHONY: all
all: $ bench gm skimage tests skhello

.PHONY: clean
clean:
	$(HIDE)rm -rf out

.PHONY: help
help:
	@echo "Targets:"
	@echo "    <default>: out/libskia.a"
	@echo "    bench: out/bench/bench"
	@echo "    gm: out/gm/gm"
	@echo "    skimage: out/tools/skimage"
	@echo "    skhello: out/tools/skhello"
	@echo "    tests: out/tests/tests"
	@echo "    clean: removes entire out/ directory"
	@echo "    help: this text"
	@echo "Options: (after make, or in bash shell)"
	@echo "    SKIA_DEBUG=true for debug build"
	@echo "    SKIA_SCALAR=fixed for fixed-point build"
	@echo "    SKIA_BUILD_FOR=mac for mac build (e.g. CG for image decoding)"
	@echo "    SKIA_PDF_SUPPORT=false to disable the pdf generation backend"
	@echo ""
