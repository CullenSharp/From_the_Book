#include <stdio.h>

int main(void) 
{
    int a[] = {5,1,9,[4]=3,7,2,[8]=6};
    unsigned long len = sizeof(a)/sizeof(a[0]);

    for (int i = 0; i < len; i++)
        printf("%d, ", a[i]);

    printf("\n");
    return 0;
}