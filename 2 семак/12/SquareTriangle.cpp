#include "SquareTriangle.h"
using namespace std;

SquareTriangle::SquareTriangle(Position A, Position B, Position C)
{
    double AB = calcDistance(A, B);
    double AC = calcDistance(A, C);
    double BC = calcDistance(B, C);
    if (AB == pif(AC, BC) || AC == pif(AB, BC) || BC == pif(AB, AC))
    {
        setA(A);
        setB(B);
        setC(C);
    }
    else
    {
        throw invalid_argument("Triangle is not square");
    }
}

void SquareTriangle::setA(Position A)
{
    this->__A = A;
}
void SquareTriangle::setB(Position B)
{
    this->__B = B;
}
void SquareTriangle::setC(Position C)
{
    this->__C = C;
}
double SquareTriangle::calcDistance(Position A, Position B)
{
    return sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
}
double SquareTriangle::pif(double a, double b)
{
    return sqrt(pow(a, 2) + pow(b, 2));
}

Position SquareTriangle::getA()
{
    return this->__A;
}
Position SquareTriangle::getB()
{
    return this->__B;
}
Position SquareTriangle::getC()
{
    return this->__C;
}

void SquareTriangle::scale(double s)
{
    Position a = this->getA();
    Position b = this->getB();
    Position c = this->getC();
    double const range = s * this->pif(a.x, a.y);
    double fi = atan(a.y / a.x);
    setA({x : range * cos(fi), y : range * sin(fi)});
    fi = atan(b.y / b.x);
    setB({x : range * cos(fi), y : range * sin(fi)});
    fi = atan(c.y / c.x);
    setC({x : range * cos(fi), y : range * sin(fi)});
}
void SquareTriangle::rotate()
{
    Position a = this->getA();
    Position b = this->getB();
    Position c = this->getC();
    double const range = this->pif(a.x, a.y);
    double fi = atan(a.y / a.x) + 90;
    setA({x : range * cos(fi), y : range * sin(fi)});
    fi = atan(b.y / b.x) + 90;
    setB({x : range * cos(fi), y : range * sin(fi)});
    fi = atan(c.y / c.x) + 90;
    setC({x : range * cos(fi), y : range * sin(fi)});
}
void SquareTriangle::miror()
{
    Position a = this->getA();
    Position b = this->getB();
    Position c = this->getC();
    setA({x : -a.x, y : a.y});
    setB({x : -b.x, y : b.y});
    setC({x : -c.x, y : c.y});
}