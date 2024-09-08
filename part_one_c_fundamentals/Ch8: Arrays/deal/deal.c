#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define NUM_SUITS 4
#define NUM_RANKS 13

int main(void) 
{
    bool in_hand[NUM_SUITS][NUM_RANKS] = {false};
    int num_cards, suit, rank;

    // 't' -> 10
    const char rank_code[] = {'2', '3', '4', '5', '6', '7', '8',
                              '9', 't', 'j', 'q', 'k', 'a'};
    const char suit_code[] = {'c', 'd', 'h', 's'};

    // Gen seed
    srand((unsigned) time(NULL));

    printf("Enter number of cards in hand: ");
    scanf("%d", &num_cards);

    printf("Your hand:");
    while (num_cards > 0) {
        suit = rand() % NUM_SUITS; // Generates a random number form 0 to NUM_SUITS - 1
        rank = rand() % NUM_RANKS;

        // Check if the card is already in your hand
        // If not
        if (!in_hand[suit][rank]) {
            // Add it to hand
            in_hand[suit][rank] = true;
            num_cards--;

            // The space before prevents trailing spaces
            printf(" %c%c", suit_code[suit], rank_code[rank]);
        }
    }
    printf("\n");

    return 0;
}