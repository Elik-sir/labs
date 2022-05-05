#include <iostream>
#ifndef lab
#define lab
using namespace std;
struct wordsList
{
    string **data;
    int size;
};
bool isNumber(const string &str);
int binarySearch(int *a, int size, int val);
#endif