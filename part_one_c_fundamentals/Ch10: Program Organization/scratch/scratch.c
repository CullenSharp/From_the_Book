#include <stdio.h>

int main(void)
{
    int contents[] = {1,2,3,4,5,6,7,8,9,0};
    int top = 1;

    printf("top: %d contents[--top]: %d\n", top, contents[--top]);
    printf("top: %d contents[top]: %d\n", top, contents[top]);
    printf("top: %d contents[top++]: %d\n", top, contents[top++]);
    printf("top: %d contents[top]: %d\n", top, contents[top]);

    return 0;
}