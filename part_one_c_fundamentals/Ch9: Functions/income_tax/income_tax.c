#include <stdio.h>

double calc_tax(double income);

int main(void) 
{
    double income;

    printf("Enter income: $");
    scanf("%lf", &income);

    printf("Taxes due: $%.2lf\n", calc_tax(income));
    return 0;
}

double calc_tax(double income)
{
    double tax_rate = 0.01;
    if (income >= 750.00 && income <= 2250.00) {
        tax_rate = 0.02;
    } else if (income > 2250.00 && income <= 3750.00) {
        tax_rate = 0.03;
    } else if (income > 3750.00 && income <= 5250.00) {
        tax_rate = 0.04;
    } else if (income > 5250.00 && income <= 7000) {
        tax_rate = 0.05;
    } else if (income > 7000.00) {
        tax_rate = 0.06;
    }

    return income * tax_rate;
}