#include <stdio.h>

int main(void)
{
    float n, largest = 0;

    do {
        printf("Enter a number: ");
        scanf("%f", &n);

        if (largest < n) largest = n;
        else continue;
    } while (n > 0);

    printf("\nThe largest number entered was %.2f.\n", largest);
    return 0;
}