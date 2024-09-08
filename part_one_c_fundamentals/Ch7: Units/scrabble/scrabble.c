#include <stdio.h>
#include <ctype.h>

int main(void)
{
    char ch;
    int score;

    printf("Enter word: ");
    while ((ch = getchar()) != '\n')
    {
        switch(toupper(ch))
        {
            case 'D': case 'G':
                score += 2;
                break;
            case 'B': case 'C': case 'M': case 'P':
                score += 3;
                break;
            case 'F': case 'H': case 'V': case 'W': case 'Y':
                score += 4;
                break;
            case 'K':
                score += 5;
                break;
            case 'J': case 'X':
                score += 8;
                break;
            case 'Q': case 'Z':
                score += 10;
                break;
            default:
                score += 1;
                break;
        }
    }
    printf("Score: %d\n", score);

    return 0;
}