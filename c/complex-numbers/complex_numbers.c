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
	res.real = ((a.real * b.real) - (a.imag * b.imag));
	res.imag = ((a.imag * b.real) + (a.real * b.imag));
	return res;
}

complex_t c_div(complex_t a, complex_t b)
{
	double i = (b.real * b.real) + (b.imag * b.imag) ;
	complex_t res;
	res.real = ((a.real * b.real) + (a.imag * b.imag)) / i;
	res.imag = ((a.imag * b.real) - (a.real * b.imag)) / i;
	return res;
}

double c_abs(complex_t x)
{
	return sqrt(pow(x.real, 2) + pow(x.imag, 2));
}

complex_t c_conjugate(complex_t x)
{
	x.imag *= -1;
	return x;
}

double c_real(complex_t x)
{
	return x.real;
}

double c_imag(complex_t x)
{
	return x.imag;
}

complex_t c_exp(complex_t x)
{
	double exp_a = exp(x.real);
	x.real = exp_a * cos(x.imag);
	x.imag = exp_a * sin(x.imag);
	return x;
}
