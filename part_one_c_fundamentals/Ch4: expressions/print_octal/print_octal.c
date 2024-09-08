#include <stdio.h>

int main(void)
{
    int inp, o1, o2, o3, o4, o5;
    printf("Enter a number between 0 and 32,767: ");
    scanf("%d", &inp);

    o5 = inp % 8;
    inp /= 8;
    o4 = inp % 8;
    inp /= 8;
    o3 = inp % 8;
    inp /= 8;
    o2 = inp % 8;
    inp /= 8;
    o1 = inp % 8;
    


    printf("In octal, your number is: %d%d%d%d%d\n", o1, o2, o3, o4, o5);
    return 0;
}