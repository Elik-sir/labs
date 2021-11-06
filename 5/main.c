#include <stdio.h>
#include <malloc.h>

void relloc(char *prev, char *new)
{
    int i = 0;
    while (prev[i])
    {
        new[i] = prev[i];
        i++;
    }
}

int wordSize(char *string)
{

    int i = 0;
    while (string[i])
    {
        i++;
    }
    return i;
}

//Ввести строку и два слова. Вывести строку, в которой все вхождения первого слова  заменены на второе слово.
int main()
{
    char *string, *firstWord, *secondWord;
    char *resultString;
    int i = 0, lastSave = 0, wordPointer = 0;
    printf("Input string\n");
    scanf("%m[^\n]", &string);
    fflush(stdin);
    printf("Input word which need change\n");
    scanf("%m[^\n]", &firstWord);
    fflush(stdin);
    printf("Input word which will change first word\n");
    scanf("%m[^\n]", &secondWord);
    int firstWordSize = wordSize(firstWord);
    int secondWordSize = wordSize(secondWord);
    while (string[i])
    {
        if (firstWord[wordPointer] == string[i])
        {
            wordPointer++;
            if (firstWordSize == wordPointer)
            {
            }
        }
        else
        {
            wordPointer = 0;
        }
        i++;
    }
    return 0;
}
