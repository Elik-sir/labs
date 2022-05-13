#include <iostream>
#ifndef lab
#define lab
using namespace std;
struct Polynom
{
    int *q;
    int qSize;
    int *r;
    int rSize;
};
void printPolynom(int *pol, int size, string arg);
int *getPolynom(int size);
Polynom dividePolynoms(int *p1, int *p2, int n, int m);
int *convertFromStr(string p);
int countOne(int *p, int size);
#endif