#include <stdio.h>

int main(void)
{
    int          a = -11;
    unsigned     b =  10;

    // Very problematic, implicitly converts a to an unsigned int
    printf("%d + %u = %u\n", a, b, a + b);

    return 0;
}