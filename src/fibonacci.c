
#include "hanoi.h"

uint64_t convert(uint64_t n, uint64_t fn1, uint64_t fn2, char found){

   // we need to find the greatest Fibonacci number less than n 
   
   printf("n: %llu, fn1: %llu, fn2: %llu\n", n, fn1, fn2);

   if(fn2 == 1 && fn1 == 1 && found == 1){
      return 0;
   }

   if(found == 1){
      // now we do the greedy algorithm
      if(n >= fn2){
         return convert(n-fn1, fn2, fn1 - fn2, 1);
      } else{
         return convert(n, fn2, fn1 - fn2, 1);
      }
   }
   if(n == 0){
      return 0;
   }

   //printf("found: %i, res: %llu, bitmask: %x\n\n", found, res, bitmask);

   if(fn1 > n){
      printf("\nnow, going back down\n\n");
      return convert(n, fn2, fn1 - fn2, 1);
   }else{
      return convert(n, fn1+fn2, fn1, 0);
   }
   
}

// Base Fibonacci
uint64_t fibonacci_encode(uint64_t n){
   convert(n, 1, 1, 0);
}

// Convert a fibonacci integer into a standard binary integer
uint64_t fibonacci_decode(uint64_t fib){


   return 0;
}
