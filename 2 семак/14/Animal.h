#ifndef AnimalClass
#define AnimalClass
#include <iostream>
using namespace std;
class Animal
{
private:
    char *number;
    char *name;

    int productCount;
    int productMax;
    int speedProduction;
    int age;

public:
    Animal(const char *number, const char *name, int age);
    Animal();
    char *getNumber() const;
    char *getName() const;
    int getAge() const;
    void setNumber(char *_number);
    void setName(char *_name);
    void setAge(int _age);
    int getProductCount() const;
    int getProductMax() const;
    int getSpeedProduction() const;
    void collectProducts();
    void setProductCount(int count);
    void setProductMax(int count);
    void setSpeedProduction(int speed);
    void printProductionInfo();
    virtual char *getType() = 0;
    virtual void paint() = 0;
    virtual void getInfo();
};
#endif