#include "kindergarten_garden.h"

int which_plant(char c) {
  char *plants = "CGRV";
  for (int i = 0; plants[i]; i++) {
    if (c == plants[i])
      return i;
  }
  return -1;
}

plants_t plants(const char *diagram, const char *student) {

  plants_t res;
  int i = 0;
  res.plants[i++] = which_plant(diagram[(student[0] - 'A') * 2]);
  res.plants[i++] = which_plant(diagram[(student[0] - 'A') * 2 + 1]);
  int j = 0;
  for (; diagram[j] != '\n'; j++)
    ;
  j++;
  res.plants[i++] = which_plant(diagram[(student[0] - 'A') * 2 + j]);
  res.plants[i++] = which_plant(diagram[(student[0] - 'A') * 2 + 1 + j]);
  return res;
}
