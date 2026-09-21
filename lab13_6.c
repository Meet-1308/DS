#include <stdio.h>
#include <string.h>

int main()
{
    char str[100];
    char *p;
    int i;
    int length;
    int flag = 0;

    printf("Enter a string: ");
    scanf("%s", str);

    p = str;

    length = strlen(str);

    for (i = 0; i < length / 2; i++)
    {
        if (*(p + i) != *(p + length - i - 1))
        {
            flag = 1;
            break;
        }
    }

    if (flag == 0)
    {
        printf("String is Palindrome.");
    }
    else
    {
        printf("String is not Palindrome.");
    }

    return 0;
}
