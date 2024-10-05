#include <stdio.h>
#include <string.h>

#define WORD_LEN 20

int main(void)
{
    char smallest_word[WORD_LEN + 1] = {'\0'}, largest_word[WORD_LEN + 1];
    char current_word[WORD_LEN + 1];

    for (;;) {
        printf("Enter a word: ");
        scanf("%20s", current_word);

        if (smallest_word[0] == '\0') {
            strcpy(smallest_word, current_word);
        } else if (strcmp(smallest_word, current_word) > 0) {
            strcpy(smallest_word, current_word);
        }

        if (strcmp(largest_word, current_word) < 0) {
            strcpy(largest_word, current_word);
        }

        if (strlen(current_word) == 4) break;
    }

    printf("\nSmallest word: %s\n", smallest_word);
    printf("Largest word: %s\n", largest_word);
    return 0;
}