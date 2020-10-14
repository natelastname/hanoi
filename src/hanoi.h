
#ifndef HANOI_H
#define HANOI_H

#include <inttypes.h>
#include <stdio.h>

#define HANOI_SB_SIGN 0x8000000000000000
#define HANOI_SB_ZERO 0x8000000000000000
#define HANOI_SB_NAN  (~0x8000000000000000)


// binarion (base -1+i) 
struct hanoi_complex {
   long long real;
   long long imag;
};

uint64_t binarion_encode(long long real, long long imag);
struct hanoi_complex binarion_decode(uint64_t binarion);

// Base Fibonacci
uint64_t fibonacci_encode(uint64_t n);
uint64_t fibonacci_decode(uint64_t n);

// Stern-Brocot rationals

struct hanoi_rational {
   long long numer;
   long long denom;
};

// Only approximates the given fraction
// TODO: what does passing a fraction not in lowest terms do
uint64_t sternbrocot_encode(uint32_t numerator, uint32_t denominator);
struct hanoi_rational sternbrocot_decode(uint64_t sternbrocot);
uint64_t sternbrocot_special(uint64_t value);

#endif // HANOI_H

