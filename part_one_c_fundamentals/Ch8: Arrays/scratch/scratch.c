#include <stdio.h>

int main(void) 
{
    printf("%d\n", 'P' - 'A');
    printf("%d\n", 'I' - 'A');
    printf("%d\n", 'T' - 'A');
    printf("%d\n", 'F' - 'A');
    printf("%d\n", 'A' - 'A');
    printf("%d\n", 'L' - 'A');
    printf("%d\n", 'L' - 'A');

    for (char ch = 'a'; ch <= 'z'; ch++) {
        if (ch % 13 == 0)
            printf("\n");
            
        printf(" %c,%d", ch, ch);
    }

    printf("\n");
    return 0;
}