#include "circular_buffer.h"

circular_buffer_t new_circular_buffer(capacity)
{
  circular_buffer_t circ;
  circ = calloc(1, sizeof(circular_buffer_t));
  circ.buffer = calloc(capacity, sizeof(buffer_value_t));
  circ.capacity = capacity;
  return circ;
}

void delete_buffer(circular_buffer_t buffer)
{
  free(buffer.buffer);
  free(buffer);
}
