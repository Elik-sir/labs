#include "Farm.h"

Farm::Farm()
{
    this->animals = new Animal *[5];
    this->countAnimals = 0;
    this->capacity = 5;
}

void Farm::addAnimal(Animal *animal)
{
    if (countAnimals < capacity)
    {
        this->animals[countAnimals] = animal;
        countAnimals++;
        return;
    }
    Animal **temp = new Animal *[capacity * 2];
    for (int i = 0; i < countAnimals; i++)
    {
        temp[i] = animals[i];
    }
    capacity *= 2;
    delete[] animals;
    animals = temp;
}

void Farm::showAllAnimal()
{
    cout << "[" << endl;
    for (int i = 0; i < this->countAnimals; i++)
    {
        animals[i]->getInfo();
    }
    cout << "]" << endl;
}

void Farm::paintAll()
{
    for (int i = 0; i < this->countAnimals; i++)
    {
        animals[i]->paint();
    }
}

Farm::~Farm()
{
    for (int i = 0; i < capacity; i++)
    {
        delete animals[i];
    }
    delete[] animals;
}