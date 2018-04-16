
#ifndef HANOI_H
#define HANOI_H

#include <inttypes.h>


struct hanoi_complex {
   long long real;
   long long imag;
};

// binarion (base -1+i) constructor
uint64_t binarion_encode(long long real, long long imag);

// interpret a binarion as a complex number
struct hanoi_complex binarion_decode(uint64_t binarion);


#endif // HANOI_H

