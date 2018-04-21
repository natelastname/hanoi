
#ifndef HANOI_H
#define HANOI_H

#include <inttypes.h>

#include <stdio.h>

struct hanoi_complex {
   long long real;
   long long imag;
};

// binarion (base -1+i) constructor
uint64_t binarion_encode(long long real, long long imag);

// interpret a binarion as a complex number
struct hanoi_complex binarion_decode(uint64_t binarion);

// Base Fibonacci
uint64_t fibonacci_encode(uint64_t n);

// Convert a fibonacci integer into a standard binary integer
uint64_t fibonacci_decode(uint64_t n);

#endif // HANOI_H

