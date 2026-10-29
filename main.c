#include <stdio.h>
#include <stdlib.h>

int main() {
  int n;

  if (scanf("%d", &n) != 1 & n <= 0) {
    printf("you have to type a positive number\n");
    return 1;
  }

  int *p = malloc(n * sizeof *p);
  if (p == NULL) {
    return 1;
  }

  for (int i = 0; i < n; i++) {
    p[i] = i + 1;
  }

  for (int i = 0; i < n; i++) {
    printf("%d ", p[i]);
  }

  printf("\n");

  free(p);
  return 0;
}
