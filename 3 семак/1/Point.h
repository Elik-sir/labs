#include <iostream>
using namespace std;
#pragma once
struct Point
{
    int x;
    int y;
    int z;
    bool operator==(const Point &point)
    {
        return x == point.x && y == point.y && z == point.z;
    }

    bool operator>(const Point &point) const
    {
        return (x * x + y * y + z * z) > (point.x * point.x + point.y * point.y + point.z * point.z);
    }
};
std::ostream &operator<<(ostream &os, Point p)
{
    os << "(" << p.x << "," << p.y << "," << p.z << ")" << endl;
    return os;
}