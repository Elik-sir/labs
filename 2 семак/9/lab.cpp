#include <iostream>
#include <malloc.h>
#include <cstdlib>
#include <string>
#include "lab.h"
using namespace std;

void printPolynom(int *pol, int size, string arg)
{
    int i = size - 1;
    while (pol[i] == 0)
    {
        i--;
    }
    if (i < 0)
    {
        return;
    }
    cout << pol[i] << arg << "^" << i;
    i--;
    for (; i >= 0; i--)
    {
        if (pol[i] == 0)
        {
            continue;
        }
        cout << " + " << pol[i] << arg << "^" << i;
    }
    cout << endl;
}

int *getPolynom(int size)
{
    int *p = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
    a:
        cout << "write coef " << i << "th degree: ";
        cin >> p[i];
        if (p[i] != 0 && p[i] != 1)
        {
            cout << "coef should be 0 or 1, please try again" << endl;
            goto a;
        }
    }

    return p;
}

int *dividePolynoms(int *p1, int *p2, int n, int m)
{
    int *q = (int *)malloc(sizeof(int) * (n + 1));
    while (p2[m] == 0)
    {
        m--;
    }
    while (n >= m)
    {
        q[n - m] = (p1[n] / p2[m]) % 2;
        for (int j = n, i = 0; j >= n - m; j--, i++)
        {
            p1[j] = (p1[j] - q[n - m] * p2[m - i]) % 2;
        }
        n--;
    }
    return q;
}