#include <iostream>
#include <malloc.h>
#include <cstdlib>
#include <string>
#include "lab.h"
using namespace std;
/*
1)сортировка списка слов в лексикографическом порядке(возрастание/убывание)
2)поиск самого близкого слова к этому(по количеству совпадающих букв/буквосочетаний)
*/
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
            return a[mid];
        }
    }
    if (a[target] != val)
    {
        return abs(val - a[target]) < abs(val - a[target + 1]) ? a[target] : a[target + 1];
    }
    return a[target];
}

int *append(int *nums, int num, int size)
{
    nums = (int *)realloc(nums, size * sizeof(int));
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
        if (!isNumber(input))
        {
            cout << "It is not a number, try again" << endl;
            continue;
        }
        *size = *size + 1;

        nums = append(nums, stoi(input), *size);
    };
}

/*!!!!!!Функции к допу!!!!!!*/

bool isLetter(char letter)
{

    return (letter >= 'A' && letter <= 'Z') || (letter >= 'a' && letter <= 'z');
}

string **appendStr(string **words, string *word, int size)
{

    words = (string **)realloc(words, size * sizeof(string *));
    if (words == NULL)
    {
        cout << "OOPS";
        exit(1);
    }

    words[size - 1] = word;

    return words;
}

wordsList getWords(string str)
{
    string *str2 = new string("");
    string **words = (string **)malloc(sizeof(string *));
    int size = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (isLetter(str[i]))
        {
            *str2 += str[i];
        }
        else
        {
            if (!str2->empty())
            {
                size++;
                words = appendStr(words, str2, size);
                str2 = new string("");
            }
        }
    }
    if (!str2->empty())
    {
        size++;
        words = appendStr(words, str2, size);
        str2 = new string("");
    }
    return {data : words, size : size};
}

string getNearestWord(wordsList words, string word)
{
    int nearestWordId = 0;
    int maxCountSuchLetters = 128;
    int countSuchLetters = 0;
    int startPos = 0;
    int hasWord = 0;
    for (int i = 0; i < words.size; i++)
    {
        startPos = words.data[i]->find(word);
        if (startPos != word.npos)
        {
            countSuchLetters = words.data[i]->length() - (startPos + word.length());
            if (countSuchLetters < maxCountSuchLetters)
            {
                maxCountSuchLetters = countSuchLetters;
                nearestWordId = i;
            }
            hasWord++;
        }
    }
    if (hasWord != 0)
    {
        return *words.data[nearestWordId];
    }
    return "";
}