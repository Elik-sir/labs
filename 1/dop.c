#include <stdio.h>
int main(int argc, char *argv[])
{
    unsigned int b = 3;
    int q = 4;
    int number = 2;
    printf("%u \t", b);
    while (number < 16)
    {
        b *= q;
        printf("%d  \t", b);
        number++;
    }
    printf("\n15th element eq %u\n", b);
}
// начальный элемент равен 3  q=4 выведите 15 лемент