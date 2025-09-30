#include "list_ops.h"

list_t *new_list(size_t length, list_element_t elements[])
{
  list_t *list;
  list = malloc(sizeof(list_t) + (length * sizeof(list_element_t)));
  for (size_t i = 0; i < length; i++)
    list->elements[i] = elements[i];
  list->length = length;
  return list;
}


// append entries to a list and return the new list
list_t *append_list(list_t *list1, list_t *list2)
{
  for (size_t i = 0; i < list2->length; i++)
    list1->elements[i + list1->length] = list2->elements[i];
  list1->length += list2->length;
  return list1;
}

// filter list returning only values that satisfy the filter function
list_t *filter_list(list_t *list, bool (*filter)(list_element_t)) {
  list_t *filt;
  filt = malloc(sizeof(list_t *));
  size_t idx = 0;
  for (size_t i = 0; i < list->length; i++)
  {
    if (filter(list->elements[i]))
      filt->elements[idx++] = list->elements[i];
  }
  filt->length = idx;
  return filt;
}

// returns the length of the list
size_t length_list(list_t *list)
{
  return list->length;
}

// return a list of elements whose values equal the list value transformed by
// the mapping function
list_t *map_list(list_t *list, list_element_t (*map)(list_element_t))
{
  list_t *res;
  res = malloc(sizeof(list_t) + (list->length * sizeof(list_element_t)));
  size_t idx = 0;
  for (size_t i = 0; i < list->length; i++)
  {
        res->elements[idx++] = map(list->elements[i]);
  }
  res->length = idx;
  return res;
}

// folds (reduces) the given list from the left with a function
list_element_t foldl_list(list_t *list, list_element_t initial,
                          list_element_t (*foldl)(list_element_t,
                                                  list_element_t))
{
  if (!list->length)
    return initial;
  for (size_t i = 0; i < list->length; i++)
  {
    initial = foldl(list->elements[i], initial);
  }
  return initial;
}

// folds (reduces) the given list from the right with a function
list_element_t foldr_list(list_t *list, list_element_t initial,
                          list_element_t (*foldr)(list_element_t,
                                                  list_element_t))
{
  if (!list->length)
    return initial;
  for (size_t i = list->length; i > 0; i--)
    initial = foldr(list->elements[i - 1], initial);
  return initial;
}

list_t *reverse_list(list_t *list)
{
  if (!list->length)
    return list;
  list_element_t tmp;
  size_t end = list->length - 1;
  for (size_t i = 0; i < end; i++, end--)
  {
    tmp = list->elements[i];
    list->elements[i] = list->elements[end];
    list->elements[end] = tmp;
  }
  return list;
}

// destroy the entire list
// list will be a dangling pointer after calling this method on it
void delete_list(list_t *list)
{
  free(list);
}
