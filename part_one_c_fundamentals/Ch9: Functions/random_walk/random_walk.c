#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define ROWS    10
#define COLUMNS 10

void generate_random_walk(char walk[ROWS][COLUMNS]);
void print_array(char walk[ROWS][COLUMNS]);

int main(void)
{
    char walk[ROWS][COLUMNS];
    generate_random_walk(walk);
    print_array(walk);

    return 0;
}

void generate_random_walk(char walk[ROWS][COLUMNS])
{
    int move, row = 0, col = 0;
    bool dirs_tried[4] = {false};
    char mark = 'A';

    // Init walk
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            walk[i][j] = '.';
        }
    }

    // Gen seed
    srand((unsigned) time(NULL));
    
    while (mark <= 'Z') {
        /*
         * Move logic:
         *      Pick a random direction
         *      Check if we can move to that space (i.e. it's unvisited and not out of bounds).
         *      If not,
         *         record that we tried that direction, and
         *         try another direction at random.
         *      If so,
         *         reset the record for which directions have been tried, and
         *         move on to the next space.
         *      If stuck,
         *         terminate.
         *
         *           ^
         *           0
         *      < 3--+--1 >
         *           2
         *           v
        */

        move = rand() % 4;
        if (dirs_tried[0] && dirs_tried[1] && dirs_tried[2] && dirs_tried[3])
            break;
        walk[row][col] = mark;

        // If in first row
        if (row == 0) {
            // If in top left corner
            if (col == 0) {
                switch (move) {
                    case 1: 
                        dirs_tried[move] = true;
                        if (walk[row][col + 1] != '.') continue;
                        dirs_tried[0] = dirs_tried[1] = dirs_tried[2] = dirs_tried[3] = false;
                        mark++;
                        col++;
                        break;
                    case 2:
                        dirs_tried[move] = true;
                        if (walk[row + 1][col] != '.') continue;
                        dirs_tried[0] = dirs_tried[1] = dirs_tried[2] = dirs_tried[3] = false;
                        mark++;
                        row++;
                        break;
                    default:
                        dirs_tried[move] = true;
                        continue;
                }
            } 
            // If in the top right corner
            else if (col == 9) {
                switch (move) {
                    case 2:
                        dirs_tried[move] = true;
                        if (walk[row + 1][col] != '.') continue;
                        dirs_tried[0] = dirs_tried[1] = dirs_tried[2] = dirs_tried[3] = false;
                        mark++;
                        row++;
                        break;
                    case 3:
                        dirs_tried[move] = true;
                        if (walk[row][col - 1] != '.') continue;
                        dirs_tried[0] = dirs_tried[1] = dirs_tried[2] = dirs_tried[3] = false;
                        mark++;
                        col--;
                        break;
                    default:
                        dirs_tried[move] = true;
                        continue;
                }
            } else {
                switch (move) {
                    case 1:
                        dirs_tried[move] = true;
                        if (walk[row][col + 1] != '.') continue;
                        dirs_tried[0] = dirs_tried[1] = dirs_tried[2] = dirs_tried[3] = false;
                        mark++;
                        col++;
                        break;
                    case 2:
                        dirs_tried[move] = true;
                        if (walk[row + 1][col] != '.') continue;
                        dirs_tried[0] = dirs_tried[1] = dirs_tried[2] = dirs_tried[3] = false;
                        mark++;
                        row++;
                        break;
                    case 3:
                        dirs_tried[move] = true;
                        if (walk[row][col - 1] != '.') continue;
                        dirs_tried[0] = dirs_tried[1] = dirs_tried[2] = dirs_tried[3] = false;
                        mark++;
                        col--;
                        break;
                    default:
                        dirs_tried[move] = true;
                        continue;
                }
            }
        }

        // If along the bottom edge
        else if (row == 9) {
            // If in the bottom left corner
            if (col == 0) {
                switch (move) {
                    case 0:
                        dirs_tried[move] = true;
                        if (walk[row - 1][col] != '.') continue;
                        dirs_tried[0] = dirs_tried[1] = dirs_tried[2] = dirs_tried[3] = false;
                        mark++;
                        row--;
                        break;
                    case 1:
                        dirs_tried[move] = true;
                        if (walk[row][col + 1] != '.') continue;
                        dirs_tried[0] = dirs_tried[1] = dirs_tried[2] = dirs_tried[3] = false;
                        mark++;
                        col++;
                        break;
                    default:
                        dirs_tried[move] = true;
                        continue;
                }
            }

            // If in the bottom right corner
            else if (col == 9) {
                switch (move) {
                    case 0:
                        dirs_tried[move] = true;
                        if (walk[row - 1][col] != '.') continue;
                        dirs_tried[0] = dirs_tried[1] = dirs_tried[2] = dirs_tried[3] = false;
                        mark++;
                        row--;
                        break;
                    case 3:
                        dirs_tried[move] = true;
                        if (walk[row][col - 1] != '.') continue;
                        dirs_tried[0] = dirs_tried[1] = dirs_tried[2] = dirs_tried[3] = false;
                        mark++;
                        col--;
                        break;
                    default:
                        dirs_tried[move] = true;
                        continue;
                }

            } else {
                switch (move) {
                    case 0:
                        dirs_tried[move] = true;
                        if (walk[row - 1][col] != '.') continue;
                        dirs_tried[0] = dirs_tried[1] = dirs_tried[2] = dirs_tried[3] = false;
                        mark++;
                        row--;
                        break;
                    case 1:
                        dirs_tried[move] = true;
                        if (walk[row][col + 1] != '.') continue;
                        dirs_tried[0] = dirs_tried[1] = dirs_tried[2] = dirs_tried[3] = false;
                        mark++;
                        col++;
                        break;
                    case 3:
                        dirs_tried[move] = true;
                        if (walk[row][col - 1] != '.') continue;
                        dirs_tried[0] = dirs_tried[1] = dirs_tried[2] = dirs_tried[3] = false;
                        mark++;
                        col--;
                        break;
                    default:
                        dirs_tried[move] = true;
                        continue;
                }
            }

        }

        // If on the left edge
        else if (col == 0) {
           switch (move) {
                case 0:
                    dirs_tried[move] = true;
                    if (walk[row - 1][col] != '.') continue;
                    dirs_tried[0] = dirs_tried[1] = dirs_tried[2] = dirs_tried[3] = false;
                    mark++;
                    row--;
                    break;
                case 1:
                    dirs_tried[move] = true;
                    if (walk[row][col + 1] != '.') continue;
                    dirs_tried[0] = dirs_tried[1] = dirs_tried[2] = dirs_tried[3] = false;
                    mark++;
                    col++;
                    break;
                case 2:
                    dirs_tried[move] = true;
                    if (walk[row + 1][col] != '.') continue;
                    dirs_tried[0] = dirs_tried[1] = dirs_tried[2] = dirs_tried[3] = false;
                    mark++;
                    row++;
                    break;
                default:
                    dirs_tried[move] = true;
                    continue;
           }
            
        }
        // If on the right edge
        else if (col == 9) {
            switch (move) {
                case 0:
                    dirs_tried[move] = true;
                    if (walk[row - 1][col] != '.') continue;
                    dirs_tried[0] = dirs_tried[1] = dirs_tried[2] = dirs_tried[3] = false;
                    mark++;
                    row--;
                    break;
                case 2:
                    dirs_tried[move] = true;
                    if (walk[row + 1][col] != '.') continue;
                    dirs_tried[0] = dirs_tried[1] = dirs_tried[2] = dirs_tried[3] = false;
                    mark++;
                    row++;
                    break;
                case 3:
                    dirs_tried[move] = true;
                    if (walk[row][col - 1] != '.') continue;
                    dirs_tried[0] = dirs_tried[1] = dirs_tried[2] = dirs_tried[3] = false;
                    mark++;
                    col--;
                    break;
                default:
                    dirs_tried[move] = true;
                    continue;
            }
            
        } else {
            switch (move) {
                case 0:
                    dirs_tried[move] = true;
                    if (walk[row - 1][col] != '.') continue;
                    dirs_tried[0] = dirs_tried[1] = dirs_tried[2] = dirs_tried[3] = false;
                    mark++;
                    row--;
                    break;
                case 1:
                    dirs_tried[move] = true;
                    if (walk[row][col + 1] != '.') continue;
                    dirs_tried[0] = dirs_tried[1] = dirs_tried[2] = dirs_tried[3] = false;
                    mark++;
                    col++;
                    break;
                case 2:
                    dirs_tried[move] = true;
                    if (walk[row + 1][col] != '.') continue;
                    dirs_tried[0] = dirs_tried[1] = dirs_tried[2] = dirs_tried[3] = false;
                    mark++;
                    row++;
                    break;
                case 3:
                    dirs_tried[move] = true;
                    if (walk[row][col - 1] != '.') continue;
                    dirs_tried[0] = dirs_tried[1] = dirs_tried[2] = dirs_tried[3] = false;
                    mark++;
                    col--;
                    break;
            }
        }
    }
}

void print_array(char walk[ROWS][COLUMNS])
{
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf(" %c", walk[i][j]);
        }
        printf("\n");
    }
}