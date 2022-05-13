#include <iostream>
#include "IntSet.h"
using namespace std;

// сеттеры, геттеры, конструкторы и деструкторы
// операторы перегрузить для объектов
// поточечное произведение для одинаковых; для разных - исключение кинуть
// декартово произведение. создать структуру
// принтсет возвращает кол-во выведенных элементов
// расставить const везде, где надо

int main()
{
    try
    {
        IntSet a;

        a = a + 7 + 5 + 0 + 321;
        IntSet b;
        // b = b + 2 + 5 + 6 + 7 + 32 + 33 + 0;
        b = b + 3 + 2 + 1;

        IntSet c;
        // c = a + b;
        // cin >> c >> c >> c;
        // cout << "C: " << c << endl;
        cout << "a = ";
        a.printSet();
        cout << "b = ";
        b.printSet();
        // if (a == b)
        // {
        //     cout << "Sets are equal" << endl;
        // }
        // cout << "a + b = ";
        // c = a + b;
        // c.printSet();
        // cout << "a - b = ";
        // c = a - b;
        // c.printSet();
        // cout << "a * b = ";
        // c = a * b;

        // c.printSet();
        Position *we = decardProduct(a, b);
        cout << "Deacard product" << endl;
        for (int i = 0; i < a.getSize() * b.getSize(); i++)
        {
            cout << "(" << we[i].x << "; " << we[i].y << ") ";
            if (i % 5 == 0)
            {
                cout << endl;
            }
        }
        cout << endl;
        c.printSet();
    }
    catch (invalid_argument &e)
    {
        cerr << e.what() << endl;
        exit(-1);
    }
    return 0;
}