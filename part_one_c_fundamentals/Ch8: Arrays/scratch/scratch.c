#include <stdio.h>

int main(void) 
{
    int bonk[4] = {1,2,3,4};

    for (int i = 0; i < 4; i++)
        printf(" %d", bonk[i]);

    bonk[0] = bonk[1] = bonk[2] = bonk[3] = 0;
    for (int i = 0; i < 4; i++)
        printf(" %d", bonk[i]);

    printf("\n");
    return 0;
}