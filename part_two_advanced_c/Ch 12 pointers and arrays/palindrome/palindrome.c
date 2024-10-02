#include <stdio.h>
#include <ctype.h>

#define MSG_LEN 80

int main(void)
{
    char msg[MSG_LEN], *p, *q;

    printf("Enter a message: ");
    for (q = msg; q < msg + MSG_LEN; q++) {
        *q = getchar();

        if (*q == '\n')
            break;
    }

    // Setup pointers
    q--;
    p = msg;

    while(p < q) {
        // Skip non-alpha characters
        while(!isalpha(*p)) {
            p++;
        }

        while(!isalpha(*q)) {
            q--;
        }

        // if not palindrome, break
        if (toupper(*q) != toupper(*p)) {
            printf("Not a palindrome\n");
            return 0;
        }

        // Shift pointers
        p++;
        q--;
    }

    printf("Palindrome\n");
    return 0;
}