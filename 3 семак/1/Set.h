#ifndef Seth
#define Seth
#include <iostream>
#include <math.h>

using namespace std;
template <class T>
class Set
{
private:
    int __size;
    int capacity;
    T **__data;

public:
    Set();
    Set(const Set<T> &set);

    int size() const;
    bool find(const T &value);
    void insert(const T &value);
    void operator=(const Set<T> &set);
    Set<T> setUnion(const Set<T> &s);
    T **getData() const;
    ~Set();
};

template <class T>
std::ostream &operator<<(ostream &os, const Set<T> &p);
#endif
