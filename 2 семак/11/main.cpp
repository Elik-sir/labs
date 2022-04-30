#include <iostream>
#include "lab.h"

// дефрагментация
// при выводе выделять блоки
// prealloc

int main()
{
    char *a = (char *)palloc(5);
    char *b = (char *)palloc(6);
    char *c = (char *)palloc(7);
    for (int i = 0; i < (6 * 16) - 1; i++)
    {
        b[i] = '1';
    }

    for (int i = 0; i < (7 * 16) - 1; i++)
    {
        c[i] = '8';
    }

    c[0] = '9';
    c[1] = '2';
    c[2] = '3';
    c[3] = '4';
    c[4] = '5';
    c[5] = '6';
    c[6] = 'A';
    char ***points = (char ***)malloc(2 * sizeof(char **));
    points[0] = &b;
    points[1] = &c;
    pfree(a);
    // defrag(points, 2);
    c = prealloc(c, 8);
    for (int i = 0; i < (8 * 16) - 1; i++)
    {
        c[i] = '9';
    }
    printArr();
    defrag(points, 2);
    printArr();
    printBuf();
    free(buffer);
    return 0;
}