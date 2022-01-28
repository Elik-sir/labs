#include <stdio.h>
int main(int argc, char *argv[])
{
    int fi = 1;
    int last = 0;
    int number = 3;
    printf("%d  \t", 0);
    printf("%d  \t", 1);
    printf("%d  \t", 1);
    while (fi < 1000)
    {
        last = fi - last;
        fi += last;
        printf("%d  \t", fi);
        number++;
    }
    printf("\nThe first element of the Fibonacci sequence that is greater than 1000 has number %d\n", number);
}
// начальный элемент равен 3  q=4 выведите 15 лемент