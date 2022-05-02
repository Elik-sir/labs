#include "IntSet.h"
using namespace std;

IntSet::IntSet(int num)
{
    this->data = (int *)malloc(1 * sizeof(int));
    this->size = 1;
    this->data[0] = num;
}
IntSet::IntSet()
{
    this->data = (int *)malloc(1 * sizeof(int));
    this->size = 0;
}

int *IntSet::operator+(int rhs)
{
    cout << this->data[0] << endl;
    size++;
    this->data = (int *)realloc(data, size * sizeof(int));
    data[size - 1] = rhs;

    return data;
}