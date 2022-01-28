#include <stdio.h>
#include <malloc.h>

int hasLetter(char letter, char *letters)
{
    int i = 0;
    while (letters[i] != '\0')
    {

        if (letters[i] == letter)
        {
            return 1;
        }
        i++;
    }
    return 0;
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

char *unicLetters(char *word)
{
    char *letters = "\0";
    int i = 0;
    int j = 0;
    char *newLetter;
    while (word[i] != '\0')
    {
        if (word[i] != ' ' && hasLetter(word[i], letters) == 0)
        {
            newLetter = (char *)malloc(j * sizeof(char));
            relloc(letters, newLetter);
            letters = newLetter;
            letters[j] = word[i];
            j++;
        }
        i++;
    }
    return letters;
}

int main()
{
    char *string, *word;
    printf("Input string\n");
    scanf("%m[^\n]", &string);
    fflush(stdin);
    printf("Input word\n");
    scanf("%m[^\n]", &word);
    char *letters = unicLetters(word);
    int i = 0;
    int count = 0;
    while (letters[i] != '\0')
    {
        int j = 0;
        while (string[j] != '\0')
        {
            if (letters[i] == string[j])
            {
                count++;
            }
            j++;
        }
        i++;
    }
    printf("\nCount: %d", count);
    return 0;
}

// добавить разные разделител
// Строка все маленькие гласные будут заменяться на заглавные