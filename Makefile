CC = g++
NAME = hanoi
SOURCEDIR = src
TESTDIR = tests
SOURCES := $(shell find $(SOURCEDIR) -name '*.c')
TESTSOURCES := $(shell find $(TESTDIR) -name '*.cpp')
TESTOBJS := main.o testing.o
OBJFILES := $(patsubst %.c,%.o,$(SOURCES))

# 1. build everything in ./src with:
# gcc -std=c99 -Wall -Wextra -c {*.c} 
# 2. combine these object files with: 
# gcc -shared -o libhanoi.so {*.o} -lm
# 3. build the test suite with:
# g++ -std=gnu++11 main.cpp testing.cpp -L{directory of .so}
# 4. Now, provided that hanoi.h gets included correctly, every
# definition will be defined 

%.o: %.c
	gcc -std=c99 -c -fPIC $<

tests: $(NAME)
	g++ -std=gnu++11 $(TESTSOURCES) -L. -lhanoi

$(NAME): $(OBJFILES)
	gcc -std=c99 -shared -fPIC -o libhanoi.so $(notdir $(OBJFILES)) -lm

all: $(NAME)

clean:
	rm -r *.o
	rm -r *.so
	$(NAME)
