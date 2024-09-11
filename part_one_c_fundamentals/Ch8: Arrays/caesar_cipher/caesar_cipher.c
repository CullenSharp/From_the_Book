#include <stdio.h>

int main(void) 
{
    char message[80], encrypted_message[80], ch;
    int i = 0, shift;

    printf("Enter a message to be encrypted: ");
    while((ch = getchar()) != '\n')
    {
        message[i++] = ch;
    }

    printf("Enter shift amount (1-25): ");
    scanf("%d", &shift);

    i = 0;
    // While printable
    while (message[i] >= ' ' && message[i] <= '~')
    {
        if (message[i] >= 'A' && message[i] <= 'Z')
        {
            encrypted_message[i] = ((message[i] - 'A') + shift) % 26 + 'A';
        }
        else if (message[i] >= 'a' && message[i] <= 'z')
        {
            encrypted_message[i] = ((message[i] - 'a') + shift) % 26 + 'a';
        }
        else
        {
            encrypted_message[i] = message[i];
        }

        i++;
    }
    
    printf("Encrypted message: %s\n", encrypted_message);
    return 0;
}