#include <iostream>
#include "Set_impl.h"
using namespace std;
int main()
{
    Set<int> a;
    a.insert(5);
    a.insert(6);
    a.insert(7);
    cout << a;
    Set<char> q;
    q.insert('a');
    q.insert('b');
    Set<char> qwe(q);
    qwe.insert('3');
    qwe = q;
    q.insert('1');
    cout << qwe << endl;
    cout << q;
    if (q.find('3'))
    {
        cout << "finded" << endl;
    }
    else
    {
        cout << "aaaaaaaaaaaaaaaaaa" << endl;
    }
    return 0;
}