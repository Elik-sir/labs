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
