#include "lab.h"

void printBuf()
{
    for (int i = 0; i < sizeS * 17; i++)
    {
        cout << buffer[i];
    }
    cout << endl;
}

void printArr()
{
    for (int i = 0; i < sizeS; i++)
    {
        cout << reserved[i] << "   ";
    }
    cout << endl;
}

char *palloc(int n)
{
    int c = 0;
    int i = 0;
    int firstPoint = 0;
    if (n == 0)
    {
        return NULL;
    }
    while (c < n && i < sizeS)
    {
        if (reserved[i] == 0)
        {
            if (c == 0)
            {
                firstPoint = i;
            }
            c++;
        }
        else
        {
            c = 0;
        }
        i++;
    }

    if (c == n)
    {
        while (c > 0)
        {
            reserved[i - c] = 1;
            c--;
        }

        buffer[(i << 4)] = '\0';
        if (buffer[firstPoint << 4] == '\0')
        {
            return (buffer + (firstPoint << 4) + 1);
        }
        return (buffer + (firstPoint << 4));
    }

    return NULL;
}

void pfree(char *p)
{
    int a = (p - buffer) >> 4;

    while (a < sizeS)
    {
        reserved[a] = 0;
        if (buffer[((a + 1) << 4)] == '\0')
        {
            buffer[((a + 1) << 4)] = ' ';
            break;
        }
        a++;
    }
    cout << endl;
}

void defrag(char ***p, int countPointer)
{
    int firstBlock,
        lastBlock,
        left,
        right, l, j;

    for (int i = 0; i < countPointer; i++)
    {

        firstBlock = (*p[i] - buffer) >> 4;
        if (firstBlock == 0)
        {
            continue;
        }
        lastBlock = (*p[i] - buffer) >> 4;
        left = firstBlock;
        right = lastBlock;
        l = 0;
        j = 0;
        while (left > 0)
        {

            left--;
            if (reserved[left] == 1)
            {
                l = left + 1;
                break;
            }
        }

        while (right < sizeS)
        {
            if (buffer[((right + 1) << 4)] == '\0')
            {
                buffer[(right << 4)] == ' ';
                break;
            }
            right++;
        }
        int countBlocks = right - firstBlock;
        cout << "L: " << right << endl;
        while (j < countBlocks + 1)
        {
            reserved[l + j] = reserved[firstBlock + j];
            replace(l + j, firstBlock + j);
            reserved[firstBlock + j] = 0;
            j++;
        }
        if (*(buffer + (l << 4)) == '\0')
        {
            *p[i] = (buffer + (l << 4) + 1);
        }
        else
        {
            *p[i] = (buffer + (l << 4));
        }
        *(buffer + ((l + countBlocks + 1) << 4)) = '\0';
    }
}

void replace(int posTo, int posFrom)
{
    int i = 0;
    int d = posTo << 4;
    int d2 = (posFrom << 4);
    if (buffer[d2] == ' ')
    {
        d2++;
    }
    while (i < 16)
    {
        buffer[d + i] = buffer[d2 + i];
        i++;
    }
    if (buffer[d2 + i] == '\0')
    {
        buffer[d2 + i] = ' ';
    }
}

char *prealloc(char *p, int n)
{
    int c = 0;
    int i = 0;
    int firstPoint = 0;
    if (n == 0)
    {
        return NULL;
    }
    while (c < n && i < sizeS)
    {

        if (reserved[i] == 0)
        {
            if (c == 0)
            {
                firstPoint = i;
            }
            c++;
        }
        else
        {
            c = 0;
        }
        i++;
    }

    if (c == n)
    {
        int firstBlock = (p - buffer) >> 4;
        cout << "C: " << c << endl;
        while (c >= 0)
        {
            reserved[i - c] = 1;
            replace(i - c, firstBlock + c);
            reserved[firstBlock + c] = 0;
            c--;
        }
        firstPoint++;
        buffer[(i << 4)] = '\0';
        if (buffer[firstPoint << 4] == '\0')
        {
            return (buffer + (firstPoint << 4) + 1);
        }
        return (buffer + (firstPoint << 4));
    }

    return NULL;
}