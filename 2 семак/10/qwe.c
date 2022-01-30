#include <stdio.h>
//Написать функцию, которая переставляет элементы массива типа int так, что все положительные элементы предшествуют отрицательным.

void findNegativeAndSwap(int arrayLength, int *arr) // функция
{
    int temp = 0; /*Multiline     
    comment    qwe
        */
    char awe[] = "qwe//ewq";
    for /*asd*/ (int i = 0; i < arrayLength; i++) //цикл
    {
        if (arr[i] > 0)
        {
            for (int j = i + 1; j < arrayLength; j++)
            {
                if (arr[j] < 0)
                {
                    temp = arr[i];
                    /**/
                    /*
                        Коммент
                        йцу
                        йцу
                        фыв
                    */
                    arr[i] = arr[j]; //123123
                    arr[j] = temp;
                    /*qwe*/ break;
                }
            }
        }
    }
}

void qs(int *arr, int arrLength)
{
    int l = 0;
    int r = arrLength - 1;
    int j = arr[arrLength / 2];
    do
    {
        while (arr[l] > j)
        {
            l++;
        }
        while (arr[r] < j)
        {
            r--;
        }
        if (l <= r)
        {
            int temp;
            temp = arr[l];
            arr[l] = arr[r];
            arr[r] = temp;
            l++;
            r--;
        }
    } while (l <= r);
    if (r > 0)
    {
        qs(arr, r + 1);
    }
    if (arrLength > l)
    {
        qs(&arr[l], arrLength - l);
    }
}

int main()
{
    int arrayLength, temp = 0;
    printf("Input array length\n");
    scanf("%d", &arrayLength);
    int arr[arrayLength];
    for (int i = 0; i < arrayLength; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Input array: ");
    for (int i = 0; i < arrayLength; i++)
    {
        printf("%d\t", arr[i]);
    }
    // findNegativeAndSwap(arrayLength, arr);
    qs(arr, arrayLength);
    printf("\nOutput array: ");
    for (int i = 0; i < arrayLength; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    return 0;
}
// вынести в функцию

//сделать быструю сортировку
