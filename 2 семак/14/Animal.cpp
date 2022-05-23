#include "Animal.h"
#include <cstring>
// char *getStr(char *str)
// {
//     int i = 0;
//     while (str[i] != '\0')
//     {
//         i++;
//     }
//     char *newStr = (char *)malloc(sizeof(char) * i);
//     for (int i = 0; i < i; i++)
//     {
//         newStr[i] = str[i];
//     }
//     return newStr;
// }

char *getStr(const char *str)
{
    char *newStr = (char *)malloc(sizeof(char) * (strlen(str) + 1));
    if (newStr == NULL)
    {
        exit(1);
    }
    strcpy(newStr, str);
    return newStr;
}

Animal::Animal(const char *number, const char *name, int age)
{
    this->setName(getStr(name));
    this->setNumber(getStr(number));
    this->setAge(age);
    this->setProductCount(0);
}

Animal::Animal()
{
    char *noname = new char[7];
    noname[0] = 'n';
    noname[1] = 'o';
    noname[2] = 'n';
    noname[3] = 'a';
    noname[5] = 'm';
    noname[6] = 'e';
    noname[7] = '\0';
    this->setName(noname);
    this->setNumber(noname);
    this->setAge(0);
    this->setProductCount(0);
}

char *Animal::getNumber() const
{
    return this->number;
}

char *Animal::getName() const
{
    return this->name;
}

int Animal::getAge() const
{
    return this->age;
}
int Animal::getProductCount() const
{
    return this->productCount;
}
int Animal::getProductMax() const
{
    return this->productMax;
}

int Animal::getSpeedProduction() const
{
    return this->speedProduction;
}

void Animal::collectProducts()
{
    if (productCount < productMax)
    {
        productCount += speedProduction;
        if (productCount > productMax)
        {
            productCount = productMax;
        }
    }
}
void Animal::setProductCount(int count)
{
    if (count < 0)
    {
        throw invalid_argument("number is negative");
    }
    this->productCount = count;
}
void Animal::setProductMax(int count)
{
    if (count < 0)
    {
        throw invalid_argument("number is negative");
    }
    this->productMax = count;
}

void Animal::setSpeedProduction(int speed)
{
    if (speed < 0)
    {
        throw invalid_argument("speed can not  negative");
    }
    this->speedProduction = speed;
}

void Animal::setNumber(char *_number)
{
    if (_number == NULL)
    {
        throw invalid_argument("number is empty");
    }
    this->number = _number;
}

void Animal::setName(char *_name)
{
    if (_name == NULL)
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

void Animal::printProductionInfo()
{
    if (productCount == productMax)
    {
        cout << "\nThe maximum amount of product has been reached\n";
        return;
    }
    cout << "\nProduction storage is full on " << ((productCount / (float)productMax) * 100) << "% The maximum amount of product will have been reached in " << (productMax - productCount) / speedProduction << " conventional unit\n";
}