#include <stdio.h>
#include <stdlib.h>

// Структуры

// Определение структуры
struct point {
  double x, y;
};

// Определение переменной типа "структура"
struct point p;

struct point p = {10, 20};

int main() {
  struct point p1 = {.x = 10, .y = 20};
  printf("%.1lf %.1lf\n", p1.x, p1.y);

  struct point *p = malloc(sizeof(*p));
  if (p == NULL) {
    return 1;
  }

  // Обращение к полям структуры
  // указатель->имя_поля

  p->x = 30; // (*p).x = 30;
  p->y = 40; // (*p).y = 40

  printf("%.1lf %.1lf\n", p->x, p->y);

  free(p);

  return 0;
}
