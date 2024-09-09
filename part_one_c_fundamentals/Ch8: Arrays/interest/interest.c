#include <stdio.h>

// Controls the number of rows
// Depends on the size of the `value` array
#define NUM_RATES ((int) (sizeof(value)/sizeof(value[0])))
#define INITIAL_BALANCE 100.00

int main(void) 
{
    int i, low_rate, num_years, year, month;
    double value[5];

    printf("Enter the interest rate: ");
    scanf("%d", &low_rate);

    printf("Enter the number of years: ");
    scanf("%d", & num_years);

    printf("\nYears");
    for (i = 0; i < NUM_RATES; i++) {
        printf("%6d%%", low_rate + i);
        value[i] = INITIAL_BALANCE;
    }
    printf("\n");

    for (year = 1; year <= num_years; year++) {
        printf("%3d    ", year);
        for (i = 0; i < NUM_RATES; i++){
            for (month = 0; month < 12; month++)
                // Casts the expression low_rate + i to double to prevent loss of precision
                value[i] += ((double) (low_rate + i) / 12) / 100.0 * value[i];
            printf("%7.2f", value[i]);
        }
        printf("\n");
    }
    /*
     * To calculate interest compounding monthly we take our APR
     * and divide it over 12 months (e.g. 6% corresponds to 0.5% each month).
     * Each month, the amount we have grows in proportion to what we gained.
     * For example, if the principal is $100.00 w/ 6% APR, after one month
     * we have 100 + 100(0.005) = $100.5;
     * after two months, we have 100.5 + 100.5(0.005) = $101.0025;
     * after three months, we have 101.0025 + 101.0025(0.005) = $101.5075125
     * and so on.
     * 
     * Man, I feel so dumb right now.
    */
    return 0;
}