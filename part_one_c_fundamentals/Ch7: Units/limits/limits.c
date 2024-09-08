#include <stdio.h>
#include <limits.h>

int main(void) {
    int a = 017, b = 077, c = 0777, d = 07777;

    printf("%x\n", a);
    printf("%d\n", b);
    printf("%d\n", c);
    printf("%d\n", d);
    return 0;
}