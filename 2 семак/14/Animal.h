#ifndef AnimalClass
#define AnimalClass
#include <iostream>
using namespace std;
class Animal
{
private:
    string number;
    string name;

    int productCount;
    int productMax;
    int speedProduction;
    int age;

public:
    Animal(string number, string name, int age);
    Animal();
    string getNumber() const;
    string getName() const;
    int getAge() const;
    void setNumber(string _number);
    void setName(string _name);
    void setAge(int _age);
    int getProductCount() const;
    int getProductMax() const;
    int getSpeedProduction() const;
    void collectProducts();
    void setProductCount(int count);
    void setProductMax(int count);
    void setSpeedProduction(int speed);
    void printProductionInfo();
    virtual string getType() = 0;
    virtual void paint() = 0;
    virtual void getInfo();
};
#endif