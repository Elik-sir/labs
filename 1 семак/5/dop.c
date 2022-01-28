#include <stdio.h>
#include <malloc.h>

int predicat(int num)
{
    if (num % 2 == 0)
    {
        return 1;
    }
    return 0;
}

void *replaceIf(int *nums, int number, int (*predicat)(int num))
{

    int i = 0;

    while (nums[i])
    {
        if (predicat(nums[i]) == 1)
        {
            nums[i] = number;
        }
        i++;
    }
}

//Ввести строку и два слова. Вывести строку, в которой все вхождения первого слова  заменены на второе слово.
int main()
{
    int numsLength;
    printf("Input count nums\n");

    if (scanf("%d", &numsLength) != 1)
    {
        printf("\nneed input integer");
        return 1;
    };

    int *nums = (int *)malloc(numsLength * sizeof(int));
    for (int i = 0; i < numsLength; i++)
    {
        printf("\n%d : ", i + 1);
        if (scanf("%d", &nums[i]) != 1)
        {
            printf("\nneed input integer");
            return 1;
        }
    }

    replaceIf(nums, 100000, predicat);

    printf("\nresult:\n");
    int i = 0;
    while (i < numsLength)
    {
        printf("%d: %d \n", i + 1, nums[i]);
        i++;
    }

    free(nums);

    return 0;
}
