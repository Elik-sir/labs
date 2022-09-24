#include <iostream>
#include "Set_impl.h"
#include "Point.h"
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
        Set<Point> qw;
        qw.insert({x : 41, y : 4, z : 4});
        qw.insert({x : 1, y : 1, z : 1});
        qw.insert({x : 1, y : 1, z : 1});
        qw.insert({x : 2, y : 1, z : 3});
        qw.insert({x : 1002, y : 2, z : 2});
        qw.insert({x : 1002, y : 3, z : 2});
        cout << qw;
        // cout << b.setUnion(c) << endl;
    }
    catch (invalid_argument &e)
    {
        cerr << e.what() << endl;
        exit(-1);
    }
    return 0;
}