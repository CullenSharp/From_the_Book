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
* Provides prototypes for line manipulation utils
*/
#ifndef LINE_H
#define LINE_H

/**
 * Clears the current line
 */
void clear_line(void);

/**
 * Adds word to the end of the current line
 * If it isn't the first word on the line,
 * it adds a space before it
 * 
 * @param Word to be added to the line
 */
void add_word(const char* word);

/**
 * Returns the number of characters remaining in the line
 * @returns The number characters remaining in the line
 */
int space_remaining(void);

/**
 * Writes the current line with justification
 */
void write_line(void);

/**
 * Writes the current line without justification.
 * If the line is empty, does nothing.
 */
void flush_line(void);

#endif