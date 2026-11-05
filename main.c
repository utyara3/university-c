#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
  int id;
  int course;
  double score;
} Student;

void print_student(Student student);

int main(void) {
  Student *student = malloc(sizeof *student);
  if (student == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    return 1;
  }

  free(student);
  student = NULL;

  return 0;
}

void print_student(Student student) {
  printf("ID: %d, Course: %d, Score: %.2f\n", student.id, student.course,
         student.score);
}

void update_student(Student *student, int new_course, double new_score) {
  student->course = new_course;
  student->score = new_score;
}
