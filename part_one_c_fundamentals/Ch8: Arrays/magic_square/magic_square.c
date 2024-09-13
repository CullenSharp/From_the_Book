#include <stdio.h>
#include <math.h>

int main(void) 
{
    int n, row, column;

    printf("This program creates a magic square of a specified size.\n");
    printf("The size must be an odd number 1 to 99.\n");
    printf("Enter size of magic square: ");
    scanf("%d", &n);

    int magic_square[n][n];

    // Initialize the array
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            magic_square[i][j] = 0;
        }
    }

    // Place a one in the middle of the first row
    magic_square[0][n/2] = 1;

    row = 0;
    column = n/2;

    for (int i = 2; i <= n * n; i++)
    {
        /*
         * Movement logic
         * On each iter place i up one row and over one column
         * if out of bounds, wrap around
         * if cell occupied, mark cell directly beneath the current one
        */
        if (magic_square[row == 0 ? n - 1 : row - 1][(column + 1) % n] != 0)
        {
            magic_square[++row][column] = i;
        } 
        else
        {
            row = row == 0 ? n - 1 : row - 1;
            column = (column + 1) % n;
            magic_square[row][column] = i;
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf(" %4d", magic_square[i][j]);
        }
        printf("\n");
    }

    return 0;
}