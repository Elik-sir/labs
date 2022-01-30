#include <iostream>
#include <malloc.h>
#include "lab.h"
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