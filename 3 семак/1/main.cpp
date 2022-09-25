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
        cout << b.setUnion(a) << '\n';

        Set<Point> p1;

        p1.insert({x : 41, y : 4, z : 4});
        p1.insert({x : 1, y : 1, z : 1});
        p1.insert({x : 1, y : 1, z : 1});
        p1.insert({x : 2, y : 1, z : 3});
        p1.insert({x : 12, y : 2, z : 2});
        p1.insert({x : 4, y : 3, z : 2});
        p1.insert({x : 1004, y : 3, z : 2});
        p1.insert({x : 1003, y : 3, z : 2});

        cout << "p1: \n"
             << p1 << '\n';
        Set<Point> p2;
        p2.insert({x : 41, y : 4, z : 4});
        p2.insert({x : 1, y : 1, z : 1});
        p2.insert({x : 1, y : 1, z : 1});
        p2.insert({x : 3, y : 3, z : 3});
        cout << p1.setUnion(p2) << '\n';
        // Set<int> c;
        //  cout << b.setUnion(c) << endl;
    }
    catch (invalid_argument &e)
    {
        cerr << e.what() << endl;
        exit(-1);
    }
    return 0;
}