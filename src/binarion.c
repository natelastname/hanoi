
#include "hanoi.h"

// create a binarion (base -1+i) from real/imaginary part
uint64_t binarion_encode(long long real,long long imag){
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

struct hanoi_complex binarion_decode(uint64_t binarion){

   // place value of current bit
   long long value_r = 1;
   long long value_i = 0;
   long long temp = 0;

   struct hanoi_complex ans;
   ans.real = 0;
   ans.imag = 0;

   uint64_t mask = 0x01;

   for(int i = 0; i < 64; i++){

      if((binarion & mask) != 0){
         ans.real += value_r;
         ans.imag += value_i;
      }
      //printf("%i + %ii\n",value_r, value_i);
      // calculate the next place value
      // (complex multiply by -1+i)
      // (a , b)(-1 , 1) = (-a + -b, -b + a)
      temp = value_r;
      value_r = (value_r * -1) + (value_i * -1);
      value_i = (temp * 1) + (value_i * -1);
      
      mask = mask + mask;   
   }

   return ans;

}












