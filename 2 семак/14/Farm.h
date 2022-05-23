#ifndef FarmClass
#define FarmClass
#include <iostream>
#include "Animal.h"
#include "Goose.h"
#include "Penguin.h"
#include "Ostrich.h"
#include <ctime>
using namespace std;
class Farm
{
private:
    Animal **animals;
    int countAnimals;
    int capacity;
    int sumPenguinProducts = 0;
    int sumOstrichProducts = 0;
    int sumGooseProducts = 0;

public:
    Farm();
    int addAnimal(Animal *animal);
    Animal **getAnimals();
    int getCountAnimals();
    void paintAll();
    void removeAnimal(const char *number);
    void showAllAnimals();
    int getSumPenguinProducts();
    int getSumOstrichProducts();
    int getSumGooseProducts();
    void setSumPenguinProducts(int count);
    void setSumOstrichProducts(int count);
    void setSumGooseProducts(int count);
    void addPenguinProducts(int count);
    void addOstrichProducts(int count);
    void addGooseProducts(int count);
    void collectAllProducts();
    void collectGooseProducts();
    void collectOstrichProducts();
    void collectPenguinProducts();
    void printProductionInfo();
    void clearProducts();
    char *getStr(const char *str);
    bool hasAnimal(char *number);
    ~Farm();
};

#endif