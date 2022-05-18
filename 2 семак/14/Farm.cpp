#include "Farm.h"

Farm::Farm()
{
    this->animals = new Animal *[5];
    this->countAnimals = 0;
    this->capacity = 5;
}

bool Farm::hasAnimal(string number)
{
    for (int i = 0; i < countAnimals; i++)
    {
        if (animals[i]->getNumber() == number)
        {
            return true;
        }
    }
    return false;
}

/**
 * @brief
 *
 * @param animal
 * @return if animal was added then return index else -1
 */
int Farm::addAnimal(Animal *animal)
{
    if (hasAnimal(animal->getNumber()))
    {
        return -1;
    }
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
    temp[countAnimals] = animal;
    countAnimals++;
    capacity *= 2;
    delete[] animals;
    animals = temp;
    return countAnimals;
}

void Farm::showAllAnimals()
{
    cout << "[" << endl;
    for (int i = 0; i < this->countAnimals; i++)
    {
        animals[i]->getInfo();
    }
    cout << "]," << endl;
}

void Farm::paintAll()
{
    for (int i = 0; i < this->countAnimals; i++)
    {
        animals[i]->paint();
    }
}

void Farm::removeAnimal(string number)
{
    int pos = -1;
    for (int i = 0; i < countAnimals; i++)
    {
        if (animals[i]->getNumber() == number)
        {
            pos = i;
        }
    }

    if (pos < 0 || pos >= countAnimals)
    {
        throw invalid_argument("out of bound");
    }

    delete animals[pos];

    for (int i = pos; i < countAnimals - 1; i++)
    {
        animals[i] = animals[i + 1];
    }

    countAnimals--;
}

Farm::~Farm()
{
    for (int i = 0; i < capacity; i++)
    {
        delete animals[i];
    }
    delete[] animals;
}