#include <stdio.h>

int main(void) 
{
    int i, n, odd, square;

    printf("This program prints a table of squares.\n");
    printf("Enter the number of entries in the table: ");
    scanf("%d", &n);

    odd = 3;
    for (i = 1, square = 1; i <= n; ++i, odd += 2)
    {
        if (i % 24 == 0) {
            printf("Press Enter to continue...\n");
            while(getchar() != '\n')
                ;
        }
        printf("%10d%10d\n", i, square);
        square += odd;
    }

    return 0;
}