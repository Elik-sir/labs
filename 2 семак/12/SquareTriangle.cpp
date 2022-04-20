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
    if (s < 0)
    {
        throw invalid_argument("Negative number cannot scale triangle");
    }
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
void SquareTriangle::mirorX()
{
    Position a = this->getA();
    Position b = this->getB();
    Position c = this->getC();
    setA({x : a.x, y : -a.y});
    setB({x : b.x, y : -b.y});
    setC({x : c.x, y : -c.y});
}

void SquareTriangle::printPoints()
{
    cout << "A: (" << this->getA().x << ", " << this->getA().y << ")" << endl;
    cout << "B: (" << this->getB().x << ", " << this->getB().y << ")" << endl;
    cout << "C: (" << this->getC().x << ", " << this->getC().y << ")" << endl;
}

string SquareTriangle::detectPoint(Position k)
{
    Position a = this->getA();
    Position b = this->getB();
    Position c = this->getC();
    double a1 = (a.x - k.x) * (b.y - a.y) - (b.x - a.x) * (a.y - k.x);
    double b1 = (b.x - k.x) * (c.y - b.y) - (c.x - b.x) * (b.y - k.y);
    double c1 = (c.x - k.x) * (a.y - c.y) - (a.x - c.x) * (c.y - k.y);
    string res = "outside";
    if ((abs(a1) < 0.001) && (((b1 <= 0) && (c1 <= 0)) || ((b1 >= 0) && (c1 >= 0))))
    {
        res = "on boundary";
    }
    if ((abs(b1) < 0.001) && (((a1 <= 0) && (c1 <= 0)) || ((a1 >= 0) && (c1 >= 0))))
    {
        res = "on boundary";
    }
    if ((abs(c1) < 0.001) && (((a1 <= 0) && (b1 <= 0)) || ((a1 >= 0) && (b1 >= 0))))
    {
        res = "on boundary";
    }
    if ((a1 >= 0) && (b1 >= 0) && (c1 >= 0) || ((a1 < 0) && (b1 < 0) && (c1 < 0)))
    {
        return "inside";
    }
    return res;
}