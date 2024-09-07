#include <stdio.h>

int main(void)
{
    int n_days, day_of_the_week;

    printf("Enter number of days in the month: ");
    scanf("%d", &n_days);

    printf("Enter starting day of the week (1=Sun, 7=Sat): ");
    scanf("%d", &day_of_the_week);

    for (int i = 1; i <= n_days + day_of_the_week - 1; i++) {
        if (i < day_of_the_week) printf("   ");
        else {
            printf("%2d ", i - day_of_the_week + 1);
            if (i % 7 == 0) printf("\n"); 
        } 
    }

    printf("\n");
    return 0;
}