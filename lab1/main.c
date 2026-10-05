#include <stdio.h>

const int MAX_N = 100;

int main(void) {
    int n;

    /* Ввод и его обработка */
    printf("Введите количество элементов (1..100): ");
    if (scanf("%d", &n) != 1) {
        printf("Ожидалось целое число на вход.\n");
        return 1;
    }

    if (n < 1 || n > 100) {
        printf("Число не попадает в диапазон 1..100.\n");
        return 1;
    }

    int nums[MAX_N];

    printf("Введите элементы: ");
    for (int i = 0; i < n; i++) {
        if (scanf("%d", &nums[i]) != 1) {
            printf("Ожидалось целое число на вход.\n");
            return 1;
        }
    }

    /* Поиск отрицательных элементов и вычисление их произведения */
    int res = 1;
    int any_negative = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] < 0) {
            res *= nums[i];

            if (any_negative == 0) {
                any_negative = 1;
            }
        }
    }

    if (any_negative == 0) {
        printf("Отрицательных чисел не было введено.\n");
        return 1;
    }

    printf("Произведение отрицательных: %d\n", res);
    return 0;
}
