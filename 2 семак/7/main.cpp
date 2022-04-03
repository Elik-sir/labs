#include <iostream>
#include <malloc.h>
#include "lab.h"

/**
    Написать генератор псевдослучайных чисел по алгоритму
    r = r * 4231 + 12345 mod 100000. Подсчитать частоты попадания
    в каждый из интервалов длиной 10000 при выборке 500000.
 */

// преобразовать генератор так, чтобы числа были в диапазоне от 0 до 1 (и соотв статистика 10)
// зерно вводить с клавиатуры

int main()
{
    size_t seed;
    cout << "Input seed" << endl;
    cin >> seed;
    int arr[10] = {0};
    mysrand(seed);
    statistic(arr);
    printArrAdditional(arr);
    return 0;
}