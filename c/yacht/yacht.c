#include "yacht.h"

int add(int *dice, int rule) {
  int score = 0;
  for (int i = 0; i < 5; i++) {
    if (dice[i] == rule)
      score += rule;
  }
  return score;
}

int full_house(int *dice) {
  int nums[6] = {0};
  int two = 0;
  int three = 0;
  for (int i = 0; i < 5; i++)
    nums[dice[i] - 1]++;
  for (int i = 0; i < 6; i++) {
    if (nums[i] == 3)
      three = i + 1;
    if (nums[i] == 2)
      two = i + 1;
  }
  return (three && two) ? (2 * two) + (3 * three) : 0;
}

int four(int *dice) {
  int count[6] = {0};
  int quad = 0;
  for (int i = 0; i < 5; i++)
    count[dice[i] - 1]++;
  for (int i = 0; i < 6; i++)
    if (count[i] >= 4)
      quad = i + 1;
  return quad * 4;
}

int lil_straight(int *dice) {
  int count = 0;
  for (int i = 1; i < 6; i++) {
    count = 0;
    for (int j = 0; j < 5; j++) {
      if (i == dice[j]) {
        count = 1;
        break;
      }
    }
    if (!count)
      return 0;
  }
  return 30;
}

int big_straight(int *dice) {
  int count = 0;
  for (int i = 2; i < 7; i++) {
    count = 0;
    for (int j = 0; j < 5; j++) {
      if (i == dice[j]) {
        count = 1;
        break;
      }
    }
    if (!count)
      return 0;
  }
  return 30;
}

int choice(int *dice) {
  int sum = 0;
  for (int i = 0; i < 5; i++)
    sum += dice[i];
  return sum;
}

int yacht(int *dice) {
  for (int i = 1; i < 5; i++)
    if (dice[0] != dice[i])
      return 0;
  return 50;
}
int (*rule[])(int *) = {full_house,   four,   lil_straight,
                        big_straight, choice, yacht};
int score(dice_t dice, category_t category) {
  return category < FULL_HOUSE ? add(dice.faces, category + 1)
                               : rule[category - FULL_HOUSE](dice.faces);
}
