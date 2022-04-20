#include <iostream>
#include "lab.h"

// использовать fstream
// убирать лишние пустые строчки
// счетчики удаленных комментариев по типам
// разобраться с const во всех возможных случаях и поставить, где надо

int main()
{

    FILE *f = fopen("qwe.c", "r");
    FILE *f2 = fopen("qwe2.c", "w");
    if (f != NULL)
    {
        readFiles(f, f2);
    }
    else
    {
        std::cout << "Error";
    }
    fclose(f);
    fclose(f2);
    return 0;
}