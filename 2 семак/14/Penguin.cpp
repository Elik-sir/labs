#include "Penguin.h"
#include <cstdlib>
using namespace std;
Penguin::Penguin(string number, string name, int age) : Animal(number, name, age)
{
    this->paint();
}

Penguin::Penguin() : Animal()
{
    this->paint();
}

void Penguin::paint()
{
    this->bodyColor = 0;
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
    cout << "{\n   type: Penguin,\n"
         << "   name: " << getName() << "," << endl
         << "   number: " << getNumber() << "," << endl
         << "   age: " << getAge() << "," << endl
         << "   bodyColor: " << bodyColor << endl
         << "}, " << endl;
}