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
        return countAnimals;
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
Animal **Farm::getAnimals()
{
    return this->animals;
}
int Farm::getCountAnimals()
{
    return this->countAnimals;
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

int Farm::getSumPenguinProducts()
{
    return this->sumPenguinProducts;
}
int Farm::getSumOstrichProducts()
{
    return this->sumOstrichProducts;
}
int Farm::getSumGooseProducts()
{
    return this->sumGooseProducts;
}
void Farm::setSumPenguinProducts(int count)
{
    this->sumPenguinProducts = count;
}
void Farm::setSumOstrichProducts(int count)
{
    this->sumOstrichProducts = count;
}
void Farm::setSumGooseProducts(int count)
{
    this->sumGooseProducts = count;
}

void Farm::collectAllProducts()
{
    for (int i = 0; i < this->countAnimals; i++)
    {

        if (animals[i]->getType() == Goose::getTypeAnimal())
        {
            this->addGooseProducts(animals[i]->getProductCount());
        }
        if (animals[i]->getType() == Ostrich::getTypeAnimal())
        {
            this->addOstrichProducts(animals[i]->getProductCount());
        }
        if (animals[i]->getType() == Penguin::getTypeAnimal())
        {
            this->addPenguinProducts(animals[i]->getProductCount());
        }
        animals[i]->setProductCount(0);
    }
}

void Farm::collectGooseProducts()
{
    for (int i = 0; i < this->countAnimals; i++)
    {
        if (animals[i]->getType() == Goose::getTypeAnimal())
        {
            this->addGooseProducts(animals[i]->getProductCount());
            animals[i]->setProductCount(0);
        }
    }
}

void Farm::collectOstrichProducts()
{
    for (int i = 0; i < this->countAnimals; i++)
    {
        if (animals[i]->getType() == Ostrich::getTypeAnimal())
        {
            this->addOstrichProducts(animals[i]->getProductCount());
            animals[i]->setProductCount(0);
        }
    }
}

void Farm::collectPenguinProducts()
{
    for (int i = 0; i < this->countAnimals; i++)
    {
        if (animals[i]->getType() == Penguin::getTypeAnimal())
        {
            this->addPenguinProducts(animals[i]->getProductCount());
            animals[i]->setProductCount(0);
        }
    }
}

void Farm::clearProducts()
{
    setSumPenguinProducts(0);
    setSumOstrichProducts(0);
    setSumGooseProducts(0);
}
void Farm::addPenguinProducts(int count)
{
    this->sumPenguinProducts += count;
}
void Farm::addOstrichProducts(int count)
{
    this->sumOstrichProducts += count;
}
void Farm::addGooseProducts(int count)
{
    this->sumGooseProducts += count;
}
void Farm::printProductionInfo()
{
    cout << "{\n  sumGooseProducts: " << sumGooseProducts << ",\n  sumOstrichProducts: " << sumOstrichProducts << ",\n  sumPenguinProducts: " << sumPenguinProducts << "\n},\n";
}

Farm::~Farm()
{
    for (int i = 0; i < capacity; i++)
    {
        delete animals[i];
    }
    delete[] animals;
}