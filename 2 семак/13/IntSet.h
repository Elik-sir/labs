#include <iostream>
#include <math.h>
#pragma once

using namespace std;

class IntSet
{
private:
public:
    int *data;
    int size;
    IntSet(int num);
    IntSet();
    int *operator+(int rhs);
};