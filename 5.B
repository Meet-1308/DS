#include <stdio.h>
#include <string.h>

#define SIZE 100

char stack[SIZE];
int top = -1;

void push(char x)
{
    top++;
    stack[top] = x;
}

void pop()
{
    if (top != -1)
    {
        top--;
    }
}

void removeStars(char str[])
{
    int i;

    top = -1;

    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '*')
        {
            pop();
        }
        else
        {
            push(str[i]);
        }
    }
    stack[top + 1] = '\0';

    printf("%s\n", stack);
}

int main()
{
    char str[SIZE];

    printf("Enter string: ");
    scanf("%s", str);

    removeStars(str);

    return 0;
}
