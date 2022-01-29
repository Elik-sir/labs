#include <iostream>
#include <malloc.h>
#include <cstdlib>
#include <vector>
#include "lab.h"

using namespace std;

int main()
{
    vector<int> nums;

    writeNums(nums);
    qsort(&nums.at(0), nums.size(), sizeof(int), [](const void *x1, const void *x2)
          { return (*(int *)x1 - *(int *)x2); });

    cout << "Input  search number: ";
    int searchNumber;
    cin >> searchNumber;
    if (cin)
    {
        for (int i = 0; i < nums.size(); i++)
            cout << nums[i] << " ";

        cout << endl
             << "Nearest number: "
             << binarySearch(&nums.at(0), nums.size(), searchNumber);
        nums.clear();
        return 0;
    }
    cerr << "It was not a number";
    nums.clear();
    exit(1);
}