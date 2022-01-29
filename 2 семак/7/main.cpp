#include <iostream>
#include <malloc.h>

static size_t _seed = 1;
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
int main()
{
    int *arr = (int *)malloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++)
    {
        arr[i] = 0;
    }
    int a;
    for (int i = 0; i < 500; i++)
    {
        a = myrand();
        arr[a / 10000]++;
        cout << a << " ";
    }
    cout << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << "from " << i * 10000 << " to " << (i + 1) * 10000 << ": " << arr[i] << endl;
    }
    free(arr);
    return 0;
}