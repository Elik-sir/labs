#pragma once
#include <iostream>
using namespace std;
class Animal
{
private:
    string number;
    string name;
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
    virtual void paint() = 0;
    virtual void getInfo();
};