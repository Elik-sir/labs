#ifndef lab
#define lab
#include <iostream>
#include <fstream>
using namespace std;
struct counter
{
    int multiline;
    int singleline;
};
string deleteComments(string str, int *counterSingleline, int *counterMultilineline);
counter readFiles(ifstream &f, ofstream &f2);
#endif