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
    char *resultString = (char *)malloc(1 * sizeof(char));
    int i = 0, wordPointer = 0;
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
    int lengthResultString = 0;
    int countWord = 0;
    int lastSave = 0;
    int lastI = 0;
    while (string[i])
    {
        if (firstWord[wordPointer] == string[i])
        {
            wordPointer++;
            if (firstWordSize == wordPointer)
            {

                countWord++;
                lengthResultString = i + 1 - firstWordSize * countWord + secondWordSize * countWord;

                char *tmp = (char *)malloc(lengthResultString * sizeof(char));
                relloc(resultString, tmp);
                resultString = tmp;
                for (int j = lastSave; j < lengthResultString - secondWordSize; j++)
                {

                    resultString[j] = string[j];
                }
                for (int j = lengthResultString - secondWordSize, word = 0; j < lengthResultString + 1; j++, word++)
                {

                    resultString[j] = secondWord[word];
                }
                lastI = i;
                lastSave = lengthResultString;
            }
        }
        else
        {
            wordPointer = 0;
        }
        i++;
    }
    if (countWord)
    {

        if (lastI != i)
        {
            int a = i - lastI - 2;
            int b = lastSave;
            char *tmp = (char *)malloc((lengthResultString + a) * sizeof(char));
            relloc(resultString, tmp);
            resultString = tmp;
            for (int j = lastI + 1; j < i; j++)
            {
                resultString[b] = string[j];
                b++;
            }
        }
        printf("\n%s", &resultString[0]);
    }
    else
    {
        printf("\nthe first word doesnt contain in the string");
    }
    return 0;
}
