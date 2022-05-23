#ifndef PenguinClass
#define PenguinClass
#include <iostream>
#include "Animal.h"
using namespace std;
class Penguin : public Animal
{
private:
    int bodyColor;
    inline static char *type;

public:
    Penguin(const char *number, const char *name, int age);
    Penguin();
    int getBodyColor();
    void setBodyColor(int color);
    Penguin &operator=(const Penguin &penguin);
    void paint();
    void getInfo();

    char *getType();
    static string getTypeAnimal();
};
#endif