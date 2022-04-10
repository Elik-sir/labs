#include <iostream>
#include "SquareTriangle.h"
using namespace std;
int main()
{
    try
    {
        Position A = {x : 1, y : 1};
        Position B = {x : 1, y : 10};
        Position C = {x : 10, y : 1};
        SquareTriangle triangle(A, B, C);
        cout << triangle.getA().x << "   " << triangle.getA().y << endl;
        cout << triangle.getB().x << "   " << triangle.getB().y << endl;
        cout << triangle.getC().x << "   " << triangle.getC().y << endl;
        triangle.scale(2);
    }
    catch (invalid_argument &e)
    {
        cerr << e.what() << endl;
        exit(-1);
    }
    return 0;
}