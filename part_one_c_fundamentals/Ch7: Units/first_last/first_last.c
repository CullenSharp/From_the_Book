#include <stdio.h>

int main(void) 
{
    /*
     * Example 
     * Enter a first and last name: Larry Fosdick
     * Fosdick, L.
    */

    char ch, F_init = ' ';

    printf("Enter first and last name: ");

    // Ignores leading spaces
    while((ch = getchar()) == ' ');
    F_init = ch;

    // Ignore preceeding characters in first name
    while((ch = getchar()) != ' ');

    // Ignore spaces between first and last
    while((ch = getchar()) == ' ');

    // Print lastname and ignore trailing spaces
    printf("%c", ch);
    while((ch = getchar()) != ' ') printf("%c", ch);
    
    printf(", %c.\n", F_init);
    return 0;
}