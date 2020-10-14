#include <stdio.h>

extern "C" {
#include "../src/hanoi.h"
};

#include "testing.hpp"

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

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

void padded_print(int n,int pad){
	int temp = n;
	int n_digits = 1; 
	while(temp / 10 > 0){
		temp = temp / 10;
		n_digits = n_digits + 1;
	}
	int i;
	if(pad < n_digits){
		printf("%i",n);
	}
	for(i = 0; i < (pad - n_digits); i++){
		printf("0");
	}
	printf("%i",n);
}

int main(void){
   printf("libhanoi 1.0 test suite\n");
   printf("Exotic integer system library\n");
   printf("Author: Nathan Nichols, nathannichols454@gmail.com, 2018\n");

   testing::open_file("tests/cases/binarion_constructor",binarion_constructor);
   testing::open_file("tests/cases/binarion_interpret_r",binarion_interpret_r);
   testing::open_file("tests/cases/binarion_interpret_i",binarion_interpret_i);
   testing::open_file("tests/cases/fibonacci_constructor",fibonacci_constructor);
   testing::open_file("tests/cases/fibonacci_interpret",fibonacci_interpret);
   
   /*
   std::cout << testing::binary_string(sternbrocot_encode(1,5)) << std::endl;
   std::cout << testing::binary_string(sternbrocot_encode(2,7)) << std::endl;
   std::cout << testing::binary_string(sternbrocot_encode(3,8)) << std::endl;
   std::cout << testing::binary_string(sternbrocot_encode(3,7)) << std::endl;
   std::cout << testing::binary_string(sternbrocot_encode(4,7)) << std::endl;
   std::cout << testing::binary_string(sternbrocot_encode(5,8)) << std::endl;
   std::cout << testing::binary_string(sternbrocot_encode(5,7)) << std::endl;
   std::cout << testing::binary_string(sternbrocot_encode(4,5)) << std::endl;
   std::cout << testing::binary_string(sternbrocot_encode(5,4)) << std::endl;
   std::cout << testing::binary_string(sternbrocot_encode(7,5)) << std::endl;
   std::cout << testing::binary_string(sternbrocot_encode(8,5)) << std::endl;
   std::cout << testing::binary_string(sternbrocot_encode(7,4)) << std::endl;
   std::cout << testing::binary_string(sternbrocot_encode(7,3)) << std::endl;
   std::cout << testing::binary_string(sternbrocot_encode(8,3)) << std::endl;
   std::cout << testing::binary_string(sternbrocot_encode(7,2)) << std::endl;
   std::cout << testing::binary_string(sternbrocot_encode(5,1)) << std::endl;
   */

}












