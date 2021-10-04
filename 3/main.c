#include <stdio.h>
//Написать функцию, которая переставляет элементы массива типа int так, что все положительные элементы предшествуют отрицательным.
int main()
{
    int arrayLength, temp = 0;
    printf("Input count array length\n");
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

    for (int i = 0; i < arrayLength; i++)
    {

        if (arr[i] > 0)
        {
            for (int j = i + 1; j < arrayLength; j++)
            {
                if (arr[j] < 0)
                {
                    temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                    break;
                }
            }
        }
    }

    printf("\nOutput array: ");
    for (int i = 0; i < arrayLength; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    return 0;
}