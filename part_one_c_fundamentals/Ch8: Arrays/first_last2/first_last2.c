#include <stdio.h>

int main(void) 
{
    /*
     * Example 
     * Enter a first and last name: Larry Fosdick
     * Fosdick, L.
    */

   int i = 0;
   char f_init, l_name[20];

   printf("Enter first and last name: ");
   scanf(" %1c%*s %s", &f_init, l_name);

   while(l_name[i]) {
        printf("%c", l_name[i++]);
   }

   printf(", %c.\n", f_init);

   return 0;
}