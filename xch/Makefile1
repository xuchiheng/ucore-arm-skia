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
CFLAGS = -g

SRC_LIST := main.cpp
 
.PHONY: all
test: $(SRC_LIST) ../out/libskia.a
	$(GPP) $(C_INCLUDES) $(CFLAGS) $^ -o $@

.PHONY: check
check: $(SRC_LIST) libskia.a
	g++ $(C_INCLUDES) $(CFLAGS)  -lpthread $^ -o $@

.PHONY: clean
clean:
	rm -rf test check