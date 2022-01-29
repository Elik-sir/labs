#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

void exitIfNull(void *link, char *err_msg)
{
    if (link == NULL)
    {
        printf("%s", err_msg);
        exit(1);
    }
}

short isValidSymbol(const char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) ? 1 : 0;
}

void *newMem(int size)
{
    void *temp = malloc(size);
    exitIfNull(temp, "No memory!!!");
    return temp;
}

void *resizeMem(void *mem, int newSize)
{
    void *temp = realloc(mem, newSize);
    if (temp == NULL)
    {
        free(mem);
        exitIfNull(temp, "No memory!!!");
    }
    return temp;
}