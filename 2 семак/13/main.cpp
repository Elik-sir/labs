#include <iostream>
#include "IntSet.h"
using namespace std;

int main()
{
    try
    {
        IntSet a(5);
        a = a + 2;
    }
    catch (invalid_argument &e)
    {
        cerr << e.what() << endl;
        exit(-1);
    }
    return 0;
}