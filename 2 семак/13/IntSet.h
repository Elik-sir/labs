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
    ~IntSet();
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
};

Position *decardProduct(const IntSet &a, const IntSet &b);