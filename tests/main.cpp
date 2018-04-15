#include <stdio.h>

extern "C" {
#include "../src/hanoi.h"
};

#include "testing.hpp"

uint64_t binarion_constructor(uint64_t * args){
   return binarion64_t(args[0], args[1]);
}

int main(void){
   printf("libhanoi 1.0 test suite\n");
   printf("Exotic integer system library\n");
   printf("Author: Nathan Nichols, nmnichols@gnu.org, 2018\n");

   testing::open_file("tests/cases/binarion_constructor",binarion_constructor);

}
