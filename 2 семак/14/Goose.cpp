#include "Goose.h"
#include <ctime>
#include <cstring>
Goose::Goose(const char *number, const char *name, int age) : Animal(number, name, age)
{
    srand(time(0));
    this->paint();
    this->setProductMax(10);
    this->setSpeedProduction(2);
    char str1[] = "goose";
    type = new char[strlen(str1) + 1];
    strcpy(type, str1);
}

Goose::Goose() : Animal()
{
    this->paint();
    this->setProductMax(10);
    this->setSpeedProduction(2);
    char str1[] = "goose";
    type = new char[strlen(str1) + 1];
    strcpy(type, str1);
}

Goose::Goose(const Goose &goose)
    : Goose(goose.getNumber(), goose.getName(), goose.getAge())
{
}

char *Goose::getType()
{
    return Goose::type;
}
char *Goose::getTypeAnimal()
{
    return Goose::type;
}
void Goose::paint()
{

    this->pawsColor = rand();
    do
    {
        this->wingsColor = rand();
    } while (this->wingsColor == pawsColor);
    do
    {
        this->bodyColor = rand();
    } while (this->bodyColor == this->pawsColor || this->bodyColor == this->wingsColor);
}

int Goose::getPawsColor()
{
    return this->pawsColor;
}

int Goose::getWingsColor()
{
    return this->wingsColor;
}

int Goose::getBodyColor()
{
    return this->bodyColor;
}

void Goose::setPawsColor(int color)
{
    this->pawsColor = color;
}
void Goose::setWingsColor(int color)
{
    this->wingsColor = color;
}

void Goose::setBodyColor(int color)
{
    this->bodyColor = color;
}

Goose &Goose::operator=(const Goose &goose)
{
    if (this != &goose)
    {
        this->setName(goose.getName());
        this->setAge(goose.getAge());
        this->setNumber(goose.getNumber());
        this->pawsColor = goose.pawsColor;
        this->wingsColor = goose.wingsColor;
        this->bodyColor = goose.bodyColor;
    }

    return *this;
}

void Goose::getInfo()
{
    cout << "  {\n   type: Goose\n"
         << "   name: " << getName() << "," << endl
         << "   number: " << getNumber() << "," << endl
         << "   age: " << getAge() << "," << endl
         << "   pawsColor: " << pawsColor << "," << endl
         << "   wingsColor: " << wingsColor << "," << endl
         << "   bodyColor: " << bodyColor << endl
         << "  },\n";
}