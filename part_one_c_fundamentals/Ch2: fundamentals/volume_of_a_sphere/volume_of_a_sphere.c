#include <stdio.h>

int main(void)
{
    float radius;
    printf("Enter the radius of a sphere in meters: ");
    scanf("%f", &radius);

    float volume = (4.0f / 3.0f) * 3.14159f * radius * radius * radius;
    
    printf(
        "The volume of a sphere with a %.0f-radius is %.2f cubic meters.\n",
        radius,
        volume);

    return 0;
}