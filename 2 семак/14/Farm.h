#include <iostream>
#include "Animal.h"
using namespace std;
class Farm
{
private:
    Animal **animals;
    int countAnimals;
    int capacity;

public:
    Farm();
    void addAnimal(Animal *animal);
    void paintAll();
    // removeAnimal();
    void showAllAnimal();
    ~Farm();
};