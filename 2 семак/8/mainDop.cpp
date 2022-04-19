#include <iostream>
#include <iterator>
#include <malloc.h>
#include <cstdlib>
#include <list>
#include <string>
#include "lab.h"

using namespace std;

int main()
{
    string str;
    string needWord;
    string *tmp = new string();

    cout << "Write str" << endl;
    getline(cin, str, '\n');
    wordsList words = getWords(str);

    for (int i = 0; i < words.size - 1; i++)
    {
        for (int j = i + 1; j < words.size; j++)
        {
            if (*words.data[i] > *words.data[j])
            {
                tmp = words.data[i];
                words.data[i] = words.data[j];
                words.data[j] = tmp;
            }
        }
    }

    cout << "Write word which need find" << endl;
    getline(cin, needWord, '\n');

    cout << "Closest word: " << getNearestWord(words, needWord) << endl;
    for (int i = 0; i < words.size; i++)
    {
        cout << *words.data[i] << endl;
    }

    for (int i = 0; i < words.size; i++)
    {
        free(words.data[i]);
    }
    free(words.data);
    return 0;
}