#include <iostream>
#include <math.h>
#pragma once

using namespace std;
struct Position
{
    int x;
    int y;
};

class IntSet
{
private:
    bool hasInt(int num);
    int *data;
    int size;

public:
    IntSet();
    IntSet(const IntSet &set);
    int *getData() const;
    int getSize() const;
    void setData(int *data);
    void setSize(int size);
    int printSet();
    IntSet operator+(const int num);
    IntSet operator+=(const int num);
    IntSet operator-(const int num);
    IntSet operator-=(const int num);
    IntSet operator+(const IntSet &set);
    IntSet operator+=(const IntSet &set);
    IntSet operator-(const IntSet &set);
    IntSet operator-=(const IntSet &set);
    IntSet operator*(IntSet set);
    void operator=(const IntSet &set);
    bool operator==(const IntSet &set);
    bool operator!=(const IntSet &set);
    bool operator>(const IntSet &set);
    bool operator<(const IntSet &set);
    bool operator>=(const IntSet &set);
    bool operator<=(const IntSet &set);
    ~IntSet();
};
class Vec
{
public:
    int a;
};
std::ostream &operator<<(ostream &os, const IntSet &p);
std::istream &operator>>(istream &os, IntSet &p);
std::istream &operator>>(istream &os, Vec &a);
Position *decardProduct(const IntSet &a, const IntSet &b);