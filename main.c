#include <stdio.h>

typedef struct Student {
  int id;
  int course;
  double score;
} Student;

void print_student(Student student);

int main(void) {
  Student student = {.id = 123, .course = 3, .score = 4.85};
  print_student(student);

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
