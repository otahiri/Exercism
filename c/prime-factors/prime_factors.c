#include "prime_factors.h"
#include <stddef.h>
#include <stdint.h>

uint64_t next_prime(uint64_t n) {
  if (n == 2)
    return 3;
  uint64_t power = 0;
  uint64_t remain = n - 1;
  while ((remain & 1) == 0) {
    remain >>= 1;
    power++;
  }
}

size_t find_factors(uint64_t n, uint64_t factors[static MAXFACTORS]) {
  uint64_t prime = 2;
  size_t i = 0;
  while (n > 1) {
    if (n % prime == 0) {
      n /= prime;
      factors[i++] = prime;
    } else
      prime = next_prime(prime);
  }
  return i;
}
