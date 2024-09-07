#include <stdio.h>

int main(void)
{
    int hrs, mins;
    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hrs, &mins);
    
    printf("Equivalent 12-hour time: ");
    if (hrs >= 0 && hrs < 12) printf("%d:%.2d AM\n", hrs, mins);
    else if (hrs == 12) printf("%d:%.2d PM\n", hrs, mins);
    else printf("%d:%.2d PM\n", hrs - 12, mins);

    return 0;
}