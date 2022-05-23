#include "Ostrich.h"

Ostrich::Ostrich(string number, string name, int age, int pawsColor, int wingsColor) : Animal(number, name, age)
{
    this->pawsColor = pawsColor;
    this->wingsColor = wingsColor;
    this->setProductMax(20);
    this->setSpeedProduction(4);
    type = "ostrich";
}

Ostrich::Ostrich() : Animal()
{
    this->setProductMax(20);
    type = "ostrich";
    this->setSpeedProduction(4);
    // this->paint();
}

void Ostrich::paint()
{
    this->pawsColor = wingsColor;
}
string Ostrich::getType()
{
    return Ostrich::type;
}
string Ostrich::getTypeAnimal()
{
    return Ostrich::type;
}
int Ostrich::getPawsColor()
{
    return this->pawsColor;
}
int Ostrich::getWingsColor()
{
    return this->wingsColor;
}

void Ostrich::setPawsColor(int color)
{
    this->pawsColor = color;
}
void Ostrich::setWingsColor(int color)
{
    this->wingsColor = color;
}
Ostrich &Ostrich::operator=(const Ostrich &ostrich)
{
    if (this != &ostrich)
    {
        this->setNumber(ostrich.getNumber());
        this->setAge(ostrich.getAge());
        this->setName(ostrich.getName());
        this->pawsColor = ostrich.pawsColor;
        this->wingsColor = ostrich.wingsColor;
    }

    return *this;
}

void Ostrich::getInfo()
{
    cout << "  {\n   type: Ostrich\n"
         << "   name: " << getName() << "," << endl
         << "   number: " << getNumber() << "," << endl
         << "   age: " << getAge() << "," << endl
         << "   pawsColor: " << pawsColor << "," << endl
         << "   wingsColor: " << wingsColor << endl
         << "  },\n";
}