#ifndef PenguinClass
#define PenguinClass
#include <iostream>
#include "Animal.h"
using namespace std;
class Penguin : public Animal
{
private:
    int bodyColor;
    inline static string type;

public:
    Penguin(string number, string name, int age);
    Penguin();
    int getBodyColor();
    void setBodyColor(int color);
    Penguin &operator=(const Penguin &penguin);
    void paint();
    void getInfo();

    string getType();
    static string getTypeAnimal();
};
#endif