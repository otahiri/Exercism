#include "beer_song.h"
#include <stdint.h>
#include <stdio.h>

// 50 bottles of beer on the wall, 50 bottles of beer.Take one down and pass it
// around, 49 bottles of beer on the wall.
static const char *FIRST_LINE[3] = {
    "No more bottles of beer on the wall, no more bottles of beer.",
    "1 bottle of beer on the wall, 1 bottle of beer.",
    "%u bottles of beer on the wall, %u bottles of beer."};

static const char *SECOND_LINE[4] = {
    "Go to the store and buy some more, 99 bottles of beer on the wall.",
    "Take it down and pass it around, no more bottles of beer on the wall.",
    "Take one down and pass it around, 1 bottle of beer on the wall.",
    "Take one down and pass it around, %u bottles of beer on the wall."};
#define MAX_SIZE (1024)

void recite(uint8_t start_bottles, uint8_t take_down, char **song) {
  uint8_t end = start_bottles - (take_down - 1);
  for (int8_t bottle = start_bottles; bottle >= end; bottle--) {
    snprintf(*song++, MAX_SIZE, FIRST_LINE[bottle > 1 ? 2 : bottle], bottle,
             bottle);
    snprintf(*song++, MAX_SIZE, SECOND_LINE[bottle - 1 > 1 ? 3 : bottle],
             bottle - 1);
    song++;
  }
}
