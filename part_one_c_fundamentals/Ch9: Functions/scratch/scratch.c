#include <stdio.h>

void swap(int a, int b);

int main(void) 
{
    int i = 1, j = 2;

    swap(i, j);
    printf("i=%d, and j=%d\n", i, j);

    return 0;
}

void swap(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}