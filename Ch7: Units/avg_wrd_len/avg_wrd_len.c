#include <stdio.h>

int main(void) 
{
    char ch;
    int n_words = 0, w_len = 0, sum_len = 0;
    float avg_len;

    printf("Enter a sentence: ");
    while ((ch = getchar()) != '\n')
    {
        if (ch == ' ') 
        {
            sum_len += w_len;
            n_words++;
            w_len = 0;
        } 
        else
        {
            w_len++;
        }
    }

    // Add last word
    if (w_len != 0)
    { 
        sum_len += w_len;
        n_words++;
    }
    
    // Compute average
    avg_len = (float) sum_len / n_words;

    printf("Average word length: %.1f\n", avg_len);

    return 0;
}