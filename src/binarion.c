
#include "hanoi.h"

// create a binarion from real/imaginary part
uint64_t binarion64_t(long long real,long long imag){
	uint64_t ans = 0x00;
	long long quotient_r = real;
	long long quotient_i = imag;

   unsigned i;
	for(i = 0; i < 64; i++){
		if(quotient_r == 0 && quotient_i == 0){
			// if zero == remainder, terminate
			break;
		}

		if( ((quotient_i ^ quotient_r) & 0x01) ){
			// if here, remainder will be 1
			ans += (1ULL << i);
			quotient_r = quotient_r - 1; 
		}

		// multiply fraction by conjugate of the denominator (d=-1+i)
		long long temp = quotient_r;
		quotient_r = (-1 * quotient_r) + quotient_i;
		quotient_i = (-1 * temp) + (-1 * quotient_i);

		quotient_i /= 2LL;
		quotient_r /= 2LL;
	}
	return ans;
}

