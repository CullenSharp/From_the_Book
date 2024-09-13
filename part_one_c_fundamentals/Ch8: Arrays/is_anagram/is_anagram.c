#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int counts[26] = {0}, i; 
    char ch;

    printf("Enter first word: ");
    while ((ch = getchar()) != '\n') {
        if (isalpha(ch)) counts[(tolower(ch) - 'a')]++;
    }

    printf("Enter second word: ");
    while ((ch = getchar()) != '\n') {
        if (isalpha(ch)) counts[(tolower(ch) - 'a')]--;
    }

    for (i = 0; i < 26; i++) {
        if (counts[i] > 0) break;
    }

    if (i < 26) printf("The words are not anagrams.\n");
    else        printf("The words are anagrams.\n");

    return 0;
}