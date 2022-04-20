#include <stdio.h>

void findNegativeAndSwap(int arrayLength, int *arr)
{
    int temp = 0;
    char awe[] = "qwe//ewq";
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

    qs(arr, arrayLength);
    printf("\nOutput array: ");
    for (int i = 0; i < arrayLength; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    return 0;
}
