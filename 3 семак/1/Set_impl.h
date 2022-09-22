#include "Set.h"
using namespace std;
template <class T>
Set<T>::Set(const Set<T> &set)
{

    this->__size = set.__size;
    this->capacity = set.capacity;
    this->__data = new T[set.capacity];
    for (int i = 0; i < this->__size; i++)
    {
        this->__data[i] = set.__data[i];
    }
}

template <class T>
Set<T>::Set()
{
    this->__data = new T[1];
    this->__size = 0;
    this->capacity = 1;
}

template <class T>
void Set<T>::insert(const T &value)
{
    if (this->__size < this->capacity)
    {
        __data[this->__size] = value;
        this->__size++;
    }
    else
    {
        this->capacity *= 2;
        __data = (T *)realloc(__data, sizeof(T) * capacity);
        __data[this->__size] = value;
        this->__size++;
    }
}

template <class T>
void Set<T>::operator=(const Set<T> &set)
{
    delete[] this->__data;
    this->__size = set.__size;
    this->__data = new T[this->size()];
    for (int i = 0; i < this->size(); i++)
    {
        this->__data[i] = set.__data[i];
    }
}

template <class T>
int Set<T>::size() const
{
    return this->__size;
}

template <class T>
bool Set<T>::find(const T &value) const
{
    for (int i = 0; i < this->size(); i++)
    {
        if (this->__data[i] == value)
        {
            return true;
        }
    }
    return false;
}
template <class T>
T *Set<T>::getData() const
{

    return this->__data;
}

template <class T>
Set<T> Set<T>::setUnion(const Set<T> &s)
{
    Set<T> newSet(s);

    for (int i = 0; i < this->size(); i++)
    {
        newSet.insert(this->__data[i]);
    }
    return newSet;
}

template <class T>
std::ostream &operator<<(ostream &os, const Set<T> &p)
{
    for (int i = 0; i < p.size(); i++)
    {
        os << p.getData()[i] << "  ";
    }

    return os;
}
