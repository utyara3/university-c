#include <stdio.h>
#include <stdlib.h>

// Объединения
// Структура данных, состоящая их нескольких именнованных полей,
// которые занимают одну и ту же область памяти
//
// union имя { типа_данных_1 имя_поля_1; тип_данных_2 имя_поля_2; }

// Одновременно можно работать только с одним полем объединения
// Используются для реалихации переменных типов данных или экономии пямяти

union variant {
  int as_int;
  double as_double;
};

int main(void) {
  union variant var;
  var.as_int = 10;

  printf("%d\n", var.as_int);
  var.as_double = 2.1;

  printf("%lf\n", var.as_double);
  printf("%d\n", var.as_int);

  return 0;
}
