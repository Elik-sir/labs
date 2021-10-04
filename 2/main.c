#include <stdio.h>
int my_strlen(const char *s)
{
    const char *cur = s;
    for (; *cur; ++cur)
        ;
    return cur - s;
}
// Доделать чтобы разделителями считались всё кроме букв
int main()
{
    char *string;
    int c = 0;
    int word_length = 0;
    printf("Input string\n");
    scanf("%m[^\n]", &string);
    int num_char;
    for (int i = 0; i < my_strlen(string); i++)
    {
        num_char = (int)string[i];
        if ((num_char < 65 || num_char > 122) || (num_char > 90 && num_char < 97))
        {
            c++;
            continue;
        }
        if (c != 0)
        {
            printf(" %d\n", word_length);
            word_length = 0;
            c = 0;
        }
        word_length++;
        printf("%c", string[i]);
    }
    printf(" %d\n", word_length);
    return 0;
}
// Вывести у кажого слова его длину