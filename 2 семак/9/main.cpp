#include <iostream>
#include <malloc.h>
#include <cstdlib>
#include "lab.h"

using namespace std;

int main()
{
    int p1Size;
    int p2Size;
    cout << "Write degree p1: ";
    cin >> p1Size;
    p1Size++;
    int *p1 = getPolynom(p1Size);
    cout << "Write degree p2: ";
    cin >> p2Size;
    p2Size++;
    int *p2 = getPolynom(p2Size);
    int *q = dividePolynoms(p1, p2, p1Size - 1, p2Size - 1);

    cout << "q= ";
    printPolynom(q, p1Size - 1, "x");
    cout << "r= ";
    printPolynom(p1, p1Size - 1, "x");

    free(p1);
    free(p2);
    free(q);
    cout << endl;

    exit(1);
}