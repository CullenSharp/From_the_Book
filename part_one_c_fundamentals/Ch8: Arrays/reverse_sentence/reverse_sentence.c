#include <stdio.h>
#include <ctype.h>

#define SIZE 40

/*
 * Takes a sentence, then reverses the word order. Thus
 *      "you can cage a swallow can't you?"
 * becomes
 *      "you can't swallow a cage can you?"
*/
int main(void)
{
    char ch, sentence[SIZE];
    int i = 0, j;

    printf("Enter a sentence: ");
    while((ch = getchar()) != '.' && ch != '?' && ch != '!') {
        sentence[i++] = ch;
    }

    // Add terminating character
    sentence[i] = ch;

    for (i = SIZE - 1; i >= 0; i--) {
        if (sentence[i] == ' ') {
            j = i + 1;
            while (sentence[j] != ch && sentence[j] != ' ') {
                printf("%c", sentence[j++]);
            }

            printf(" ");
        }
    }

    // Print the last word
    i = 0;
    while (sentence[i] != ' ') {
        printf("%c", sentence[i++]);
    }
    
    // Print the terminating character
    printf("%c\n", ch);
    return 0;
}