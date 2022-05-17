#include "Animal.h"

Animal::Animal(string number, string name, int age)
{
    this->setName(name);
    this->setNumber(number);
    this->setAge(age);
}

Animal::Animal()
{
    this->setName("noname");
    this->setNumber("empty");
    this->setAge(0);
}

string Animal::getNumber() const
{
    return this->number;
}

string Animal::getName() const
{
    return this->name;
}

int Animal::getAge() const
{
    return this->age;
}

void Animal::setNumber(string _number)
{
    if (_number.empty())
    {
        throw invalid_argument("number is empty");
    }
    this->number = _number;
}

void Animal::setName(string _name)
{
    if (_name.empty())
    {
        throw invalid_argument("name is empty");
    }
    this->name = _name;
}

void Animal::setAge(int _age)
{
    if (_age < 0)
    {
        throw invalid_argument("negative age");
    }
    this->age = _age;
}
void Animal::getInfo()
{
    cout << "name: " << getName() << endl
         << "number: " << getNumber() << endl
         << "age: " << getAge() << endl;
}