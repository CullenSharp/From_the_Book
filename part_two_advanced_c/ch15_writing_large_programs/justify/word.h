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
* Provides prototypes for taking character input
*/
#ifndef WORD_H  
#define WORD_H

/**
 * Reads the next word from input and
 * stores it in word. Makes word empty if
 * no word could be read or EOF.
 * Truncates the word if it exceeds len.
 */
void read_word(char* word, int len);
#endif