#include <stdio.h>

int main(void)
{
    int n;

    printf("Enter number: ");
    scanf("%d", &n);

    for (int sq = 4, diff = 12; sq <= n; diff += 8)
    {
        printf("%d\n", sq);
        sq += diff;
    }

    return 0;
}