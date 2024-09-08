#include <stdio.h>

int main(void) 
{
    int i, n;

    printf("This program prints a table of squares.\n");
    printf("Enter the number of entries in the table: ");
    scanf("%d", &n);

    // Get rid of the new line left by scanf
    getchar();
    for (i = 1; i <= n; ++i)
    {
        if (i % 24 == 0) {
            printf("Press Enter to continue...\n");
            
            // Do nothing if 'enter' is not hit
            getchar();
        }
        printf("%10d%10d\n", i, i*i);
    }

    return 0;
}