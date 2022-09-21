#include "IntSet.h"
using namespace std;

IntSet::IntSet(const IntSet &set)
{

    this->size = set.size;
    this->data = new int[this->size];
    for (int i = 0; i < this->size; i++)
    {
        this->data[i] = set.data[i];
    }
}
IntSet::IntSet()
{
    this->data = new int[1];
    this->size = 0;
}

int *IntSet::getData() const
{
    return this->data;
}
int IntSet::getSize() const
{
    return this->size;
}
void IntSet::setData(int *data)
{
    this->data = data;
}
void IntSet::setSize(int size)
{
    this->size = size;
}

int IntSet::printSet()
{
    for (int i = 0; i < this->getSize(); i++)
    {
        cout << this->data[i] << "  ";
    }
    cout << endl;
    return this->getSize();
}

bool IntSet::hasInt(int num)
{
    for (int i = 0; i < this->getSize(); i++)
    {
        if (this->data[i] == num)
        {
            return true;
        }
    }
    return false;
}

IntSet IntSet::operator+(const int num)
{
    if (!this->hasInt(num))
    {
        this->size++;
        this->data = (int *)realloc(this->data, this->size * sizeof(int));
        this->data[this->size - 1] = num;
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
    IntSet tmp;
    tmp = *this;
    if (tmp.hasInt(num))
    {
        tmp.size--;
        int *data2 = (int *)malloc(tmp.size * sizeof(int));
        for (int i = 0, j = 0; i < tmp.size + 1; i++)
        {
            if (num != tmp.data[i])
            {
                data2[j] = tmp.data[i];
                j++;
            }
        }
        tmp.data = data2;
    }

    return tmp;
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
    if (set.size == this->size)
    {
        for (int i = 0; i < this->size; i++)
        {
            resultSet += set.data[i] * this->data[i];
        }

        return resultSet;
    }
    else
    {
        throw invalid_argument("Different sizes");
    }
}

void IntSet::operator=(const IntSet &set)
{
    delete[] this->data;
    this->size = set.size;
    this->data = new int[this->size];
    for (int i = 0; i < this->size; i++)
    {
        this->data[i] = set.data[i];
    }
}

bool IntSet::operator==(const IntSet &set)
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

bool IntSet::operator!=(const IntSet &set)
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

bool IntSet::operator>(const IntSet &set)
{
    return this->size > set.size;
}
bool IntSet::operator<(const IntSet &set)
{
    return this->size < set.size;
}
bool IntSet::operator>=(const IntSet &set)
{
    return this->size >= set.size;
}
bool IntSet::operator<=(const IntSet &set)
{
    return this->size <= set.size;
}

IntSet IntSet::operator+(const IntSet &set)
{
    IntSet tmp;
    tmp = *this;
    for (int i = 0; i < set.size; i++)
    {
        tmp += set.data[i];
    }
    return tmp;
}
IntSet IntSet::operator+=(const IntSet &set)
{
    for (int i = 0; i < set.size; i++)
    {
        *this += set.data[i];
    }
    return *this;
}
IntSet IntSet::operator-(const IntSet &set)
{
    IntSet tmp;
    tmp = *this;
    for (int i = 0; i < set.size; i++)
    {
        tmp -= set.data[i];
    }
    return tmp;
}
IntSet IntSet::operator-=(const IntSet &set)
{
    for (int i = 0; i < set.size; i++)
    {
        *this -= set.data[i];
    }
    return *this;
}

IntSet::~IntSet()
{
    delete[] data;
}

std::ostream &operator<<(ostream &os, const IntSet &p)
{
    for (int i = 0; i < p.getSize(); i++)
    {
        os << p.getData()[i] << "  ";
    }

    return os;
}
std::istream &operator>>(istream &in, IntSet &p)
{
    int num;
    in >> num;
    p += num;
    return in;
}

std::istream &operator>>(istream &in, int &a)
{
    int num;
    in >> num;
    a = num * num * num;
    return in;
}
// IntSet IntSet::operator*(IntSet set)
// {
//     IntSet resultSet;
//     if (set.size > this->size)
//     {
//         for (int i = 0; i < this->size; i++)
//         {
//             if (set.hasInt(this->data[i]))
//             {
//                 resultSet += this->data[i];
//             }
//         }

//         return resultSet;
//     }
//     else
//     {
//         for (int i = 0; i < set.size; i++)
//         {
//             if (this->hasInt(set.data[i]))
//             {
//                 resultSet += set.data[i];
//             }
//         }

//         return resultSet;
//     }
// }

Position *decardProduct(const IntSet &a, const IntSet &b)
{
    Position *res = (Position *)malloc(a.getSize() * b.getSize() * sizeof(Position));
    int *dataA = a.getData();
    int *dataB = b.getData();
    int count = 0;
    for (size_t i = 0; i < a.getSize(); i++)
    {
        for (size_t j = 0; j < b.getSize(); j++)
        {
            res[count].x = dataA[i];
            res[count].y = dataB[j];
            count++;
        }
    }
    return res;
}
