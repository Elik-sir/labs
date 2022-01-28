#include <stdio.h>
#include <malloc.h>

int wordSize(char *string)
{

    int i = 0;
    while (string[i])
    {
        i++;
    }
    return i;
}

void relloc(char *prev, char *new)
{
    int i = 0;
    while (prev[i])
    {
        new[i] = prev[i];
        i++;
    }
}
void rellocPoint(char **prev, char **new, int countWords)
{
    int i = 0;
    while (i < countWords)
    {
        new[i] = prev[i];
        i++;
    }
}
int isSeparator(char letter)
{
    if (letter >= 'A' && letter <= 'Z' || letter >= 'a' && letter <= 'z')
    {
        return 0;
    }
    return 1;
}
char **split(char *string)
{
    char **resultString = (char **)malloc(sizeof(char *));
    int i = 0, j = 0, countWords = 0, a = 0;
    char *string2 = (char *)malloc(1 * sizeof(char));
    while (string[i] != '\0')
    {
        if (isSeparator(string[i]) == 0)
        {
            char *tmp = (char *)malloc((j + 1) * sizeof(char));
            relloc(string2, tmp);
            string2 = tmp;
            string2[j] = string[i];
            j++;
        }

        if ((isSeparator(string[i]) == 1) || string[i + 1] == '\0')
        {
            if (j > 0)
            {
                j = 0;
                char **tmp = (char **)malloc((countWords + 1) * sizeof(char *));
                rellocPoint(resultString, tmp, countWords + 1);
                resultString = tmp;
                resultString[countWords] = string2;
                string2 = (char *)malloc(1 * sizeof(char));
                countWords++;
            }
            char **tmp = (char **)malloc((countWords + 1) * sizeof(char *));
            rellocPoint(resultString, tmp, countWords + 1);
            resultString = tmp;
            resultString[countWords] = malloc(sizeof(char));
            resultString[countWords][0] = string[i];
            resultString[countWords][1] = '\0';
            countWords++;
        }

        i++;
    }
    return resultString;
}
int isEqual(char *string, char *word)
{
    int i = 0;
    while (word[i])
    {
        if (word[i] != string[i])
        {
            return 0;
        }
        i++;
    }

    return 1;
}
//Ввести строку и два слова. Вывести строку, в которой все вхождения первого слова  заменены на второе слово.
int main()
{
    char *string, *firstWord, *secondWord;
    int i = 0, wordPointer = 0;
    printf("Input string\n");
    scanf("%m[^\n]", &string);
    fflush(stdin);
    printf("Write word which need change\n");
    scanf("%m[^\n]", &firstWord);
    fflush(stdin);
    printf("Write word which will change the first word\n");
    scanf("%m[^\n]", &secondWord);
    int firstWordSize = wordSize(firstWord);
    int secondWordSize = wordSize(secondWord);

    char **res = split(string);
    while (res[i])
    {
        if (isEqual(res[i], firstWord) == 1)
        {
            res[i] = secondWord;
        }
        printf("%s", res[i]);
        i++;
    }
    return 0;
}
