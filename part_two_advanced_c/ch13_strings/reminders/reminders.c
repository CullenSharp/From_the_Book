#include <stdio.h>
#include <string.h>

#define MAX_REMIND 50
#define MSG_LEN 60

int read_line(char str[], int n);

int main(void)
{
    char reminders[MAX_REMIND][MSG_LEN + 3];
    char day_str[3], msg_str[MSG_LEN + 1];
    int day, i, j, num_remind = 0;

    for (;;) {
        if (num_remind == MAX_REMIND) {
            printf("-- No space left -- \n");
            break;
        }

        printf("Enter day and reminder: ");
        scanf("%2d", &day);

        if (day == 0)
            break;
        
        // Takes formatted output and stores it in a string
        sprintf(day_str, "%2d", day);
        read_line(msg_str, MSG_LEN);

        // Find place in day order
        // Since the date comes first, 
        // using strcmp enables us to sort reminders chronologically
        // With reminders occurring Earlier in the month at the "top"
        for (i = 0; i < num_remind; i++)
            if (strcmp(day_str, reminders[i]) < 0)
                break;

        // Move all elements from i+1 to n right one space
        for (j = num_remind; j > i; j--)
            strcpy(reminders[j], reminders[j-1]);

        strcpy(reminders[i], day_str);
        strcat(reminders[i], msg_str);

        num_remind++;
    }

    // Show list
    printf("\nDay Reminder\n");
    for(i = 0;i < num_remind; i++)
        printf(" %s\n", reminders[i]);
    
    return 0;
}

int read_line(char str[], int n)
{
    int ch, i = 0;

    while((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';
    return i;
}