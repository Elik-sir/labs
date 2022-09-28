#include "Set.h"
using namespace std;
template <class T>
Set<T>::Set(const Set<T> &set)
{

    this->__size = set.__size;
    this->capacity = set.capacity;
    this->__data = new T *[set.capacity];
    for (int i = 0; i < this->__size; i++)
    {
        this->__data[i] = new T(*set.__data[i]);
    }
}

template <class T>
Set<T>::Set()
{
    this->__data = new T *[1];
    this->__size = 0;
    this->capacity = 1;
}

template <class T>
void Set<T>::insert(const T &value)
{
    if (find(value))
    {
        return;
    }
    int i;
    for (i = 0; i < this->__size && value > *__data[i]; i++)
    {
    }

    if (size() < capacity)
    {
        this->__size++;
        for (int j = this->__size; j > i; j--)
        {
            __data[j] = __data[j - 1];
        }
        __data[i] = new T(value);
    }
    else
    {
        capacity = capacity * 2;
        T **tmp = new T *[capacity];
        for (size_t k = 0; k < this->__size; k++)
        {
            tmp[k] = new T(*this->__data[k]);
        }
        __data = tmp;
        for (int j = this->size(); j > i; j--)
        {
            __data[j] = tmp[j - 1];
        }
        this->__size++;
        __data[i] = new T(value);
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
bool Set<T>::find(const T &value)
{
    for (int i = 0; i < this->size(); i++)
    {
        if (*this->__data[i] == value)
        {
            return true;
        }
    }
    return false;
}
template <class T>
T **Set<T>::getData() const
{

    return this->__data;
}

template <class T>
Set<T> Set<T>::setUnion(const Set<T> &s)
{
    Set<T> newSet(s);
    if (s.size() == 0 || this->size() == 0)
    {
        throw invalid_argument("You cant not union with void set");
    }
    for (int i = 0; i < this->size(); i++)
    {
        newSet.insert(*this->__data[i]);
    }
    return newSet;
}

template <class T>
std::ostream &operator<<(ostream &os, const Set<T> &p)
{
    for (int i = 0; i < p.size(); i++)
    {
        os << *p.getData()[i] << "  ";
    }

    return os;
}

template <class T>
Set<T>::~Set()
{
    delete[] __data;
}