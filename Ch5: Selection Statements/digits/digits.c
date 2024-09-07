#include <stdio.h>

int main(void)
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("The number %d has ", n);

    if      (n >= 0 && n <= 9)              printf("1 digit.\n");
    else if (n >= 10 && n <= 99)            printf("2 digits.\n");
    else if (n >= 100 && n <= 999)          printf("3 digits.\n");
    else if (n >= 1000 && n <= 9999)        printf("4 digits.\n");
    else                                    printf("More than 4 digits.\n");

    return 0;
}