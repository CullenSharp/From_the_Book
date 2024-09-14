#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define STACK_SIZE 100

char contents[STACK_SIZE];
int top = 0; // Reflects the number of items on the stack

void make_empty(void);
bool is_empty(void);
bool is_full(void);
void stack_overflow(void);
void stack_underflow(void);
void push(char ch);
char pop(void);

int main(void)
{
    char ch;

    printf("Enter parentheses and or braces: ");
    while((ch = getchar()) != '\n') {
        switch (ch) {
            case '[': case '{': case '(':
                push(ch);
                break;
            case ']': case '}': case ')':
                pop();
                break;
        }
    }

    if (is_empty())
        printf("Parentheses/braces are balanced.\n");
    else
        printf("Parentheses/braces are not balanced.\n");

    return 0;
}

void make_empty(void)
{
    top = 0;
}

bool is_empty(void)
{
    return top == 0;
}

bool is_full(void)
{
    return top == STACK_SIZE;
}

void stack_overflow(void)
{
    printf("Stack overflow!\n");
    exit(EXIT_FAILURE);
}

void stack_underflow(void)
{
    printf("Stack underflow!\n");
    exit(EXIT_FAILURE);
}

void push(char ch)
{
    if (is_full())
        stack_overflow();
    else
        contents[top++] = ch;
}

char pop(void)
{
    if (is_empty())
        stack_underflow();

    return contents[--top];
}