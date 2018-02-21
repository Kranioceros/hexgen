OBJS_DIR=Build.lnx
TESTS_DIR=tests
GPP=g++
GCC=gcc
FLAGS=-fshow-column  -g2 -Wall -O0  -D_DEBUG -g -std=c++11
LIBS=-lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

#all: tests ${OBJS_DIR} ${OBJS_DIR}/Project.bin
all: tests

include Makefile.common

tests: ${TESTS}

clean:
	rm -rf ${OBJS} ${OBJS_DIR}/Project.bin

#${OBJS_DIR}/Project.bin: ${OBJS}
#	${GPP} ${OBJS} ${LIBS} -o $@

#${OBJS_DIR}:
#	mkdir ${OBJS_DIR}

