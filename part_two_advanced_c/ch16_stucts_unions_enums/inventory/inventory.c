#include <stdio.h>
#include "readine.h"

#define NAME_LEN 25
#define MAX_PARTS 100

struct part {
    int number;
    char name[NAME_LEN+1];
    int on_hand;
} inventory[MAX_PARTS];

int num_parts = 0;

int find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);

/*
 * Main: Prompts user for op code,
 *       then calls a function preforming that action.
 *       Repeats request until user inputs 'q'.
 *       Prints an error if an illegal code is entered.
 */
int main(void)
{
    char code;

    for (;;) {
        printf("Enter op code: ");
        scanf(" %c", &code);
        while (getchar() != '\n') // Skips to the end of the line
            ;
        switch (code) {
            case 'i': insert();
                      break;
            case 's': search();
                      break;
            case 'u': update();
                      break;
            case 'p': print();
                      break;
            case 'q': return 0;
            default: printf("Illegal code\n");
        }
        printf("\n");
    }
}

/*
 * find_part: looks up a part number in the inventory array.
 *            returns the index if found, otherwise it returns -1
 *
 */
int find_part(int number)
{
    int i;
    for (i = 0; i < num_parts; i++)
        if (inventory[i].number == number)
            return i;
    
    return -1;
}

/*
 * insert: Prompts user for information about a new part,
 *         and inserts it into the inventory array
 *         Prints an error or returns prematurely if the part already exists,
 *         or the database is full.
 */
void insert(void)
{
    int part_number;
    if (num_parts == MAX_PARTS) {
        printf("Database is full; can't add more parts.\n");
        return;
    }

    printf("Enter a part number: ");
    scanf(" %d", &part_number);

    if (find(part_number) >= 0) {
        printf("Part already exists in the database.\n");
        return;
    }

    inventory[num_parts].number = part_number;
    printf("Enter part name: ");
    read_line(inventory[num_parts].name, NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf(" %d", &inventory[num_parts].on_hand);
    num_parts++;
}

/*
 * search: Prompts the user for a part number,
 *         and prints the name and quantity if it exists in the db.
 *         else it prints an error message.
 */
void search(void)
{
    int i, part_number;

    printf("Enter a part number: ");
    scanf(" %d", &part_number);
    i = find(part_number);
    if (i >= 0) {
        printf("Part name: %s\n", inventory[i].name);
        printf("Quantity: %d\n", inventory[i].on_hand);
    } else {
        printf("Part not found.\n");
    }
}

/*
 * update: Prompts the user to enter a part number.
 *         Prints an error if the part doesn't exist;
 *         otherwise, prompts the user to change the quantity
 *         and updates the db.
 */
void update(void)
{
    int i, part_number, change;
    printf("Enter a part number: ");
    scanf(" %d", &part_number);
    i = find(part_number);
    if (i >= 0) {
        printf("Enter change in quantity on hand: ");
        scanf(" %d", &change);
        inventory[i].on_hand += change;
    } else {
        printf("Part not found.\n");
    }
}

/*
 * Print: Prints a listing of all the parts in the database,
 *        showing part number, name, and quantity on hand.
 *        Parts are printed in the ordered entered.
 */
void print(void) 
{
    int i;
    printf("Part Number    Part Name                       "
           "Quantity On Hand\n");
    for (i = 0; i < num_parts; i++)
        printf("%7d       %-25s%11d\n", inventory[i].number,
                                        inventory[i].name,
                                        inventory[i].on_hand);
}
