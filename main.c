#include <stdio.h>
#include <stdlib.h>

int main(void) {
  FILE *input = fopen("input.txt", "r");

  if (input == NULL) {
    fprintf(stderr, "Error: cannot open input.txt\n");
    return 1;
  }

  FILE *output = fopen("output.txt", "w");

  if (output == NULL) {
    fprintf(stderr, "Error: cannot open output.txt\n");
    fclose(input);
    return 1;
  }

  int n;

  if (fscanf(input, "%d", &n) != 1) {
    fprintf(stderr, "Error: invalid input\n");
    fclose(input);
    fclose(output);
    return 1;
  }

  fprintf(output, "Read number %d\n", n);

  fclose(input);
  fclose(output);

  return 0;
}
