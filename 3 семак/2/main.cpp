#include <iostream>
#include "MySet_impl.h"
using namespace std;

int main()
{
    try
    {
        MySet<int> a;
        a.insert(1);
        a.insert(2);
        a.insert(3);
        a.insert(3111);
        MySet<int> b;
        b.insert(122);
        b.insert(233);
        b.insert(3111);
        b.insert(2);
        MySet<int> s;
        s = a.minus(b);
        for (auto const &e : s)
        {
            std::cout << e << ' ';
        }
    }
    catch (invalid_argument &e)
    {
        cerr << e.what() << endl;
        exit(-1);
    }
    return 0;
}