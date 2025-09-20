#include "sublist.h"
#include <stdio.h>

int sublist(int *small_list, int *large_list, int size_small, int size_large) {
  int count = 0;
  int i = 0;
  int j = 0;

  while (i < size_small && j < size_large) {
    i = 0;
    count = 0;
    while (small_list[i] == large_list[j + i]) {
      count++;
      i++;
    }
    if (count == size_small)
      break;
    j++;
  }
  return count == size_small ? 1 : 0;
}

comparison_result_t check_lists(int *list, int *base_list, size_t list_count,
                                size_t base_list_count) {
  if (list_count < base_list_count)
    return sublist(list, base_list, list_count, base_list_count) ? 2 : 1;
  if (base_list_count < list_count)
    return sublist(base_list, list, base_list_count, list_count) ? 3 : 1;
  return !sublist(base_list, list, base_list_count, base_list_count);
}
