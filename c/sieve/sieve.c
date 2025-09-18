#include "sieve.h"
#include <stdio.h>

int is_divis(uint32_t *arr, uint32_t num, int idx) {
  for (int j = 0; j <= idx; j++) {
    if (num != arr[j] && !(num % arr[j]))
      return 1;
  }
  return 0;
}

uint32_t sieve(uint32_t limit, uint32_t *primes, size_t max_primes) {
  if (limit < 2)
    return 0;
  uint32_t idx = 0;
  primes[idx++] = 2;
  for (uint32_t i = 3; i <= limit; i++) {
    if (is_divis(primes, i, idx - 1))
      continue;
    primes[idx++] = i;
    if (idx == (uint32_t)max_primes)
      break;
  }
  return idx;
}
