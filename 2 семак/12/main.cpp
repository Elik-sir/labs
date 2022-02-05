#include <iostream>
#include "SquareTriangle.h"
using namespace std;
int main()
{
    try
    {
        Position A = {x : 0, y : 0};
        Position B = {x : 0, y : 20};
        Position C = {x : 20, y : 0};
        SquareTriangle triangle(A, B, C);
    }
    catch (invalid_argument &e)
    {
        cerr << e.what() << endl;
        return -1;
    }
    return 0;
}