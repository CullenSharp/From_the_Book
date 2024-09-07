#include <stdio.h>
#include <float.h>

int main(void)
{
    printf("The maximum value of a float %.10e\n", FLT_MAX);
    printf("The minimum value of a float %.10e\n", FLT_MIN);
    printf("\n");

    printf("The maximum value of a double %.10lg\n", DBL_MAX);
    printf("The minimum value of a double %.10lg\n", DBL_MIN);
    printf("\n");

    printf("The maximum value of a long double %.10Lg\n", LDBL_MAX);
    printf("The minimum value of a long double %.10Lg\n", LDBL_MIN);

    return 0;
}