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
    int addAnimal(Animal *animal);
    void paintAll();
    void removeAnimal(string number);
    void showAllAnimals();
    bool hasAnimal(string number);
    ~Farm();
};
