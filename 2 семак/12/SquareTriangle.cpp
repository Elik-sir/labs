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
    setA({x : s * a.x, y : s * a.y});
    setB({x : s * b.x, y : s * b.y});
    setC({x : s * c.x, y : s * c.y});
}
void SquareTriangle::rotate()
{
    Position a = this->getA();
    Position b = this->getB();
    Position c = this->getC();
    setA({x : -a.y, y : a.x});
    setB({x : -b.y, y : b.x});
    setC({x : -c.y, y : c.x});
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