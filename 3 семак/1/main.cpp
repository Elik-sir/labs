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
        Set<Point> p1;
        cout << "p1:\n";
        p1.insert({x : 41, y : 4, z : 4});
        p1.insert({x : 1, y : 1, z : 1});
        p1.insert({x : 1, y : 1, z : 1});
        p1.insert({x : 2, y : 1, z : 3});
        p1.insert({x : 1002, y : 2, z : 2});
        p1.insert({x : 1002, y : 3, z : 2});
        Set<Point> p2;
        cout << p1 << "p2:\n";
        p2.insert({x : 3, y : 1, z : 3});
        p2.insert({x : 1004, y : 2, z : 2});
        p2.insert({x : 1002, y : 3, z : 2});
        cout << p2 << "\nunion p2 and p1: \n";
        cout << p1.setUnion(p2);
        // cout << b.setUnion(c) << endl;
    }
    catch (invalid_argument &e)
    {
        cerr << e.what() << endl;
        exit(-1);
    }
    return 0;
}