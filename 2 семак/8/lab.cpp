#include <iostream>
#include <malloc.h>
#include <cstdlib>
#include <string>
using namespace std;

bool isNumber(const string &str)
{
    return str.find_first_not_of("0123456789", str[0] == '-' ? 1 : 0) == string::npos;
}

int binarySearch(int *a, int size, int val)
{

    int r = size - 1;
    int l = 0;

    int mid = 0;

    if (a[r] < val)
    {
        return a[r];
    }
    if (a[l] > val)
    {
        return a[l];
    }
    int target;
    while (l <= r)
    {
        mid = (l + r) >> 1;

        if (a[mid] > val)
        {
            r = mid - 1;
        }
        else if (a[mid] < val)
        {
            target = mid;
            l = mid + 1;
        }
        else
        {
            return a[l];
        }
    }
    if (a[target] != val)
    {
        return val - a[target] < a[target + 1] - val ? a[target] : a[target + 1];
    }
    return a[target];
}

int *append(int *nums, int num, int size)
{
    nums = (int *)realloc(nums, size);
    nums[size - 1] = num;
    return nums;
}

void writeNums(int *nums, int *size)
{
    cout << "Enter number array" << endl;
    string input;

    while (cin)
    {
        getline(cin, input, '\n');
        if (input == "")
        {
            break;
        }
        *size = *size + 1;
        nums = append(nums, stoi(input), *size);
    };
}
