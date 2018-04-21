
#include "hanoi.h"

uint64_t convert(uint64_t n, uint64_t fn1, uint64_t fn2, char found,
               uint64_t res, uint64_t bitmask){

   // We need to find the greatest Fibonacci number less than n.
   //printf("n: %llu, fn1: %llu, fn2: %llu\n", n, fn1, fn2);

   if(fn2 == 1 && fn1 == 1 && found == 1){
      if(n == 1){
         res = res | 1;
      }
      return res;
   }

   if(found == 1){
      // We found the least Fibonacci number greater than n.
      // Now, it starts popping the stack and doing the greedy algorithm.
      if(n >= fn1){
         // this bit is one
         return convert(n-fn1, fn2, fn1 - fn2, 1,
                res | bitmask, bitmask >> 1);
      } else{
         // this bit is zero
         return convert(n, fn2, fn1 - fn2, 1,
                res, bitmask >> 1);
      }
   }

   if(fn1 > n){
      //printf("now, going back down\n");
      return convert(n, fn2, fn1 - fn2, 1,
             res, bitmask);
   }else{
      return convert(n, fn1+fn2, fn1, 0,
             res, bitmask << 1);
   }
   
}

// Base Fibonacci
uint64_t fibonacci_encode(uint64_t n){
   if(n == 0){
      return 0;
   }
   return convert(n, 2, 1, 0, 0, 1);
}

// Convert a fibonacci integer into a standard binary integer
uint64_t fibonacci_decode(uint64_t  n){
   uint64_t last = 1;   
   uint64_t this_fib = 1;
   uint64_t temp = 0;   
   uint64_t sum = 0;
   uint64_t bitmask = 1;
   int i = 0;

   for(i = 0; i < 64; i++){
      if((bitmask & n) != 0){
         sum += this_fib;
      }
      temp = this_fib;
      this_fib = last + this_fib;
      last = temp;
      bitmask = bitmask + bitmask;
   }
   return sum;
}



