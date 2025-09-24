#include "grade_school.h"
#include <string.h>
#include <stdlib.h>

void init_roster(roster_t *roster)
{
  roster->count = 0;
}

void sort_list(roster_t *roster)
{
  for (size_t i = 0; i < roster->count; i++)
  {
    for (size_t j = 0; j < roster->count - 1; j++)
    {
      if ((roster->students[j].grade > roster->students[j + 1].grade) || (roster->students[j].grade == roster->students[j + 1].grade && strcmp(roster->students[j].name, roster->students[j + 1].name) > 0))
      {
        student_t tmp = roster->students[j + 1];
        roster->students[j + 1] = roster->students[j];
        roster->students[j] = tmp;
      }
    }
  }
}

int add_student(roster_t *roster, char *name, int grade)
{
  for (size_t i = 0; i < roster->count; i++)
  {
    if (strcmp(name, roster->students[i].name) == 0)
      return 0;
  }
  strncpy(roster->students[roster->count].name, name, MAX_NAME_LENGTH - 1);
  roster->students->name[MAX_NAME_LENGTH - 1] = '\0';
  roster->students[roster->count].grade = grade;
  roster->count++;
  sort_list(roster);
  return roster->count;
}

roster_t get_grade(roster_t *roster, int grade)
{
  int idx = 0;
  roster_t res;
  init_roster(&res);
  for (size_t i = 0; i < roster->count; i++)
  {
    if (roster->students[i].grade == grade)
    {
      res.students[idx] = roster->students[i];
      res.students[idx].grade = grade;
      res.count++;
      idx++;
    }
  }
  return res;
}
