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
    char *e = (char *)palloc(2);
    for (int i = 0; i < (6 * 16) - 1; i++)
    {
        b[i] = '1';
    }

    for (int i = 0; i < (7 * 16) - 1; i++)
    {
        c[i] = '8';
    }
    for (int i = 0; i < (2 * 16) - 1; i++)
    {
        e[i] = '2';
    }

    pfree(b);
    printArr();
    int countPoints = 3;
    char *r2 = (char *)palloc(13);
    if (r2 == NULL)
    {
        char ***points = (char ***)malloc(countPoints * sizeof(char **));
        points[0] = &a;
        points[1] = &c;
        points[2] = &e;
        defrag(points, countPoints);
        r2 = (char *)palloc(13);
    }

    printArr();
    printBuf();
    cout << c << endl;
    e = prealloc(e, 3);
    printArr();
    free(buffer);
    return 0;
}