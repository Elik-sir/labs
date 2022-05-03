#include <iostream>
#include <math.h>
#pragma once

using namespace std;

class IntSet
{
private:
    bool hasInt(int num);

public:
    int *data;
    int size;
    IntSet(int num);
    IntSet();
    void printSet();
    IntSet operator+(int num);
    IntSet operator*(IntSet set);
    IntSet operator+=(int num);
    IntSet operator-(int num);
    IntSet operator-=(int num);
    IntSet operator=(IntSet *set);
    bool operator==(IntSet set);
    bool operator!=(IntSet set);
    bool operator>(IntSet set);
    bool operator<(IntSet set);
    bool operator>=(IntSet set);
    bool operator<=(IntSet set);
};