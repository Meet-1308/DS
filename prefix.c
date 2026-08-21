#include <stdio.h>
#include <string.h>

#define n 50

char s[n];
int top = -1;

void push(char x)
{
    if (top == n - 1)
    {
        printf("Overflow");
        return;
    }

    top++;
    s[top] = x;
}

char pop()
{
    char x;

    if (top == -1)
        return '\0';

    x = s[top];
    top--;

    return x;
}

int f(char x)
{
    if (x == '+' || x == '-')
        return 1;

    if (x == '*' || x == '/')
        return 3;

    if (x == '^')
        return 6;

    if (x == '(')
        return 9;

    if (x == ')')
        return 0;

    return 7;
}

int g(char x)
{
    if (x == '+' || x == '-')
        return 2;

    if (x == '*' || x == '/')
        return 4;

    if (x == '^')
        return 5;

    if (x == '(')
        return 0;

    return 8;
}

int r(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/' || x == '^')
        return -1;

    if (x == '(' || x == ')')
        return 0;

    return 1;
}

void prefix(char infix[], char result[])
{
    char temp[n];
    char next;
    char x;

    int i, j;

    /* Step 1: Reverse infix */
    int len = strlen(infix);

    for (i = 0; i < len; i++)
    {
        if (infix[len - 1 - i] == '(')
            temp[i] = ')';
        else if (infix[len - 1 - i] == ')')
            temp[i] = '(';
        else
            temp[i] = infix[len - 1 - i];
    }

    temp[len] = '\0';

    /* Step 2: Convert reversed expression to postfix */
    top = -1;
    push('(');

    strcat(temp, ")");

    i = 0;
    j = 0;

    next = temp[i];

    while (next != '\0')
    {
        if (r(next) == 1)
        {
            result[j] = next;
            j++;
        }
        else
        {
            while (g(s[top]) > f(next))
            {
                x = pop();
                result[j] = x;
                j++;
            }

            if (g(s[top]) != f(next))
                push(next);
            else
                pop();
        }

        i++;
        next = temp[i];
    }

    result[j] = '\0';
    len = strlen(result);

    for (i = 0; i < len / 2; i++)
    {
        x = result[i];
        result[i] = result[len - 1 - i];
        result[len - 1 - i] = x;
    }

    printf("Prefix = %s", result);
}

int main()
{
    char infix[n];
    char result[n];

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    prefix(infix, result);

    return 0;
}
