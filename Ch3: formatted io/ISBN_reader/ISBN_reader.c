#include <stdio.h>

int main(void)
{
    int gs1, group_id, pub_code, itm_num, chk_digit;
    printf("Enter ISBN: ");
    scanf("%d-%d-%d-%d-%d", &gs1, &group_id, &pub_code, &itm_num, &chk_digit);

    printf("GS1 Prefix: %d\n", gs1);
    printf("Publisher Code: %d\n", pub_code);
    printf("Group ID: %d\n", group_id);
    printf("Item Number: %d\n", itm_num);
    printf("Check Digit: %d\n", chk_digit);

    return 0;
}