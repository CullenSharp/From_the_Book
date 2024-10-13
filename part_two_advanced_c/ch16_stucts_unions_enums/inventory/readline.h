#ifndef READLINE_H
#define READLINE_H

/*
 * read_line: Skips leading whitespace, the reads the remainder of the input,
 *            storing it in a str. Truncates the line if it's longer than n.
 *            Returns number of characters stored.
 */
int read_line(char str[], int n);

#endif