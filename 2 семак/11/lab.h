#ifndef lab
#define lab
#include <iostream>
#include <malloc.h>
using namespace std;
const int sizeS = 32;
static char *buffer = (char *)malloc(sizeS * 17 * sizeof(char));
static unsigned int reserved[sizeS] = {0};
void printArr();
char *palloc(int n);
char *prealloc(char *p, int n);
void pfree(char *p);
void defrag(char ***p, int countPointer);
void replace(int posTo, int posFrom);
void printBuf();
void initBuf();
#endif