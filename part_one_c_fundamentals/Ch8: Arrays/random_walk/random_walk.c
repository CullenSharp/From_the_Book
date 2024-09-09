#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define ROWS    10
#define COLUMNS 10

int main(void)
{
    char board[ROWS][COLUMNS];
    int move, row = 0, col = 0, dirs_tried[4] = {false};
    char mark = 'A';

    // Init board
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            board[i][j] = '.';
        }
    }

    // Gen seed
    srand((unsigned) time(NULL));
    
    while (mark <= 'Z') {
        /*
         * Move logic:
         *      Pick a random direction
         *      Check if we can move to that space (i.e. it's unvisited and not out of bounds).
         *      Move to that space
         *
         *           ^
         *           0
         *      < 3--+--1 >
         *           2
         *           v
        */

        move = rand() % 4;
        if (dirs_tried[0] && dirs_tried[1] && dirs_tried[2] & dirs_tried[3])
            break;
        board[row][col] = mark;
        //printf("Current Pos: (%d,%d) \t Current Move: %d\n", row, col, move);

        // If in first row
        if (row == 0) {
            // If in top left corner
            if (col == 0) {
                switch (move) {
                    case 1: 
                        dirs_tried[move] = true;
                        if (board[row][col + 1] != '.') continue;
                        dirs_tried[0] = dirs_tried[1] = dirs_tried[2] = dirs_tried[3] = 0;
                        mark++;
                        col++;
                        break;
                    case 2:
                        dirs_tried[move] = true;
                        if (board[row + 1][col] != '.') continue;
                        dirs_tried[0] = dirs_tried[1] = dirs_tried[2] = dirs_tried[3] = 0;
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
                        if (board[row + 1][col] != '.') continue;
                        dirs_tried[0] = dirs_tried[1] = dirs_tried[2] = dirs_tried[3] = 0;
                        mark++;
                        row++;
                        break;
                    case 3:
                        dirs_tried[move] = true;
                        if (board[row][col - 1] != '.') continue;
                        dirs_tried[0] = dirs_tried[1] = dirs_tried[2] = dirs_tried[3] = 0;
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
                        if (board[row][col + 1] != '.') continue;
                        dirs_tried[0] = dirs_tried[1] = dirs_tried[2] = dirs_tried[3] = 0;
                        mark++;
                        col++;
                        break;
                    case 2:
                        dirs_tried[move] = true;
                        if (board[row + 1][col] != '.') continue;
                        dirs_tried[0] = dirs_tried[1] = dirs_tried[2] = dirs_tried[3] = 0;
                        mark++;
                        row++;
                        break;
                    case 3:
                        dirs_tried[move] = true;
                        if (board[row][col - 1] != '.') continue;
                        dirs_tried[0] = dirs_tried[1] = dirs_tried[2] = dirs_tried[3] = 0;
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
                        if (board[row - 1][col] != '.') continue;
                        dirs_tried[0] = dirs_tried[1] = dirs_tried[2] = dirs_tried[3] = 0;
                        mark++;
                        row--;
                        break;
                    case 1:
                        dirs_tried[move] = true;
                        if (board[row][col + 1] != '.') continue;
                        dirs_tried[0] = dirs_tried[1] = dirs_tried[2] = dirs_tried[3] = 0;
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
                        if (board[row - 1][col] != '.') continue;
                        dirs_tried[0] = dirs_tried[1] = dirs_tried[2] = dirs_tried[3] = 0;
                        mark++;
                        row--;
                        break;
                    case 3:
                        dirs_tried[move] = true;
                        if (board[row][col - 1] != '.') continue;
                        dirs_tried[0] = dirs_tried[1] = dirs_tried[2] = dirs_tried[3] = 0;
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
                        if (board[row - 1][col] != '.') continue;
                        dirs_tried[0] = dirs_tried[1] = dirs_tried[2] = dirs_tried[3] = 0;
                        mark++;
                        row--;
                        break;
                    case 1:
                        dirs_tried[move] = true;
                        if (board[row][col + 1] != '.') continue;
                        dirs_tried[0] = dirs_tried[1] = dirs_tried[2] = dirs_tried[3] = 0;
                        mark++;
                        col++;
                        break;
                    case 3:
                        dirs_tried[move] = true;
                        if (board[row][col - 1] != '.') continue;
                        dirs_tried[0] = dirs_tried[1] = dirs_tried[2] = dirs_tried[3] = 0;
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
                    if (board[row - 1][col] != '.') continue;
                    dirs_tried[0] = dirs_tried[1] = dirs_tried[2] = dirs_tried[3] = 0;
                    mark++;
                    row--;
                    break;
                case 1:
                    dirs_tried[move] = true;
                    if (board[row][col + 1] != '.') continue;
                    dirs_tried[0] = dirs_tried[1] = dirs_tried[2] = dirs_tried[3] = 0;
                    mark++;
                    col++;
                    break;
                case 2:
                    dirs_tried[move] = true;
                    if (board[row + 1][col] != '.') continue;
                    dirs_tried[0] = dirs_tried[1] = dirs_tried[2] = dirs_tried[3] = 0;
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
                    if (board[row - 1][col] != '.') continue;
                    dirs_tried[0] = dirs_tried[1] = dirs_tried[2] = dirs_tried[3] = 0;
                    mark++;
                    row--;
                    break;
                case 2:
                    dirs_tried[move] = true;
                    if (board[row + 1][col] != '.') continue;
                    dirs_tried[0] = dirs_tried[1] = dirs_tried[2] = dirs_tried[3] = 0;
                    mark++;
                    row++;
                    break;
                case 3:
                    dirs_tried[move] = true;
                    if (board[row][col - 1] != '.') continue;
                    dirs_tried[0] = dirs_tried[1] = dirs_tried[2] = dirs_tried[3] = 0;
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
                    if (board[row - 1][col] != '.') continue;
                    dirs_tried[0] = dirs_tried[1] = dirs_tried[2] = dirs_tried[3] = 0;
                    mark++;
                    row--;
                    break;
                case 1:
                    dirs_tried[move] = true;
                    if (board[row][col + 1] != '.') continue;
                    dirs_tried[0] = dirs_tried[1] = dirs_tried[2] = dirs_tried[3] = 0;
                    mark++;
                    col++;
                    break;
                case 2:
                    dirs_tried[move] = true;
                    if (board[row + 1][col] != '.') continue;
                    dirs_tried[0] = dirs_tried[1] = dirs_tried[2] = dirs_tried[3] = 0;
                    mark++;
                    row++;
                    break;
                case 3:
                    dirs_tried[move] = true;
                    if (board[row][col - 1] != '.') continue;
                    dirs_tried[0] = dirs_tried[1] = dirs_tried[2] = dirs_tried[3] = 0;
                    mark++;
                    col--;
                    break;
            }
        }
    }
    


    // Show board
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            //printf(" %d,%d", i, j);
            printf(" %c", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}