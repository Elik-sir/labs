#include <iostream>
#include "Set_impl.h"
using namespace std;
int main()
{
    try
    {
        Set<int> a;
        a.insert(8);
        a.insert(6);
        a.insert(7);
        a.insert(1);
        a.insert(-1114);
        cout << a << endl;
        Set<int> b;
        b.insert(1);
        b.insert(123);
        b.insert(-333);
        Set<int> c;
        cout << b.setUnion(c) << endl;
    }
    catch (invalid_argument &e)
    {
        cerr << e.what() << endl;
        exit(-1);
    }
    return 0;
}