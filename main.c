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

Node *create_node(Student student);
bool append_node(Node **head, Student student);
bool remove_node(Node **head, int id);
void free_list(Node **head);

int main(void) {}

Node *create_node(Student student) {
  Node *new_node = malloc(sizeof *new_node);
  if (new_node == NULL) {
    return NULL;
  }

  new_node->data = student;
  new_node->next = NULL;

  return new_node;
}

bool append_node(Node **head, Student student) {
  Node *new_node = create_node(student);
  if (new_node == NULL) {
    return false;
  }

  if (*head == NULL) {
    (*head) = new_node;
  } else {
    Node *current = *head;
    while (current->next != NULL) {
      current = current->next;
    }

    current->next = new_node;
  }

  return true;
}

bool remove_node(Node **head, int id) {
  Node *current = *head;
  Node *previous = NULL;

  while (current != NULL && current->data.id != id) {
    previous = current;
    current = current->next;
  }

  if (current == NULL) {
    // Не нашли такую ноду
    return false;
  }

  if (current == *head) {
    *head = current->next;
  } else {
    previous->next = current->next;
  }

  free(current);

  return true;
}

void free_list(Node **head) {
  Node *current = *head;

  while (current != NULL) {
    Node *next = current->next;
    free(current);
    current = next;
  }

  *head = NULL;
}
