#include <stdio.h>

/*
 * Evaluates an expression from left to right without respect to operator precedence
 * Only accepts numbers from [0.0, 9.9]
 * 
 * example run
 *    Enter expression: 1+2.5*3/4-1
 *    Value of expression: 1.62
*/

int main(void) {
    char ch;
    float result = 0.0;

    printf("Enter expression: ");
    while((ch = getchar()) != '\n')
    {
        /*
         * The ASCII standard encodes digits sequentially
         *
         * | Glyph |   Hex  |
         * |-------|--------|
         * |   0   |  0x30  |
         * |   1   |  0x31  |
         * |   2   |  0x32  |
         * |   3   |  0x33  |
         * |   4   |  0x34  |
         * |   5   |  0x35  |
         * |   6   |  0x36  |
         * |   7   |  0x37  |
         * |   8   |  0x38  |
         * |   9   |  0x39  |
         * 
         * Thus by shifting characters over by 0x30, each character
         * will represent its digital value (e.g. '1' - '0' = 1).
        */

        switch(ch) {
            case '+':
                ch = getchar();                  // Get next char
                result += ch - '0';              // Shift char to decimal value
                break;
            case '-':
                ch = getchar();
                result -= ch - '0';
                break;
            case '*':
                ch = getchar();
                result *= ch - '0';
                break;
            case '/':
                ch = getchar();
                result /= ch - '0';
                break;
            case '.':
                // ex 2.5
                ch = getchar();
                // cast to float before division for more precision
                result += (float) (ch - '0')/10; 
                break;
            default:
                result += ch - '0';
                break;
        }
    }

    printf("Value of expression: %.2f\n", result);
    return 0;
}