#include <stdio.h>
int main(int argc, char *argv[])
{
    int a, b, c, result;

    printf("Input first number: ");
    if (scanf("%d", &a) != 1)
    {
        printf("You had to enter an int\n");
        return 1;
    }
    printf("Input second number: ");
    if (scanf("%d", &b) != 1)
    {
        printf("You had to enter an int\n");
        return 1;
    }
    printf("Input third number: ");
    if (scanf("%d", &c) != 1)
    {
        printf("You had to enter an int\n");
        return 1;
    }

    result = (a * b) % c;
    printf("Result: %d %% %d = %d\n", a * b, c, result);

    return 0;
}