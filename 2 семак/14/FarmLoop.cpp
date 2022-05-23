#include "FarmLoop.h"
#include <chrono>
#include <time.h>
#include <thread>
FarmLoop::FarmLoop(Farm *farm)
{
    this->farm = farm;
}

void FarmLoop::run()
{
    using namespace std::this_thread;
    using namespace std::chrono;
    int hours = 0;
    int days = 0;
    Animal **animals = farm->getAnimals();
    while (true)
    {
        sleep_for(nanoseconds(1000000000));
        hours++;
        for (int i = 0; i < farm->getCountAnimals(); i++)
        {
            if (hours % 2 == 0)
            {
                if (animals[i]->getType() == Goose::getTypeAnimal())
                {
                    animals[i]->collectProducts();
                }
            }
            if (hours % 5 == 0)
            {
                if (animals[i]->getType() == Ostrich::getTypeAnimal())
                {
                    animals[i]->collectProducts();
                }
            }
            if (hours % 7 == 0)
            {
                if (animals[i]->getType() == Penguin::getTypeAnimal())
                {
                    animals[i]->collectProducts();
                }
            }
        }

        if (hours % 6 == 0)
        {
            farm->collectAllProducts();
            farm->printProductionInfo();
        }
        if (hours == 24)
        {
            hours = 0;
            days++;
        }
        if (days % 7 == 0)
        {
            farm->clearProducts();
        }
    }
}