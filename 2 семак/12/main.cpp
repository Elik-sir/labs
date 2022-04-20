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
        Position A = {x : 1, y : 1};
        Position B = {x : 1, y : 5};
        Position C = {x : 5, y : 1};
        SquareTriangle triangle(A, B, C);
        triangle.printPoints();
        triangle.scale(-1);
        cout << triangle.detectPoint({x : 1, y : 4});
    }
    catch (invalid_argument &e)
    {
        cerr << e.what() << endl;
        exit(-1);
    }
    return 0;
}