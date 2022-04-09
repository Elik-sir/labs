#include <iostream>
#ifndef lab
#define lab
using namespace std;
struct wordsList
{
    string **data;
    int size;
};
bool isNumber(const string &str);
int binarySearch(int *a, int size, int val);
void writeNums(int *nums, int *size);
bool isLetter(char letter);
string **appendStr(string **words, string *word, int size);
wordsList getWords(string str);
string getNearestWord(wordsList words, string word);
#endif