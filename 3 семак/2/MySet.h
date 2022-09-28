
#ifndef MySeth
#define MySeth
#include <iostream>
#include <set>

using namespace std;
template <typename T>
class MySet : public set<T>
{
public:
    // Set();
    // Set(const Set<T> &set);
    MySet<T> combine(const MySet<T> &s);
    MySet<T> intersect(const MySet<T> &s);
    MySet<T> minus(const MySet<T> &s);
    //~Set();
};
#endif
