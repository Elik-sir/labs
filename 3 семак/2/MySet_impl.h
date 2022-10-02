#include "MySet.h"
#include <iterator>
#include <fstream>
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

template <typename T>
bool MySet<T>::customFind(const T &s)
{
    int l = 0;
    int r = this->size() - 1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        set<int>::iterator itq;
        itq = this->begin();
        advance(itq, mid);
        if (*itq == s)
            return true;
        else if (*itq > s)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return false;
}

template <typename T>
void MySet<T>::writeToFile(string path)
{
    ofstream fileOut;
    fileOut.open(path);
    if (fileOut.is_open())
    {
        for (T const &e : *this)
        {
            fileOut << e << " ";
        }
        fileOut << "\n";
    }
    else
    {
        throw invalid_argument("file can not be open");
    }
    fileOut.close();
}