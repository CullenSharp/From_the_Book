#include <stdio.h>

int main(void)
{
    float x, result;

    printf("Enter a value for x: ");
    scanf("%f", &x);

    result = ((((3*x + 2)*x - 5)*x - 1)*x + 7)*x - 6;

    printf(
        "3(%.3f)^5 + 2(%.3f)^4 - 5(%.3f)^3 - %.3f^2 + 7(%.3f) - 6 = %.3f\n",
        x, x, x, x, x,
        result);

    return 0;
}