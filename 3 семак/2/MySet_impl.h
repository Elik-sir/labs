#include "MySet.h"

template <typename T>
MySet<T> MySet<T>::combine(const MySet<T> &s)
{
    MySet<T> tmp(s);
    tmp.insert(this->begin(), this->end());
    return tmp;
}

template <typename T>
MySet<T> MySet<T>::intersect(const MySet<T> &s)
{
    MySet<T> tmp;
    for (T const &e : *this)
    {
        if (s.find(e) != s.end())
        {
            tmp.insert(e);
        }
    }
    return tmp;
}

template <typename T>
MySet<T> MySet<T>::minus(const MySet<T> &s)
{
    MySet<T> tmp;
    for (T const &e : *this)
    {
        if (s.find(e) == s.end())
        {
            tmp.insert(e);
        }
    }
    return tmp;
}