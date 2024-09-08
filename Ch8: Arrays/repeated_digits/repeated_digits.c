#include <stdbool.h> // Since C99 defines bool, true and false
#include <stdio.h>

int main(void) 
{
    bool digit_seen[10] = {false};
    int digit, repeated_digit[10] = {0};
    long n;

    printf("Enter number: ");
    scanf("%ld", &n);

    while (n > 0) {
        digit = n % 10;

        // If a digit has already been seen
        if (digit_seen[digit])
            // Add it to the list of repeats
            repeated_digit[digit]++;

        // Record that we've seen the current digit
        digit_seen[digit] = true;
        n /= 10;
    }

    printf("Repeated digits: ");
    for (int i = 0; i < 10; i++) {
        if (repeated_digit[i])
            printf(" %d", i);
    }
    printf("\n");

    return 0;
}