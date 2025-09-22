#include "variable_length_quantity.h"
#include <stddef.h>
#include <stdint.h>

int encode_int(uint32_t integer, uint8_t *res) {
  int i = 0;
  while (integer > 0) {
    res[i++] = integer & 127;
    integer /= 127;
  }
  res[i - 1] += 128;
  return i;
}

int encode(const uint32_t *integers, size_t integers_len, uint8_t *output) {
   uint8_t buffer[5];
  int size;
  int len = 0;
  for (size_t i = 0; i < integers_len; i++) {
   size = encode_int(integers[i], buffer);
    for (int j = size - 1; j >= 0; j--)
      output[len++] = buffer[j];
  }
  return len;;
}

int decode(const uint8_t *bytes, size_t buffer_len, uint32_t *output) {
  // write to `output`, return final output's length
  // return -1 if error
  // `output` buffer should be enough to hold the full result

  return 0;
}
