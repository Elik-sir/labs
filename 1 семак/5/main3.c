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
char *relloc(char *prev, int newLength)
{
    char *new = (char *)malloc(newLength * sizeof(char));
    int i = 0;
    while (prev[i])
    {
        new[i] = prev[i];
        i++;
    }
    free(prev);
    return new;
}
int resultWordSize(char *string, char *firstWord, int secondWordSize)
{
    int firstWordSize = wordSize(firstWord);
    int j = 0, i = 0, wordPointer = 0, resultPoint = 0;
    while (string[i] != '\0')
    {
        if (string[i] == firstWord[j])
        {
            wordPointer = i;
            while (string[i] == firstWord[j] && string[i] != '\0')
            {
                i++;
                j++;
            }

            if (j == firstWordSize)
            {
                resultPoint += secondWordSize;
            }
            else
            {
                resultPoint += i - wordPointer;
            }
            i--;
            j = 0;
        }
        else
        {
            resultPoint++;
        }
        i++;
    }
    return resultPoint;
}

char *replaceAll(char *string, char *firstWord, char *secondWord)
{
    const int stringSize = wordSize(string),
              firstWordSize = wordSize(firstWord),
              secondWordSize = wordSize(secondWord);
    int j = 0, i = 0, wordPointer = 0, resultPoint = 0;
    int resultWordLength = resultWordSize(string, firstWord, secondWordSize);
    char *result = (char *)malloc(resultWordLength * sizeof(char));

    while (string[i] != '\0')
    {

        if (string[i] == firstWord[j])
        {
            wordPointer = i;
            while (string[i] == firstWord[j] && string[i] != '\0')
            {
                i++;
                j++;
            }
            if (j == firstWordSize)
            {
                j = 0;
                while (j < secondWordSize)
                {
                    result[resultPoint] = secondWord[j];
                    resultPoint++;
                    j++;
                }
                i--;
            }
            else
            {
                while (wordPointer <= i)
                {
                    result[resultPoint] = string[wordPointer];
                    wordPointer++;
                    resultPoint++;
                }
            }

            j = 0;
        }
        else
        {
            result[resultPoint] = string[i];
            resultPoint++;
        }
        i++;
    }
    result[resultWordLength] = '\0';

    return result;
}
char *get_string()
{
    int len = 0;                            // изначально строка пуста
    int capacity = 1;                       // ёмкость контейнера динамической строки (1, так как точно будет '\0')
    char *s = (char *)malloc(sizeof(char)); // динамическая пустая строка

    char c = getchar(); // символ для чтения данных

    // читаем символы, пока не получим символ переноса строки (\n)
    while (c != '\n')
    {
        s[len++] = c; // заносим в строку новый символ

        // если реальный размер больше размера контейнера, то увеличим его размер
        if (len >= capacity)
        {
            capacity *= 2;                   // увеличиваем ёмкость строки в два раза
            s = (char *)relloc(s, capacity); // создаём новую строку с увеличенной ёмкостью
        }

        c = getchar(); // считываем следующий символ
    }

    s[len] = '\0'; // завершаем строку символом конца строки

    return s; // возвращаем указатель на считанную строку
}
int callback(void)
{
    return 1;
}
char *replaceIf(char *string, char *firstWord, char *secondWord, int (*callback)(void))
{
    const int stringSize = wordSize(string),
              firstWordSize = wordSize(firstWord),
              secondWordSize = wordSize(secondWord);
    int j = 0, i = 0, wordPointer = 0, resultPoint = 0;
    int resultWordLength = resultWordSize(string, firstWord, secondWordSize);
    char *result = (char *)malloc(resultWordLength * sizeof(char));

    while (string[i] != '\0')
    {

        if (string[i] == firstWord[j])
        {
            wordPointer = i;
            while (string[i] == firstWord[j] && string[i] != '\0')
            {
                i++;
                j++;
            }
            if (callback())
            {
                j = 0;
                while (j < secondWordSize)
                {
                    result[resultPoint] = secondWord[j];
                    resultPoint++;
                    j++;
                }
                i--;
            }
            else
            {
                while (wordPointer <= i)
                {
                    result[resultPoint] = string[wordPointer];
                    wordPointer++;
                    resultPoint++;
                }
            }

            j = 0;
        }
        else
        {
            result[resultPoint] = string[i];
            resultPoint++;
        }
        i++;
    }
    result[resultWordLength] = '\0';

    return result;
}
//Ввести строку и два слова. Вывести строку, в которой все вхождения первого слова  заменены на второе слово.
int main()
{
    printf("Input initial string\n");
    char *string = get_string();
    printf("Input first word\n");
    char *firstWord = get_string();
    printf("Input second word\n");
    char *secondWord = get_string();
    printf("\n%s", replaceAll(string, firstWord, secondWord));
    free(string);
    free(firstWord);
    free(secondWord);
    return 0;
}
