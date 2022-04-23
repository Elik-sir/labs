#include <iostream>
#include "lab.h"
#include <fstream>
// использовать fstream
// убирать лишние пустые строчки
// счетчики удаленных комментариев по типам
// разобраться с const во всех возможных случаях и поставить, где надо

int main()
{
    ifstream fileIn;
    ofstream fileOut;
    fileIn.open("qwe.c");
    fileOut.open("qwe2.c");
    if (fileIn.is_open() && fileOut.is_open())
    {
        counter count = readFiles(fileIn, fileOut);
        cout << "Deleted singleline comments: " << count.singleline << endl
             << "Deleted multiline comments : " << count.multiline << endl;
    }
    else
    {
        std::cout << "Error";
    }
    fileIn.close();
    fileOut.close();
    return 0;
}