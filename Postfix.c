#include <stdio.h>
#include <string.h>

#define n 50

char s[n];
int top=-1;

void push(char x)
{
    if(top==n-1)
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

    if(top==-1)
    {
        return '\0';
    }

    x =s[top];
    top--;

    return x;
}

int f(char x)
{
    if(x=='+'||x=='-')
        return 1;

    if(x =='*'|| x =='/')
        return 3;

    if(x =='^')
        return 6;

    if(x =='(')
        return 9;

    if(x ==')')
        return 0;

    return 7;       
}

int g(char x)
{
    if(x =='+'|| x=='-')
        return 2;

    if(x =='*'|| x=='/')
        return 4;

    if(x =='^')
        return 5;

    if(x =='(')
        return 0;

    return 8;      
}

int r(char x)
{
    if(x == '+' || x == '-' || x == '*' || x == '/' || x == '^')
        return -1;

    if(x == '(' || x == ')')
        return 0;

    return 1;
}

void revpol(char infix[], char polish[])
{
    char next;
    char temp;
    int rank = 0;
    int i = 0;
    int j = 0;

  
    top = -1;
    push('(');


    strcat(infix, ")");
    next = infix[i];

    while(next != '\0')
{
    if(r(next) == 1)
    {
        polish[j] = next;
        j++;

        rank = rank + r(next);
    }
    else
    {
        while(g(s[top]) > f(next))
        {
            temp = pop();

            polish[j] = temp;
            j++;

            rank = rank + r(temp);

            if(rank < 1)
            {
                printf("Invalid");
                return;
            }
        }

        if(g(s[top]) != f(next))
        {
            push(next);
        }
        else
        {
            pop();
        }
    }

    i++;
    next = infix[i];
}

    if(top != -1 || rank != 1)
    {
        printf("Invalid Expression");
        return;
    }

    polish[j] = '\0';

    printf("Postfix = %s", polish);
}

int main()
{
    char infix[n];
    char polish[n];

    printf("Enter Infix Expression: ");
    scanf("%s", infix);

    revpol(infix, polish);

    return 0;
}
