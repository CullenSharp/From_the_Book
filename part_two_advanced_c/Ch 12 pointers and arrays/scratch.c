#include <stdio.h>

char *xlate[] = {"zero", "one", "two", "three", "four", "five",
                 "six", "seven", "eight","nine","ten"};

int main(void)
{
    printf("%s\n", xlate[0]);
    return 0;
}