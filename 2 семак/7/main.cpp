#include <iostream>
#include <malloc.h>
#include "lab.h"

/**
    Написать генератор псевдослучайных чисел по алгоритму
    r = r * 4231 + 12345 mod 100000. Подсчитать частоты попадания
    в каждый из интервалов длиной 10000 при выборке 500000.
 */
int main()
{
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        arr[i] = 0;
    }
    statistic(arr);
    printArr(arr);
    return 0;
}