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
        cout << "a\n";

        for (auto const &e : a)
        {
            std::cout << e << ' ';
        }
        cout << "\nb\n";
        for (auto const &e : b)
        {
            std::cout << e << ' ';
        }
        cout << "\nminus\n";
        for (auto const &e : a.minus(b))
        {
            std::cout << e << ' ';
        }
        cout << "\nintersect\n";
        for (auto const &e : a.intersect(b))
        {
            std::cout << e << ' ';
        }
        cout << "\ncombine\n";
        for (auto const &e : a.combine(b))
        {
            std::cout << e << ' ';
        }
        b.writeToFile("aaaa.txt");
        if (a.customFind(5))
        {
            cout << "eeeeeee" << endl;
        }
    }
    catch (invalid_argument &e)
    {
        cerr << e.what() << endl;
        exit(-1);
    }
    return 0;
}