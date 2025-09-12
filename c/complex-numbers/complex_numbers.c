#include "complex_numbers.h"

complex_t c_add(complex_t a, complex_t b)
{
   complex_t res;
   res.real = a.real + b.real;
   res.imag = a.imag + b.imag;
   return res;
}

complex_t c_sub(complex_t a, complex_t b)
{
   complex_t res;
   res.real = a.real - b.real;
   res.imag = a.imag - b.imag;
   return res;
}

complex_t c_mul(complex_t a, complex_t b)
{
	complex_t res;
	res.real = ((a.rea * b.real) + (a.imag * b.imag));
	res.imag = ((a.imag * b.real) - (a.rea * b.imag));
	return res;
}

complex_t c_div(complex_t a, complex_t b)
{
	int i = (b.real * b.real) + (b.imag * b.imag) ;
	complex_t res;
	res.real = ((a.rea * b.real) + (a.imag * b.imag)) / i;
	res.imag = ((a.imag * b.real) - (a.rea * b.imag)) / i;
	return res;
}

double c_abs(complex_t x)
{
   // TODO: implement
}

complex_t c_conjugate(complex_t x)
{
   // TODO: implement
}

double c_real(complex_t x)
{
   // TODO: implement
}

double c_imag(complex_t x)
{
   // TODO: implement
}

complex_t c_exp(complex_t x)
{
   // TODO: implement
}
