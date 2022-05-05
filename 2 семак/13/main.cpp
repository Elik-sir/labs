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
        a = a + 2 + 3;
        a += 0;
        IntSet r;
        // r = r + 8 + 0;
        // a = a - r;
        IntSet b;
        b = a;

        // a.printSet();
        // a -= 8;
        // b += 24;
        // a += 323;
        // b = b + 33;
        IntSet c;
        // a.printSet();
        // b.printSet();
        a += 10;
        b += 7;
        b = b + 2 + 3 + 5 + 6;

        // c = a * b;
        a.printSet();
        b.printSet();
        Position *we = decardProduct(a, b);
        for (int i = 0; i < a.getSize() * b.getSize(); i++)
        {
            cout << "(" << we[i].x << "; " << we[i].y << ") ";
        }
        cout << endl;
        // c.printSet();
    }
    catch (invalid_argument &e)
    {
        cerr << e.what() << endl;
        exit(-1);
    }
    return 0;
}