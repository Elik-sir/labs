#include <iostream>

static size_t _seed = 2;

using namespace std;

void mysrand(size_t seed)
{
    _seed = seed;
}

size_t myrand()
{
    static const size_t magic_number1 = 4231;
    static const size_t magic_number2 = 12345;
    _seed = (_seed * magic_number1 + magic_number2) % 100000;
    return _seed;
}

void printArr(int *arr)
{
    for (int i = 0; i < 10; i++)
    {
        cout << "from " << i * 10000 << " to " << (i + 1) * 10000 << ": " << arr[i] << endl;
    }
}

void statistic(int *arr)
{
    int a;
    for (int i = 0; i < 500000; i++)
    {
        a = myrand();
        arr[a / 10000]++;
        cout << a << " ";
    }
    cout << endl;
}