#include "grade_school.h"

void init_roster(roster_t *roster)
{
  roster->student = malloc(sizeof(student_t) * MAX_STUDENTS;
  for (int i = 0; i < MAX_STUDENTS; i++)
  {
    roster->student[i].name = malloc(sizeof(char) * (MAX_NAME_LENGHT + 1);
  }
  roster->count = 0;
}

void add_student(roster_t *roster, char *name, int grade)
{
  sprintf(roster->student->name, "%s\0", name);
  roster->student->grade = grade;
  roster->count++;
}

roster_t get_grade(roster_t *roster, int grade)
{

}
