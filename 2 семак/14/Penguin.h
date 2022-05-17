#include <iostream>
#include "Animal.h"
using namespace std;
class Penguin : public Animal
{
private:
    int bodyColor;

public:
    Penguin(string number, string name, int age);
    Penguin();
    int getBodyColor();
    void setBodyColor(int color);
    Penguin &operator=(const Penguin &penguin);
    void paint();
    void getInfo();
};