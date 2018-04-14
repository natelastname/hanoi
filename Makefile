# Makefile with support for Windows (mingw32) and NIX (clang / gcc)

CC = gcc
NAME = hanoi
SOURCEDIR = src
SOURCES := $(shell find $(SOURCEDIR) -name '*.c')

CFLAGS =
CFLAGS += -std=c99
CFLAGS += -Wshadow -Wall -Wpedantic -Wextra -Wdouble-promotion -Wunused-result

if ${DEBUG}=y
   CFLAGS += -g
else
   # why not O3?
   CLFAGS += -O2
endif


# Get list of object files, with paths
OBJECTS := $(addprefix $(BUILDDIR)/,$(SOURCES:%.c=%.o))

$(BINARY): $(OBJECTS)
    $(CC) $(CFLAGS) $(LDFLAGS) $(OBJECTS) -o $(BINARY)



hanoi: $(SRCS)
   $(CC) $(CFLAGS) -o
