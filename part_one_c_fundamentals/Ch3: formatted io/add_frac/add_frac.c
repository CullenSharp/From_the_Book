#include <stdio.h>

// Takes two fractions and prints their sum
int main(void)
{
    // n -> numerator
    // d -> denominator
    int n1, d1, n2, d2, rn, rd;

    // the '/' character matches the '/' in the input
    printf("Enter the sum of two fractions: ");
    scanf("%d/%d+%d/%d", &n1, &d1, &n2, &d2);

    // cross multiply
    rn = n1*d2 + n2*d1;
    rd = d1*d2;

    printf("%d/%d + %d/%d = %d/%d\n", n1, d1, n2, d2, rn, rd);
    return 0;
}