#include <iostream>
#include <malloc.h>

using namespace std;

bool isOpenQuote = false;
int multiLine = -1;

char const *deleteComments(string str)
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
                return str.c_str();
            }
            if (str[i + 1] == '*')
            {
                multiLine = i;
            }
        }

        if (multiLine != -1 && str[i] == '*' && str[i + 1] == '/')
        {
            str.erase(multiLine, (i + 2) - multiLine);
            multiLine = -1;
        }
        i++;
    }

    if (multiLine != -1)
    {
        str.erase(multiLine, str.length());
    }
    return str.c_str();
}

void readFiles(FILE *f, FILE *f2)
{
    string str = "";
    char c;
    while (!feof(f))
    {
        c = fgetc(f);

        str += c;
        if (c == '\n' || c == '\0')
        {
            fputs(deleteComments(string(str)), f2);
            str = "";
        }
    }
}