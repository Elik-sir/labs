#include "lab.h"
using namespace std;

bool isOpenQuote = false;
int multiLine = -1;

string deleteComments(string str, int *counterSingleline, int *counterMultilineline)
{
    int a = 0;
    int i = 0;
    if (multiLine != -1)
    {
        multiLine = 0;
    }
    while (i < str.length())
    {
        if (str[i] == '"')
        {
            isOpenQuote = !isOpenQuote;
        }
        if (!isOpenQuote && str[i] == '/')
        {
            if (str[i + 1] == '/')
            {
                str.erase(i, str.length() - i - 1);
                *counterSingleline = *counterSingleline + 1;
                return str;
            }
            if (str[i + 1] == '*')
            {
                multiLine = i;
            }
        }
        if (multiLine != -1 && str[i] == '*' && str[i + 1] == '/')
        {
            str.erase(multiLine, (i + 3) - multiLine);
            *counterMultilineline = *counterMultilineline + 1;
            multiLine = -1;
        }
        i++;
    }

    if (multiLine != -1)
    {
        str.erase(multiLine, str.length() + 1);
    }
    return str;
}

bool hasLetter(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t' && str[i] != '\0')
        {
            return true;
        }
    }
    return false;
}

counter readFiles(ifstream &f, ofstream &f2)
{
    string str = "";
    string resString = "";
    char c;
    int counterSingleline = 0;
    int counterMultilineline = 0;
    while (!f.eof())
    {
        f.get(c);
        str += c;
        if (c == '\n' || c == '\0')
        {
            resString = deleteComments(str, &counterSingleline, &counterMultilineline);
            if (hasLetter(resString))
            {
                // cout << resString << endl;
                f2 << resString;
            }

            resString = "";
            str = "";
        }
    }

    return {
        multiline : counterMultilineline,
        singleline : counterSingleline,
    };
}