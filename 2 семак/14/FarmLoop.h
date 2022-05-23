#ifndef FarmLoopClass
#define FarmLoopClass
#include <iostream>
#include "Farm.h"
using namespace std;
class FarmLoop
{
private:
    Farm *farm;

public:
    FarmLoop(Farm *farm);
    void run();
};

#endif