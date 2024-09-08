#include <stdio.h>

// Takes two fractions and prints their sum
int main(void)
{
    // n -> numerator
    // d -> denominator
    signed int n1, d1, n2, d2, rn, rd;
    char operation;

    // the '/' character matches the '/' in the input
    printf("Enter two fractions: ");
    scanf(" %d/%d %d/%d", &n1, &d1, &n2, &d2);

    // get rid of '\n' left by scanf
    getchar();

    printf("Enter operation ('+', '-', '*', '/'): ");
    operation = getchar();

    switch (operation)
    {
        case '-':
            rn = n1 * d2 - n2 * d1;
            rd = d1 * d2;
            break;
        case '*':
            rn = n1 * n2;
            rd = d1 * d2;
            break;
        case '/':
            rn = n1 * d2;
            rd = d1 * n2;
            break;
        default :
            rn = n1 * d2 + n2 * d1;
            rd = d1 * d2;
            break;
    }

    printf(
        "%d/%d %c %d/%d = %d/%d\n",
        n1, d1,
        operation == '\n' ? '+': operation,
        n2, d2,
        rn, rd);

    return 0;
}