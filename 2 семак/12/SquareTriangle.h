#include <iostream>
#include <math.h>
#pragma once
struct Position
{
    double x;
    double y;
};

using namespace std;

class SquareTriangle
{

private:
    Position __A;
    Position __B;
    Position __C;
    void setA(Position A);
    void setB(Position B);
    void setC(Position C);
    double calcDistance(Position A, Position B);
    double pif(double a, double b);
    Position changeAngle(Position a);

public:
    SquareTriangle(Position A, Position B, Position C);
    Position getA();
    Position getB();
    Position getC();
    void scale(double s);
    void rotate();
    void miror();
};