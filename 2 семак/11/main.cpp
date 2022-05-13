#include <iostream>
#include "lab.h"

// дефрагментация
// при выводе выделять блоки
// prealloc

int main()
{
    char *a = (char *)palloc(5);
    char *b = (char *)palloc(3);
    char *c = (char *)palloc(2);
    char *e = (char *)palloc(2);

    for (int i = 0; i < (5 * 16); i++)
    {
        a[i] = '1';
    }
    for (int i = 0; i < (3 * 16) - 1; i++)
    {
        b[i] = '2';
    }
    for (int i = 0; i < (2 * 16) - 1; i++)
    {
        c[i] = '3';
    }
    for (int i = 0; i < (2 * 16) - 1; i++)
    {
        e[i] = '4';
    }
    cout << "init data: " << endl;
    printArr();
    printBuf();
    pfree(b);
    pfree(c);
    cout << "deleted 2 pointers: " << endl;
    printArr();

    char *r2 = NULL;
    if (r2 == NULL)
    {
        int countPoints = 2;
        char ***points = (char ***)malloc(countPoints * sizeof(char **));
        points[0] = &a;
        points[1] = &e;
        // points[2] = &d;
        defrag(points, countPoints);
        // r2 = (char *)palloc(9);
    }
    cout << "\nStatement memory after defrag: " << endl;
    printArr();
    cout << "\nData:" << endl;
    printBuf();
    //
    // cout << c << endl;
    cout << "\nprelloc first pointer: " << endl;
    e = prealloc(a, 7);
    printArr();
    printBuf();
    free(buffer);
    return 0;
}

// for (int i = 0; i < (7 * 16) - 1; i++)
// {
//     c[i] = '3';
// }
// for (int i = 0; i < (2 * 16) - 1; i++)
// {
//     e[i] = '4';
// }