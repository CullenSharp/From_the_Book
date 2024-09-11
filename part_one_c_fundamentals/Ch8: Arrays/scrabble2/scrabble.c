#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch;
        // Tracks the score for a current word
    int score = 0,
        /*
         * In Scrabble each letter is assigned a value. For example,
         * 'a' is worth one point. Since C represents characters with
         * an integer, we can use characters to index the array*. This
         * Method allows us to avoid the use of selection statements
         * altogether.
         * 
         * *Note that this will only work if characters are represented
         * sequentially (i.e. 'b' follows 'a') as with ASCII.
        */
        scores[26] = {1, 3, 3, 2,  1, 4, 2, 4, 1, 8, 5, 1, 3,  
                      1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    printf("Enter word: ");

    while ((ch = toupper(getchar())) != '\n')
        score += scores[ch - 'A'];

    printf("Score: %d\n", score);
    return 0;
}