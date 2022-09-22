#include <iostream>
#include "Set_impl.h"
using namespace std;
int main()
{
    Set<int> a;
    a.insert(5);
    a.insert(6);
    a.insert(7);
    cout << a << endl;
    Set<int> b;
    b.insert(1);
    b.insert(123);
    cout << a.setUnion(b) << endl;
    return 0;
}