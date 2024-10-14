/**
* @file
* @author Cullen Sharp
* @version 1.0
*
* @section LICENSE
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License as
* published by the Free Software Foundation; either version 2 of
* the License, or (at your option) any later version.
*
* @section DESCRIPTION
*
* Provides the implementation for functions taking character input
*/
#include <stdio.h>
#include "word.h"

/**
 * Reads characters from input.
 * If the character is '\n' or '\t', converts the character to a ' '
 * 
 * @returns a character
 */
int read_char(void)
{
    int ch = getchar();

    if (ch == '\n' || ch == '\n')
        return ' ';
    return ch;
}

void read_word(char* word, int len)
{
    int ch, pos = 0;

    // Skips over any spaces
    while ((ch = getchar()) == ' ')
        ;

    // EOF is a non-blank character
    // Continues to read past len, but won't record to word
    while (ch != ' ' && ch != EOF) {
        if (pos < len)
            word[pos++] = ch;
        ch = read_char();
    }

    word[pos] = '\0';
}