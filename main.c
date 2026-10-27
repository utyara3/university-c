#include <stdio.h>
#include <stdlib.h>

// Структуры

// Определение неименованной структуры

struct {
  double x, y;
} p;

int main() {
  p.x = 10;
  p.y = 20;

  return 0;
}
