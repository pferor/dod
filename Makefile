#
#
#

CC      = gcc
CCLFAGS = -Wall -Werr -pedantic
LDFLAGS = -lcrypt

SHELL = /bin/sh
.SUFFIXES:
.SUFFIXES: .c .h .o


OBJS   = main.o usage.o crypt.o
TARGET = dod

${TARGET}: ${OBJS}
	${CC} ${LDFLAGS} -o $@ $^

%.o: %.c
	${CC} ${CCFLAGS} -c -o $@ $<


all:
	make ${TARGET}

clean-obj:
	rm -f ${OBJS}

clean:
	rm -f ${TARGET} ${OBJS}

help:
	@echo "'make all' to build"
	@echo "'make clean' to remove object files and the binary"

