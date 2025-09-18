#include "prime_factors.h"
#include <math.h>
#include <stddef.h>
#include <stdint.h>

uint64_t is_prime(uint64_t n) {
  double fact = sqrt((double)n);
  for (uint64_t i = 2; i <= fact; i++) {
    if ((n % i) == 0)
      return 0;
  }
  return 1;
}

uint64_t next_prime(uint64_t n) {
  if (n < 2)
    return 2;
  n = (n % 2 == 0) ? n + 1 : n + 2;
  while (!is_prime(n))
    n += 2;
  return n;
}

size_t find_factors(uint64_t n, uint64_t factors[static MAXFACTORS]) {
  uint64_t factor = 2;
  size_t i = 0;
  while (factor <= n) {
    if ((n % factor) == 0) {
      factors[i++] = factor;
      n /= factor;
    } else {
      factor = next_prime(factor);
    }
  }
  return i;
}
