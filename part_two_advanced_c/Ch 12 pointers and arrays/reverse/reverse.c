#include <stdio.h>

#define LEN 100

int main(void)
{
    char str[LEN], *p;
    printf("Enter a message: ");

    // Point p at the first element of str
    for (p = str; p < str + LEN; p++) {
        *p = getchar();

        if (*p == '\n')
            break;
    }
    
    printf("The reversal is: ");
    while(p >= str)
        putchar(*--p);
    putchar('\n');

    return 0;
}