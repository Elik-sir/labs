#include <iostream>

static size_t _seed = 2;

using namespace std;

void mysrand(size_t seed)
{
    _seed = seed;
}

float myrand()
{
    static const int magic_number1 = 4231;
    static const int magic_number2 = 12345;
    _seed = (_seed * magic_number1 + magic_number2) % 100000;
    return _seed / 99999.0f;
}

void printArr(int *arr)
{
    for (int i = 0; i < 10; i++)
    {
        cout << "from " << i * 10000 << " to " << (i + 1) * 10000 << ": " << arr[i] << endl;
    }
}
void printArrAdditional(int *arr)
{
    for (int i = 0; i < 10; i++)
    {
        cout << "from " << i * 0.1 << " to " << (i + 1) * 0.1 << ": " << arr[i] << endl;
    }
}

void statistic(int *arr)
{
    for (int i = 0; i < 500000; i++)
    {
        arr[(int)(myrand() * 10)]++;
    }
    cout << endl;
}