#include <stdio.h>

// Пользовательские типы данных
enum direction {
  EAST,
  NORTH,
  WEST,
  SOUTH // 0, 1, 2, 3 - auto
};
enum day_of_week {
  MON = 1,
  TUE,
  WED,
  THU,
  FRI,
  SAT,
  SUN // 1, 2, ..., 7 - auto
};

int main() {
  enum direction dir = SOUTH;
  enum day_of_week day = TUE;

  printf("%d %d\n", dir, day); // 3 2
}
