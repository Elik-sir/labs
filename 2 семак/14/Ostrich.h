#ifndef OstrichClass
#define OstrichClass
#include <iostream>
#include "Animal.h"
using namespace std;
class Ostrich : public Animal
{
private:
    int pawsColor;
    int wingsColor;
    inline static char *type;

public:
    Ostrich(const char *number, const char *name, int age, int pawsColor, int wingsColor);
    Ostrich();
    int getPawsColor();
    int getWingsColor();
    int getBodyColor();
    void setPawsColor(int color);
    void setWingsColor(int color);
    void paint();
    char *getType();
    static string getTypeAnimal();
    Ostrich &operator=(const Ostrich &ostrich);
    void getInfo();
};
#endif