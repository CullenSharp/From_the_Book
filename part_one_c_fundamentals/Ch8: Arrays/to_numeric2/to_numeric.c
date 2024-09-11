#include <stdio.h>
#include <ctype.h>

#define SIZE ((int) sizeof(phone_number_alpha)/sizeof(phone_number_alpha[0]))

int main(void) 
{
    char phone_number_alpha[16], phone_number_numeric[16], ch;
    int i = 0;
    printf("Enter phone number: ");

    while ((ch = getchar()) != '\n')
        phone_number_alpha[i++] = ch;

    for (i = 0; i < SIZE; i++) {
        ch = phone_number_alpha[i];
        switch(toupper(ch)) {
            case 'A': case 'B': case 'C': 
                phone_number_numeric[i] = '2';
                break;
            case 'D': case 'E': case 'F':
                phone_number_numeric[i] = '3';
                break;
            case 'G': case 'H': case 'I':
                phone_number_numeric[i] = '4';
                break;
            case 'J': case 'K': case 'L':
                phone_number_numeric[i] = '5';
                break;
            case 'M': case 'N': case 'O':
                phone_number_numeric[i] = '6';
                break;
            case 'P': case 'R': case 'S':
                phone_number_numeric[i] = '7';
                break;
            case 'T': case 'U': case 'V':
                phone_number_numeric[i] = '8';
                break;
            case 'W': case 'X': case 'Y':
                phone_number_numeric[i] = '9';
                break;
            default:
                phone_number_numeric[i] = ch;
                break;
        }
    }

    for (int i = 0; i < SIZE; i++)
        printf("%c", phone_number_numeric[i]);
    
    printf("\n");

    return 0;
}