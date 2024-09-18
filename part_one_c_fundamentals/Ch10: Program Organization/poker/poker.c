#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define NUM_CARDS 5
#define RANK  0
#define SUIT  1

// External variables
bool straight, flush, four, three;
int pairs;

// Function prototypes
void read_cards(int hand[NUM_CARDS][2]);
void sort_hand(int num_cards, int hand[NUM_CARDS][2]);
void analyze_hand(int hand[NUM_CARDS][2]);
void print_result(int hand[NUM_CARDS][2]);

/*****************************************************************************
 * main: Calls read_cards, analyze hand, and print results repeatedly
 *****************************************************************************/
int main(void)
{
    int hand[NUM_CARDS][2];
    for (;;) {
        read_cards(hand);
        sort_hand(NUM_CARDS, hand);
        analyze_hand(hand);
        print_result(hand);
    }
}

/*****************************************************************************
 * read_cards: Reads the cards into the external variables
 *             num_in_rank and num_in_suit; 
 *             checks for bad cards and duplicate cards.
 *****************************************************************************/
void read_cards(int hand[NUM_CARDS][2])
{
    char ch, rank_ch, suit_ch;
    int rank, suit;
    bool bad_card, is_duplicate = false;
    int cards_read = 0, card;

    // Reset hand
    for (card = 0; card < NUM_CARDS; card++) {
        hand[card][RANK] = hand[card][SUIT] = 0;
    }

    while (cards_read < NUM_CARDS) {
        bad_card = false;

        printf("Enter a card: ");

        rank = getchar();
        switch(rank) {
            case '0':           exit(EXIT_SUCCESS);
            case '2':           rank = 0;  break;
            case '3':           rank = 1;  break;
            case '4':           rank = 2;  break;
            case '5':           rank = 3;  break;
            case '6':           rank = 4;  break;
            case '7':           rank = 5;  break;
            case '8':           rank = 6;  break;
            case '9':           rank = 7;  break;
            case 't': case 'T': rank = 8;  break;
            case 'j': case 'J': rank = 9;  break;
            case 'q': case 'Q': rank = 10; break;
            case 'k': case 'K': rank = 11; break;
            case 'a': case 'A': rank = 12; break;
            default:            bad_card = true;
        }

        suit = getchar();
        switch(suit) {
            case 'c': case 'C': suit = 0; break;
            case 'd': case 'D': suit = 1; break;
            case 'h': case 'H': suit = 2; break;
            case 's': case 'S': suit = 3; break;
            default:            bad_card = true;
        }

        while((ch = getchar()) != '\n') {
            if (ch != ' ') bad_card = true;
        }

        for (card = 0; card < cards_read; card++) {
            if (hand[card][RANK] == rank &&
                hand[card][SUIT] == suit) {
                    is_duplicate = true;
                }
        }

        if (bad_card) {
            printf("Bad card. Ignored.\n");
        } else if (is_duplicate) {
            printf("Duplicate. Ignored.\n");
        } else {
            hand[cards_read][RANK]   = rank;
            hand[cards_read++][SUIT] = suit;
        }
    }
}

/*****************************************************************************
 * sort_hand: Sorts a hand of cards by rank recursively
 *****************************************************************************/
void sort_hand(int num_cards, int hand[NUM_CARDS][2])
{
    int max_rank = hand[0][RANK], max_suit = hand[0][SUIT], max_card_pos = 0;

    if (num_cards <= 0) return;
    
    for (int card = 0; card < num_cards; card++) {
        if (max_rank < hand[card][RANK]) {
            max_card_pos = card;

            max_rank = hand[card][RANK];
            max_suit = hand[card][SUIT];
        }
    }

    // Swap max and last
    hand[max_card_pos][RANK] = hand[num_cards - 1][RANK];
    hand[max_card_pos][SUIT] = hand[num_cards - 1][SUIT];

    hand[num_cards - 1][RANK] = max_rank;
    hand[num_cards - 1][SUIT] = max_suit;

    sort_hand(num_cards - 1, hand);
}

/*****************************************************************************
 * analyze_hand: Determines whether the hand contains a
 *               straight, a flush, four-of-a-kind, 
 *               and/or three-of-a-kind; determines the number of pairs;
 *               stores the result in external variables straight, flush,
 *               four, three, and pairs.
 *****************************************************************************/
void analyze_hand(int hand[NUM_CARDS][2])
{
    int num_consecutive = 1;
    int rank = hand[0][RANK], suit = hand[0][SUIT];
    straight = false;
    flush = true;
    four = false;
    three = false;
    pairs = 0;

    // Check for straight and flush
    for (int card = 1; card < NUM_CARDS; card++)
    {
        // straight means that the cards are ascending in rank
        if (hand[card][RANK] == ++rank) {
            num_consecutive++;
        }

        // Flush means all the cards have the same suit
        if (hand[card][SUIT] != suit) {
            flush = false;
        }

        suit = hand[card][1];
    }

    if (num_consecutive == NUM_CARDS) {
        straight = true;
        return;
    } else if (num_consecutive == NUM_CARDS - 1 &&
               hand[NUM_CARDS - 1][RANK] == 12) {
        // Straight ace-low
        // Works because hand is sorted; ace always appears last.
        straight = true;
        return;
    }

    // Check for pairs, three-of-a-kind and four-of-a-kind
    for (int cur_card = 0; cur_card < NUM_CARDS; cur_card++) {
        int score = 1;
        for (int nxt_card = cur_card + 1; nxt_card < NUM_CARDS; nxt_card++) {
            if (hand[cur_card][RANK] == hand[nxt_card][RANK]) {
                score++;
            }
        }
        
        if (score == 4) {
            four = true;
            break;
        } else if (score == 3) {
            cur_card++; // skip two cards, works because cards are sorted
            three = true;
        } else if (score == 2) 
            pairs++;
    }
}

/*****************************************************************************
 * analyze_hand: Prints the classification of the hand,
 *               based on the values of external
 *               variables straight, flush, four, three, and pairs
 *               and the state of the hand
 *****************************************************************************/
void print_result(int hand[NUM_CARDS][2])
{
    /* Royal flush means ten, jack, king, queen ace all in the same suit.
     * Ten will always appear first in this case, since the hand is sorted.
     */
    if (straight && flush && hand[0][RANK] >= 8) printf("Royal Flush");
    else if (straight && flush)                  printf("Straight flush");
    else if (four)                               printf("Four-of-a-kind");
    else if (three && 
             pairs == 1)                         printf("Full house");
    else if (three)                              printf("Three-of-a-kind");
    else if (flush)                              printf("Flush");
    else if (straight)                           printf("Straight");
    else if (pairs == 2)                         printf("Two pairs");
    else if (pairs == 1)                         printf("One pair");
    else                                         printf("High card");

    printf("\n\n");
}