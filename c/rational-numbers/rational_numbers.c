#include "rational_numbers.h"

rational_t reduce(rational_t ratio)
{
  int lowest = (ratio.denominator <= ratio.numerator) ? ratio.denominator : ratio.numerator;
  for (int i = lowest; i > 1; i--)
  {
    if (ratio.denominator % i == 0 && ratio.numerator % i == 0)
    {
      ratio.denominator /= i;
      ratio.numerator /= i;
      i = lowest;
    }
  }
  return ratio;
}

rational_t add(rational_t r1, rational_t r2)
{
  rational_t sum;
  sum.numerator = (r1.numerator * r2.denominator) + (r2.numerator * r1.denominator);
  sum.denominator = r1.denominator * r2.denominator; 
  return sum;
}
rational_t subtract(rational_t r1, rational_t r2)
{
  rational_t sub;
  sub.numerator = (r1.numerator * r2.denominator) - (r2.numerator * r1.denominator);
  sub.denominator = r1.denominator * r2.denominator; 
  return sub;
}

rational_t multiply(rational_t r1, rational_t r2)
{
  rational_t mult;
  mult.numerator = r1.numerator * r2.numerator;
  mult.denominator = r1.denominator * r2.denominator;
  return mult;
}

rational_t divide(rational_t r1, rational_t r2)
{
  rational_t div;
  div.numerator = r1.numerator * r2.denominator;
  div.denominator = r2.numerator * r1.denominator;
  return div;
}

rational_t absolute(rational_t r)
{
  r.numerator = abs(r.numerator);
  r.denominator = abs(r.denominator);
  return r;
}

rational_t exp_rational(rational_t r, int16_t n)
{
  if (n >= 0)
  {
    r.numerator = pow(r.numerator, n);
    r.denominator = pow(r.denominator, n);
  }
  else{
    r.numerator = pow(r.denominator, abs(n));
    r.denominator = pow(r.numerator, abs(n));
  }
  return  r;
}

//Exponentiation of a real number `x` to a rational number `r = a/b` is `x^(a/b) = root(x^a, b)`, where `root(p, q)` is the `q`th root of `p`.
//

float exp_real(uint16_t x, rational_t r)
{
  float res = sqrt()
  return  ;
}
