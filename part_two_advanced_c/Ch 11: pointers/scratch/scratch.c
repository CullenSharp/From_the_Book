#include <stdio.h>

int main(void)
{
    int i = 1;
    int *p = &i;

    printf("*p : %14d\n", *p);
    printf("*&p: %p\n", *&p);
    printf("&p : %p\n", &p);
    printf("&*p: %p\n", &*p);
    printf("&i : %p\n", &i);
    printf("*&i: %14d\n", *&i);
    //printf("&*i: %d\n", &*i);

    return 0;
}