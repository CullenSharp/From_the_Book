#include <stdio.h>

int main(void)
{
    int input, d1, d2, d3;

    printf("Enter a three-digit number: ");
    scanf("%1d%1d%1d", &d1, &d2, &d3);

    /* if input is 365, then input/100 = 3, input % 100 = 65, and input % 10 = 5
     * d1 = input / 100;                        // hundreds place
     * d2 = (input % 100) / 10;                 // tens place
     * d3 = input % 10;                         // ones place
    */

    printf("The reversal is: %d%d%d\n", d3, d2, d1);
    return 0;
}