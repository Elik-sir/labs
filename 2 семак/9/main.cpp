#include <iostream>
#include <malloc.h>
#include <cstdlib>
#include "lab.h"

using namespace std;

// структурка
// ввод строкой (1 0 1 1 0)
// вывод тоже строкой
// умножение вектора на матрицу
// подсчёт количества единиц в результате

int main()
{
    try
    {
        int p1Size;
        int p2Size;
        // cout << "Write degree p1: ";
        // cin >> p1Size;
        // p1Size++;
        // int *p1 = getPolynom(p1Size);
        // cout << "Write degree p2: ";
        // cin >> p2Size;
        // p2Size++;
        // int *p2 = getPolynom(p2Size);

        // string p1Str;
        // cout << "Write p1: ";
        // getline(cin, p1Str);
        // cout << endl;
        // string p2Str;
        // cout << "Write p2: ";
        // getline(cin, p2Str);
        // int *p1 = convertFromStr(p1Str);
        // int *p2 = convertFromStr(p2Str);

        // p1Size = p1Str.size() / 2;
        // p2Size = p2Str.size() / 2;
        // cout << "Digits: " << countOne(p1, p1Size) << endl;
        // Polynom q = dividePolynoms(p1, p2, p1Size, p2Size);

        // if (q.q != NULL)
        // {
        //     cout << "q= ";
        //     printPolynom(q.q, q.qSize, "x");
        //     cout << "r= ";
        //     printPolynom(q.r, q.rSize, "x");
        // }

        // free(p1);
        // free(p2);
        // free(q.q);
        // free(q.r);
        int *vector = (int *)malloc(sizeof(int) * 3);
        vector[0] = 5;
        vector[1] = 4;
        vector[2] = 10;
        Matrix a = writeMatrix();

        int *g = VectorProductMatrix(vector, a, 3);
        for (int i = 0; i < a.columns; i++)
        {
            cout << g[i] << "   ";
        }
        cout << endl;
    }
    catch (invalid_argument &e)
    {
        cerr << e.what() << endl;
        exit(-1);
    }
    exit(1);
}