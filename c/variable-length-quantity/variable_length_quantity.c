#include "variable_length_quantity.h"
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

int encode_int(uint32_t integer, uint8_t *res) {
  int i = 0;
  int tmp[5];
  if (integer == 0)
  {
    res[i++] = 0x00;
    return 1;
  }
  while (integer > 0) {
      tmp[i++] = integer & 127;
      integer >>= 7;
  }
  int len = i;
  for (int j = 0; j < i; j++)
      res[j] = tmp[i - 1 - j];
  for (int j = 0; j < i - 1; j++)
      res[j] |= 0x80;
  return len;
}

int encode(const uint32_t *integers, size_t integers_len, uint8_t *output) {
   uint8_t buffer[5];
  int size;
  int len = 0;
  for (size_t i = 0; i < integers_len; i++) {
   size = encode_int(integers[i], buffer);
    for (int j = 0;  j < size; j++)
      output[len++] = buffer[j];
  }
  return len;
}

int decode(const uint8_t *bytes, size_t buffer_len, uint32_t *output) {
  // write to `output`, return final output's length
  // return -1 if error
  // `output` buffer should be enough to hold the full result
  size_t i = 0;
  size_t j = 0;
  while (i < buffer_len)
  {
    uint32_t value = 0;
    while (1)
    {
      if (i >= buffer_len) return -1;
      uint8_t byte = bytes[i++];
      value = (value << 7) | (byte & 0x7f);
      if ((byte & 0x80) == 0)
        break;
    }
    output[j++] = value;
  }
  return j;
}
