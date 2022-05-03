#include <iostream>
#include "IntSet.h"
using namespace std;

int main()
{
    try
    {
        IntSet a;
        a = a + 2 + 22;

        a = a + 8 + 4 + 5;
        a += 0;
        a -= 2;
        a.printSet();
        IntSet b;
        b = a;
        b -= 4;
        b.printSet();
        a.printSet();
        a -= 8;
        b += 24;
        a += 33;
        b = b + 33;
        IntSet c;

        c = a * b;
        cout << "Product: " << endl;
        a.printSet();
        b.printSet();
        cout << "result: ";
        c.printSet();
        b = b - 22;
        a = a - 4;
        a.printSet();
        b.printSet();
        IntSet r;
        r = r + 22 + 5 + 0;
        if (a == r)
        {
            cout << "a equal r" << endl;
        }
        if (a != b)
        {
            cout << "a is not equal b" << endl;
        }
    }
    catch (invalid_argument &e)
    {
        cerr << e.what() << endl;
        exit(-1);
    }
    return 0;
}