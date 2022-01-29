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
                str.erase(i);
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

int main()
{
    char *str = (char *)malloc(250 * sizeof(char));
    FILE *f = fopen("qwe.c", "r");
    FILE *f2 = fopen("qwe2.c", "w");
    if (f != NULL)
    {

        while (!feof(f))
        {
            if (fgets(str, 250, f))
            {

                fputs(deleteComments(string(str)), f2);
            }
        }
    }
    else
    {
        cout << "Error";
    }
    fclose(f);
    fclose(f2);
    return 0;
}