#include <stdio.h>
void toUpperCase(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= ' ';
        }
        i++;
    }
}

int main()
{
    char *string;
    printf("Input string\n");
    scanf("%m[^\n]", &string);
    toUpperCase(string);
    printf("\n%s", string);
    return 0;
}