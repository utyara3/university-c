#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
  int id;
  int course;
  double score;
} Student;

typedef struct Node {
  Student data;
  struct Node *next;
} Node;

FILE *open_file(char filename[], const char *mode);
Node *create_node(Student student);
bool *append_node(Node **head, Student student);

int main(void) {
  Node *head = NULL;

  FILE *input = open_file("input.txt", "r");
  FILE *output = open_file("output", "w");

  int N;
  if (fscanf(input, "%d", &N) != 1) {
    fprintf(stderr, "record count not found\n");
    return 1;
  }

  for (int i = 0; i < N; i++) {
    Student s;
    if (fscanf(input, "%d %d %lf", &s.id, &s.course, &s.score) != 3) {
      fprintf(stderr, "error while parsing string. check your data.\n");
      return 1;
    }

    bool is_node_appended = append_node(&head, s);
    if (!is_node_appended) {
      fprintf(stderr,
              "error while appending node (memory allocation error).\n");
      return 1;
    }
  }

  fclose(input);
  fclose(output);
  return 0;
}

FILE *open_file(char filename[], const char *mode) {
  FILE *file = fopen(filename, mode);
  if (file == NULL) {
    fprintf(stderr, "Cannot open file '%s' on mode '%s'!\n", filename, mode);
    exit(EXIT_FAILURE);
  }

  return file;
}

Node *create_node(Student student) {
  Node *new_node = malloc(sizeof *new_node);
  if (new_node == NULL) {
    return NULL;
  }

  new_node->data = student;
  new_node->next = NULL;

  return new_node;
}

bool *append_node(Node **head, Student student) {
  Node *new_node = create_node(student);
  if (new_node == NULL) {
    return false;
  }

  if (*head == NULL) {
    *head = new_node;
  } else {
    Node *current = *head;

    while (current->next != NULL) {
      current = current->next;
    }

    current->next = new_node;
  }

  return true;
}
