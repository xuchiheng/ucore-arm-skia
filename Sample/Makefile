C_INCLUDES := -I../include/core \
	-I../include/config \
	-I../include/effects \
	-I../include/images \
	-I../include/utils \
	-I../include/views \
	-I../include/xml \
	-I../include/gpu \
	-I../gpu/include \
	-I../include/utils/unix \
	-I../samplecode

GPP := arm-linux-androideabi-g++

VPATH = libs:../src/ports:../samplecode:../src/core:../src/utils/unix

#generate debugging info
#	$(GPP) $(C_INCLUDES) $(CFLAGS)  $^ -L. -static -lpng -lz  -o $@ -T bionic.ld
CFLAGS = -g

SRC_LIST := main.cpp
 
.PHONY: all
test: $(SRC_LIST) ../out/libskia.a ../lib/libpng.a ../lib/libz.a
	$(GPP) $(C_INCLUDES) $(CFLAGS)  $^  -o $@ -T bionic.ld
	cp test ~/ucore_plus/ucore/src/user-ucore/_initial/

.PHONY: clean
clean:
	rm -rf test

