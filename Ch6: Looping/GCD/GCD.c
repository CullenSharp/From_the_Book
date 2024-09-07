#include <stdio.h>

int main(void)
{
    int n, m, tmp;

    printf("Enter two numbers:" );
    scanf("%d %d", &n, &m);

    while(n > 0) tmp = n; n = m % n; m = tmp;

    printf("GCD: %d\n", m);
    return 0;
}