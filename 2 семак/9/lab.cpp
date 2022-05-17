#include <iostream>
#include <malloc.h>
#include <cstdlib>
#include <string>
#include "lab.h"
using namespace std;

void printPolynom(int *pol, int size, string arg)
{
    int i = size - 1;
    while (pol[i] == 0)
    {
        i--;
    }
    if (i < 0)
    {
        return;
    }
    if (i == 0)
    {
        cout << 1;
        return;
    }
    else
    {
        cout << arg << "^" << i;
    }
    i--;
    for (; i > 0; i--)
    {
        if (pol[i] == 0)
        {
            continue;
        }
        cout << " + " << arg << "^" << i;
    }
    if (pol[i] == 1)
    {
        cout << " + " << 1;
    }
    cout << endl;
}

int *getPolynom(int size)
{
    int *p = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
    a:
        cout << "write coef " << i << "th degree: ";
        cin >> p[i];
        if (p[i] != 0 && p[i] != 1)
        {
            cout << "coef should be 0 or 1, please try again" << endl;
            goto a;
        }
    }

    return p;
}

Polynom dividePolynoms(int *p1, int *p2, int n, int m)
{

    while (p2[m] == 0)
    {
        m--;
    }
    while (p1[n] == 0)
    {
        n--;
    }
    if (n < m)
    {
        Polynom result;
        result.q = NULL;
        return result;
    }
    Polynom result;

    result.q = (int *)malloc(sizeof(int) * n);
    result.r = (int *)malloc(sizeof(int) * n);
    result.qSize = n;
    result.rSize = n;
    for (int i = 0; i < n + 1; i++)
    {
        result.q[i] = 0;
    }

    for (int i = 0; i < n + 1; i++)
    {
        result.r[i] = p1[i];
    }

    while (n >= m)
    {
        result.q[n - m] = (result.r[n] / p2[m]) % 2;
        for (int j = n, i = 0; j >= n - m; j--, i++)
        {
            result.r[j] = abs(result.r[j] - result.q[n - m] * p2[m - i]) % 2;
        }
        n--;
    }

    return result;
}

int *convertFromStr(string p)
{
    int *res = (int *)malloc(sizeof(int) * p.size() / 2 + 1);
    for (int i = 0, j = (p.size() / 2); i < p.size(); i++)
    {

        if (p[i] == '0')
        {

            res[j] = 0;
            j--;
            continue;
        }
        if (p[i] == '1')
        {

            res[j] = 1;
            j--;
            continue;
        }
        if (p[i] != ' ')
        {
            throw invalid_argument("ERROR!!!!");
        }
    }
    return res;
}

int countOne(int *p, int size)
{
    int c = 0;
    for (int i = 0; i < size + 1; i++)
    {
        if (p[i] == 1)
        {
            c++;
        }
    }
    return c;
}

int *VectorProductMatrix(int *vector, Matrix matrix, int vectorSize)
{
    if (vectorSize != matrix.rows)
    {
        throw invalid_argument("ERROR!!!!");
    }
    int *result = (int *)malloc(sizeof(int) * matrix.columns);
    for (int i = 0; i < matrix.columns; i++)
    {
        result[i] = 0;
    }
    for (int i = 0; i < matrix.columns; i++)
    {

        for (int j = 0; j < vectorSize; j++)
        {
            result[i] += vector[j] * matrix.data[j][i];
        }
    }

    return result;
}

Matrix writeMatrix()
{
    int rows, columns;
    cout << "Write rows: ";
    cin >> rows;
    cout << endl;
    cout << "Write columns: ";
    cin >> columns;
    cout << endl;
    int **data = (int **)malloc(sizeof(int *) * rows);
    for (int i = 0; i < rows; i++)
    {
        data[i] = (int *)malloc(sizeof(int) * columns);
        for (int j = 0; j < columns; j++)
        {
            cout << "matrix[" << i << "][" << j << "]: ";
            cin >> data[i][j];
            cout << endl;
        }
    }
    Matrix result;
    result.columns = columns;
    result.rows = rows;
    result.data = data;
    return result;
}

void printMatrix(Matrix a)
{
    for (int i = 0; i < a.rows; i++)
    {
        for (int j = 0; j < a.columns; j++)
        {
            cout << a.data[i][j] << "   ";
        }
        cout << endl;
    }
}