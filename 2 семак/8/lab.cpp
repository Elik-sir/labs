#include <iostream>
#include <malloc.h>
#include <cstdlib>
#include <vector>

using namespace std;

bool isNumber(const string &str)
{
    return str.find_first_not_of("0123456789", str[0] == '-' ? 1 : 0) == string::npos;
}

int binarySearch(int *a, int size, int val)
{
    int l = 0, r = size - 1;

    while (r > l)
    {
        int m = (l + r) / 2; //целочисленное деление!

        if (a[m] < val)
        {
            l = m + 1;
        }
        else if (a[m] > val)
        {
            r = m - 1;
        }
        else
        {
            return m;
        }
    }
    if (a[l] == val)
    {
        return l;
    }

        return a[l];
}

void writeNums(vector<int> &nums)
{

    cout << "Enter number array" << endl;
    string input = "";

    do
    {
        getline(cin, input);

        if (input.length() == 0)
        {
            break;
        }

        if (!isNumber(input))
        {
            cout << "Oops, it was not a number. Please try again" << endl;
            continue;
        }

        nums.push_back(stoi(input));

    } while (cin);
}
