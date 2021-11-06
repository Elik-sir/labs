#include <stdio.h>
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
    int arr[] = {1, 7, 2, 0, 7, 0, 7, 0};
    qs(arr, 8);
    for (int i = 0; i < 8; i++)
    {
        printf("%d \t", arr[i]);
    }
    return 0;
}