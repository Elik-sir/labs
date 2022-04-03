#include <iostream>
#include <malloc.h>
#include <cstdlib>
#include <vector>
#include "lab.h"

using namespace std;

int main()
{
    // vector<int> nums;
    int *nums = (int *)malloc(5 * sizeof(int));
    int size = 0;
    writeNums(nums, &size);
    qsort(nums, size, sizeof(int), [](const void *x1, const void *x2)
          { return (*(int *)x1 - *(int *)x2); });

    cout << "Input  search number: ";
    int searchNumber;
    cin >> searchNumber;
    if (cin)
    {
        for (int i = 0; i < size; i++)
            cout << nums[i] << " ";

        cout << endl
             << "Nearest number: "
             << binarySearch(nums, size, searchNumber);
        free(nums);
        return 0;
    }
    cerr << "It was not a number";
    free(nums);
    exit(1);
}