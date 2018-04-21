#include <stdio.h>

extern "C" {
#include "../src/hanoi.h"
};

#include "testing.hpp"

uint64_t binarion_constructor(uint64_t * args){
   return binarion_encode(args[0], args[1]);
}

uint64_t binarion_interpret_r(uint64_t * args){
   return binarion_decode(args[0]).real;
}

uint64_t binarion_interpret_i(uint64_t * args){
   return binarion_decode(args[0]).imag;
}


uint64_t fibonacci_constructor(uint64_t * args){
   return fibonacci_encode(args[0]);
}

uint64_t fibonacci_interpret(uint64_t * args){
   return fibonacci_decode(args[0]);
}


int main(void){
   printf("libhanoi 1.0 test suite\n");
   printf("Exotic integer system library\n");
   printf("Author: Nathan Nichols, nmnichols@gnu.org, 2018\n");

   testing::open_file("tests/cases/binarion_constructor",binarion_constructor);
   testing::open_file("tests/cases/binarion_interpret_r",binarion_interpret_r);
   testing::open_file("tests/cases/binarion_interpret_i",binarion_interpret_i);
   testing::open_file("tests/cases/fibonacci_constructor",fibonacci_constructor);
   testing::open_file("tests/cases/fibonacci_interpret",fibonacci_interpret);

}












