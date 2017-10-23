# makefile

CC := gcc
CFLAGS := -Wall
SOURCES := assign.h asign.c
#libraries to link with
LDLIBS :=-lm
OUT_FILE := a.out
build: $(SOURCES)
	$(CC) $(CFLAGS) -o $(OUT_FILE) $(SOURCES) $(LDLIBS)

clean:
	rm -f $(OUT_FILE)

rebuild: clean build

all: build
