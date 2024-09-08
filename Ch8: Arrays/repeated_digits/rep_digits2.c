#include <stdio.h>

int main(void) 
{
    int digit, occurrences[10] = {0};
    long n;

    printf("Enter number: ");
    scanf("%ld", &n);

    while (n > 0) {
        digit = n % 10;

        occurrences[digit]++;
        n /= 10;
    }
    
    printf("Digits:     ");
    for (int i = 0; i < 10; i++) {
        printf("  %d", i);
    }
    
    printf("\nOccurrences:");
    for (int i = 0; i < 10; i++) {
        printf("  %d", occurrences[i]);
    }
    printf("\n");

    return 0;
}