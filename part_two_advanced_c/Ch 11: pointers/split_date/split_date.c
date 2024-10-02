#include <stdio.h>

#define JAN 1
#define FEB 2
#define MAR 3
#define APR 4
#define MAY 5
#define JUN 6
#define JUL 7
#define AUG 8
#define SEP 9
#define OCT 10
#define NOV 11
#define DEC 12

void split_date(int day_of_the_year, int year,
                int *month, int *day);

int main(void)
{
    int month, day, year, day_of_the_year;

    printf("Enter day of the year (1-366): ");
    scanf(" %d", &day_of_the_year);

    printf("Enter year: ");
    scanf(" %d", &year);

    split_date(day_of_the_year, year, &month, &day);

    printf(" %d, %d, %d\n", month, day, year);

    return 0;
}

void split_date(int day_of_the_year, int year,
                int *month, int *day)
{

    /* normal year
    * Jan: [1,31]
    * Feb: [32, 59]
    * Mar: [60, 90]
    * Apr: [91, 120]
    * May: [121, 151]
    * Jun: [152, 181]
    * Jul: [182, 212]
    * Aug: [213, 243]
    * Sep: [244, 273]
    * Oct: [274, 304]
    * Nov: [305, 334]
    * Dec: [335, 365]
    */

    // Check if leap year
    if (year % 4 == 0) {
        if (day_of_the_year >= 1 && day_of_the_year <= 31) {
            *month = JAN;
            *day = day_of_the_year;
        } else if (day_of_the_year >= 32 && day_of_the_year <= 60) {
            *month = FEB;
            *day = day_of_the_year - 31;
        } else if (day_of_the_year >= 61 && day_of_the_year <= 91) {
            *month = MAR;
            *day = day_of_the_year - 60;
        } else if (day_of_the_year >= 92 && day_of_the_year <= 121) {
            *month = APR;
            *day = day_of_the_year - 91;
        } else if (day_of_the_year >= 122 && day_of_the_year <= 152) {
            *month = MAY;
            *day = day_of_the_year - 121;
        } else if (day_of_the_year >= 153 && day_of_the_year <= 182) {
            *month = JUN;
            *day = day_of_the_year - 152;
        } else if (day_of_the_year >= 183 && day_of_the_year <= 213) {
            *month = JUL;
            *day = day_of_the_year - 182;
        } else if (day_of_the_year >= 214 && day_of_the_year <= 244) {
            *month = AUG;
            *day = day_of_the_year - 213;
        } else if (day_of_the_year >= 245 && day_of_the_year <= 274) {
            *month = SEP;
            *day = day_of_the_year - 244;
        } else if (day_of_the_year >= 275 && day_of_the_year <= 305) {
            *month = OCT;
            *day = day_of_the_year - 274;
        } else if (day_of_the_year >= 306 && day_of_the_year <= 335) {
            *month = NOV;
            *day = day_of_the_year - 305;
        } else if (day_of_the_year >= 336 && day_of_the_year <= 366) {
            *month = DEC;
            *day = day_of_the_year - 335;
        }
    } else {
        if (day_of_the_year >= 1 && day_of_the_year <= 31) {
            *month = JAN;
            *day = day_of_the_year;
        } else if (day_of_the_year >= 32 && day_of_the_year <= 59) {
            *month = FEB;
            *day = day_of_the_year - 31;
        } else if (day_of_the_year >= 60 && day_of_the_year <= 90) {
            *month = MAR;
            *day = day_of_the_year - 59;
        } else if (day_of_the_year >= 91 && day_of_the_year <= 120) {
            *month = APR;
            *day = day_of_the_year - 90;
        } else if (day_of_the_year >= 121 && day_of_the_year <= 151) {
            *month = MAY;
            *day = day_of_the_year - 120;
        } else if (day_of_the_year >= 152 && day_of_the_year <= 181) {
            *month = JUN;
            *day = day_of_the_year - 151;
        } else if (day_of_the_year >= 182 && day_of_the_year <= 212) {
            *month = JUL;
            *day = day_of_the_year - 181;
        } else if (day_of_the_year >= 213 && day_of_the_year <= 243) {
            *month = AUG;
            *day = day_of_the_year - 212;
        } else if (day_of_the_year >= 244 && day_of_the_year <= 273) {
            *month = SEP;
            *day = day_of_the_year - 243;
        } else if (day_of_the_year >= 274 && day_of_the_year <= 304) {
            *month = OCT;
            *day = day_of_the_year - 273;
        } else if (day_of_the_year >= 305 && day_of_the_year <= 334) {
            *month = NOV;
            *day = day_of_the_year - 304;
        } else if (day_of_the_year >= 335 && day_of_the_year <= 365) {
            *month = DEC;
            *day = day_of_the_year - 334;
        }
    }
}