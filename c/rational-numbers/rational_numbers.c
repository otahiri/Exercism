#include "rational_numbers.h"
#include <stdio.h>

rational_t reduce(rational_t ratio)
{
  if (ratio.numerator == 0)
  {
    ratio.denominator = 1;
    return ratio;
  }
  int lowest = (abs(ratio.denominator) <= abs(ratio.numerator)) ? abs(ratio.denominator) : abs(ratio.numerator);
  for (int i = abs(lowest); i > 1; i--)
  {
    if (ratio.denominator % i == 0 && ratio.numerator % i == 0)
    {
      ratio.denominator /= i;
      ratio.numerator /= i;
      i = abs(lowest);
    }
  }
  ratio.numerator = (ratio.denominator < 0) ? -ratio.numerator : ratio.numerator;
  ratio.denominator = abs(ratio.denominator);
  return ratio;
}

rational_t add(rational_t r1, rational_t r2)
{
  rational_t sum;
  sum.numerator = (r1.numerator * r2.denominator) + (r2.numerator * r1.denominator);
  sum.denominator = r1.denominator * r2.denominator; 
  return reduce(sum);
}
rational_t subtract(rational_t r1, rational_t r2)
{
  rational_t sub;
  sub.numerator = (r1.numerator * r2.denominator) - (r2.numerator * r1.denominator);
  sub.denominator = r1.denominator * r2.denominator; 
  return reduce(sub);
}

rational_t multiply(rational_t r1, rational_t r2)
{
  rational_t mult;
  mult.numerator = r1.numerator * r2.numerator;
  mult.denominator = r1.denominator * r2.denominator;
  return reduce(mult);
}

rational_t divide(rational_t r1, rational_t r2)
{
  rational_t div;
  div.numerator = r1.numerator * r2.denominator;
  div.denominator = r2.numerator * r1.denominator;
  if (div.denominator < 0)
  {
    div.denominator *= -1;
    div.numerator *= -1;
  }
  return reduce(div);
}

rational_t absolute(rational_t r)
{
  r.numerator = abs(r.numerator);
  r.denominator = abs(r.denominator);
  return reduce(r);
}

rational_t exp_rational(rational_t r, int16_t n)
{
  int num = r.numerator;
  int den = r.denominator;
  if (n >= 0)
  {
    r.numerator = pow(num, n);
    r.denominator = pow(den, n);
  }
  else if (n < 0){
    r.numerator = (n & 1) ? -pow(den, abs(n)) : pow(den, abs(n));
    r.denominator = (n & 1) ? -pow(num, abs(n)) : pow(num, abs(n));
  }
  return  reduce(r);
}

float exp_real(uint16_t x, rational_t r)
{
  return (pow(pow(x, r.numerator), 1.0/r.denominator));
}
