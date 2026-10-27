#include <stdio.h>
#include <stdlib.h>

// Структуры

// Определение структуры
struct point {
  double x, y;
};

void swap_coords(struct point *p) {
  double buffer = p->x;
  p->x = p->y;
  p->y = buffer;
}

int main() {
  struct point p1 = {.x = 10, .y = 20};
  struct point p2 = p1;

  swap_coords(&p1);

  printf("%.1lf %.1lf\n", p1.x, p1.y);
  printf("%.1lf %.1lf\n", p2.x, p2.y);

  return 0;
}
