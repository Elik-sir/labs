#include <iostream>
#include "SquareTriangle.h"
using namespace std;

// вывод
// отзеркаливание относительно оси абсцисс
// исключение в масштабировании
// пользователь задает точку, ты выводишь, где она относительно треугольника
int main()
{
    try
    {
        Position A = {x : 0, y : 0};
        Position B = {x : 0, y : 10};
        Position C = {x : 10, y : 0};
        SquareTriangle triangle(A, B, C);
        triangle.printPoints();
        cout << "Point: (" << -1 << "; " << 0 << ")" << endl;
        cout << triangle.detectPoint({x : -1, y : 0});
    }
    catch (invalid_argument &e)
    {
        cerr << e.what() << endl;
        exit(-1);
    }
    return 0;
}