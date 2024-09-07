#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int i_hrs, i_mins, period, t;

    printf("Enter a 12-hour time: ");
    scanf("%d:%d ", &i_hrs, &i_mins);

    // AM -> ante meridiem; PM -> post meridiem
    period = getchar();
    if (toupper(period) == 'A')
    {
        if (i_hrs == 12) t = i_mins;
        else             t = 60 * i_hrs + i_mins;
    }
    else
    {
        if (i_hrs == 12) t = 60 * i_hrs + i_mins;
        else             t = 60 * (i_hrs + 12) + i_mins;
    }

    if (t >= 173 && t < 532)
    {
        printf("Closest departure time is %s, arriving at %s.\n",
        "8:00 a.m.", "10:16 a.m.");
    } 
    else if (t >= 532 && t < 631)
    {
        printf("Closest departure time is %s, arriving at %s.\n",
        "9:43 a.m.", "11:52 a.m.");
    } 
    else if (t >= 631 && t < 723)
    {
        printf("Closest departure time is %s, arriving at %s.\n",
        "11:19 a.m.", "1:31 p.m.");
    } 
    else if (t >= 723 && t < 804)
    {
        printf("Closest departure time is %s, arriving at %s.\n",
        "12:47 p.m.", "3:00 p.m.");
    } 
    else if (t >= 804 && t < 893)
    {
        printf("Closest departure time is %s, arriving at %s.\n",
        "2:00 p.m.", "4:08 p.m.");
    } 
    else if (t >= 893 && t < 1043)
    {
        printf("Closest departure time is %s, arriving at %s.\n",
        "3:45 p.m.", "5:55 p.m.");
    } 
    else if (t >= 1043 && t < 1223)
    {
        printf("Closest departure time is %s, arriving at %s.\n",
        "7:00 p.m.", "9:20 p.m.");
    }
    else if ((t >= 1223 && t <= 1439) || (t >= 0 && t < 173))
    {
        printf("Closest departure time is %s, arriving at %s.\n",
        "9:45 p.m.", "11:58 p.m.");
    }

    return 0;
}