#include "Penguin.h"
#include <cstdlib>
#include <cstring>
using namespace std;
Penguin::Penguin(const char *number, const char *name, int age) : Animal(number, name, age)
{
    this->paint();
    this->setProductMax(30);
    this->setSpeedProduction(5);
    char str1[] = "penguin";
    type = new char[strlen(str1) + 1];
    strcpy(type, str1);
}

Penguin::Penguin() : Animal()
{
    this->paint();
    this->setProductMax(30);
    this->setSpeedProduction(5);
    char str1[] = "penguin";
    type = new char[strlen(str1) + 1];
    strcpy(type, str1);
}

void Penguin::paint()
{
    this->bodyColor = 0;
}
char *Penguin::getType()
{
    return Penguin::type;
}
string Penguin::getTypeAnimal()
{
    return Penguin::type;
}
int Penguin::getBodyColor()
{
    return this->bodyColor;
}

void Penguin::setBodyColor(int color)
{
    this->bodyColor = color;
}

Penguin &Penguin::operator=(const Penguin &penguin)
{
    if (this != &penguin)
    {
        this->setName(penguin.getName());
        this->setAge(penguin.getAge());
        this->setNumber(penguin.getNumber());
        this->bodyColor = penguin.bodyColor;
    }

    return *this;
}

void Penguin::getInfo()
{
    cout << "  {\n   type: Penguin,\n"
         << "   name: " << getName() << "," << endl
         << "   number: " << getNumber() << "," << endl
         << "   age: " << getAge() << "," << endl
         << "   bodyColor: " << bodyColor << endl
         << "  }, " << endl;
}