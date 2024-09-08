#include <stdio.h>

int main(void)
{
    int len = 0;

    printf("Enter a message: ");
    while(getchar() != '\n')
        len++;
    
    printf("The message is %d character(s) long.\n", len);
}