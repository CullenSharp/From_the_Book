#include <stdio.h>

#define LEN 100

int main(void)
{
    char ch, str[LEN], *p;
    printf("Enter a message: ");

    // Point p at the first element of str
    p = str;
    while((ch = getchar()) != '\n' && p < (str + LEN)) {
        *p++ = ch;
    }
    
    printf("The reversal is: ");
    while(p > str) {
        printf("%c", *--p);
    }
    printf("\n");

    return 0;
}