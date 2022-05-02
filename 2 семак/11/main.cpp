#include <iostream>
#include "lab.h"

// дефрагментация
// при выводе выделять блоки
// prealloc

int main()
{
    initBuf();
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

    c[0] = '9';
    c[1] = '2';
    c[2] = '3';
    c[3] = '4';
    c[4] = '5';
    c[5] = '6';
    c[6] = 'A';
    char ***points = (char ***)malloc(3 * sizeof(char **));
    points[0] = &b;
    points[1] = &c;
    points[2] = &e;
    pfree(a);
    printArr();
    defrag(points, 3);
    printArr();
    printBuf();
    c = prealloc(c, 9);

    printBuf();
    cout << "C:" << (c) << endl;
    cout << "E: " << e << endl;
    printArr();

    printArr();
    for (int i = 0; i < (9 * 16); i++)
    {
        c[i] = '6';
    }
    points[2] = &c;
    points[1] = &e;
    defrag(points, 3);
    pfree(e);
    printArr();
    printBuf();
    // pfree(e);
    // printArr();
    free(buffer);
    return 0;
}