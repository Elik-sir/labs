#pragma once
#include <iostream>
#include "Animal.h"
using namespace std;
class Ostrich : public Animal
{
private:
    int pawsColor;
    int wingsColor;

public:
    Ostrich(string number, string name, int age, int pawsColor, int wingsColor);
    Ostrich();
    int getPawsColor();
    int getWingsColor();
    int getBodyColor();
    void setPawsColor(int color);
    void setWingsColor(int color);
    void paint();
    Ostrich &operator=(const Ostrich &ostrich);
    void getInfo();
};