#include <stdio.h>

extern "C" {
#include "../src/hanoi.h"
};

#include "testing.hpp"

uint64_t binarion_constructor(uint64_t * args){
   return binarion_encode(args[0], args[1]);
}

// This is the only number system we will test that must return a struct instead 
// of a uint64_t. The way we handle this is by doing one test file for the real
// and one test file for the imaginary part of the result.
uint64_t binarion_interpret_r(uint64_t * args){
   return binarion_decode(args[0]).real;
}

uint64_t binarion_interpret_i(uint64_t * args){
   return binarion_decode(args[0]).imag;
}

int main(void){
   printf("libhanoi 1.0 test suite\n");
   printf("Exotic integer system library\n");
   printf("Author: Nathan Nichols, nmnichols@gnu.org, 2018\n");

   testing::open_file("tests/cases/binarion_constructor",binarion_constructor);
   testing::open_file("tests/cases/binarion_interpret_r",binarion_interpret_r);
   testing::open_file("tests/cases/binarion_interpret_i",binarion_interpret_i);

   fibonacci_encode(13);

}
