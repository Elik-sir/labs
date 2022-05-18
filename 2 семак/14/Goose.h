#pragma once
#include <iostream>
#include "Animal.h"
using namespace std;
class Goose : public Animal
{
private:
    int pawsColor;
    int wingsColor;
    int bodyColor;

public:
    Goose(string number, string name, int age);
    Goose(const Goose &goose);
    Goose();
    int getPawsColor();
    int getWingsColor();
    int getBodyColor();
    void setPawsColor(int color);
    void setWingsColor(int color);
    void setBodyColor(int color);
    void paint();
    void getInfo();
    Goose &operator=(const Goose &goose);
};