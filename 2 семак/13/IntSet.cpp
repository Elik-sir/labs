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

void IntSet::printSet()
{
    for (int i = 0; i < this->size; i++)
    {
        cout << this->data[i] << "  ";
    }
    cout << endl;
}

bool IntSet::hasInt(int num)
{
    for (int i = 0; i < this->size; i++)
    {
        if (this->data[i] == num)
        {
            return true;
        }
    }
    return false;
}

IntSet IntSet::operator+(int num)
{
    if (!this->hasInt(num))
    {
        size++;
        data = (int *)realloc(this->data, size * sizeof(int));
        data[size - 1] = num;
    }

    return *this;
}
IntSet IntSet::operator+=(int num)
{
    if (!this->hasInt(num))
    {
        size++;
        data = (int *)realloc(this->data, size * sizeof(int));
        data[size - 1] = num;
    }

    return *this;
}

IntSet IntSet::operator-(int num)
{
    if (this->hasInt(num))
    {
        size--;
        int *data2 = (int *)malloc(size * sizeof(int));
        for (int i = 0, j = 0; i < size + 1; i++)
        {
            if (num != data[i])
            {
                data2[j] = data[i];
                j++;
            }
        }
        data = data2;
    }

    return *this;
}
IntSet IntSet::operator-=(int num)
{
    if (this->hasInt(num))
    {
        size--;
        int *data2 = (int *)malloc(size * sizeof(int));
        for (int i = 0, j = 0; i < size + 1; i++)
        {
            if (num != data[i])
            {
                data2[j] = data[i];
                j++;
            }
        }
        data = data2;
    }

    return *this;
}

IntSet IntSet::operator*(IntSet set)
{
    IntSet resultSet;
    if (set.size > this->size)
    {
        for (int i = 0; i < this->size; i++)
        {
            if (set.hasInt(this->data[i]))
            {
                resultSet += this->data[i];
            }
        }

        return resultSet;
    }
    else
    {
        for (int i = 0; i < set.size; i++)
        {
            if (this->hasInt(set.data[i]))
            {
                resultSet += set.data[i];
            }
        }

        return resultSet;
    }
}

IntSet IntSet::operator=(IntSet *set)
{
    // delete[] this->data;
    IntSet tmp;
    tmp.size = set->size;
    tmp.data = (int *)malloc(set->size * sizeof(int));
    for (int i = 0; i < tmp.size; i++)
    {
        tmp.data[i] = set->data[i];
    }

    return tmp;
}

bool IntSet::operator==(IntSet set)
{
    if (set.size == this->size)
    {
        for (int i = 0; i < set.size; i++)
        {
            if (!this->hasInt(set.data[i]))
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

bool IntSet::operator!=(IntSet set)
{
    if (set.size != this->size)
    {
        for (int i = 0; i < set.size; i++)
        {
            if (!this->hasInt(set.data[i]))
            {
                return true;
            }
        }
        return false;
    }
    return false;
}
bool IntSet::operator>(IntSet set)
{
    return this->size > set.size;
}
bool IntSet::operator<(IntSet set)
{
    return this->size < set.size;
}
bool IntSet::operator>=(IntSet set)
{
    return this->size >= set.size;
}
bool IntSet::operator<=(IntSet set)
{
    return this->size <= set.size;
}