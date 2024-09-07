#include <stdio.h>

int main(void)
{
    int d1, d2;

    printf("Enter two-digit number: ");
    scanf("%1d%1d", &d1, &d2);

    printf("You entered the number: ");
    switch (d1) {
        case 9: printf("%s", d2 != 0 ? "ninety-" : "ninety");   break;
        case 8: printf("%s", d2 != 0 ? "eighty-" : "eighty");   break;
        case 7: printf("%s", d2 != 0 ? "seventy-" : "seventy"); break;
        case 6: printf("%s", d2 != 0 ? "sixty-" : "sixty");     break;
        case 5: printf("%s", d2 != 0 ? "fifty-" : "fifty");     break;
        case 4: printf("%s", d2 != 0 ? "forty-" : "forty");     break;
        case 3: printf("%s", d2 != 0 ? "thirty-" : "thirty");   break;
        case 2: printf("%s", d2 != 0 ? "twenty-" : "twenty");   break;
        default: printf("");                                    break;
    }

    if (d1 == 1)
        switch (d2) {
            case 9: printf("nineteen");  break;
            case 8: printf("eighteen");  break;
            case 7: printf("seventeen"); break;
            case 6: printf("sixteen");   break;
            case 5: printf("fifteen");   break;
            case 4: printf("fourteen");  break;
            case 3: printf("thirteen");  break;
            case 2: printf("twelve");    break;
            case 1: printf("eleven");    break;
            case 0: printf("ten");       break;
        }
    else
        switch (d2) {
            case 9: printf("nine");   break;
            case 8: printf("eight");  break;
            case 7: printf("seven");  break;
            case 6: printf("six");    break;
            case 5: printf("five");   break;
            case 4: printf("four");   break;
            case 3: printf("three");  break;
            case 2: printf("two");    break;
            case 1: printf("one");    break;
            case 0: 
                if (d1 != 0) printf("");
                else         printf("zero");
                break;
        }
    printf("\n");
    return 0;
}