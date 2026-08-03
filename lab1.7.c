#include <stdio.h>

int main()
{
    int num, temp, duck = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    temp = num;

    while (temp > 0)
    {
        if (temp % 10 == 0)
        {
            duck = 1;
            break;
        }
        temp = temp / 10;
    }

    if (duck)
        printf("Duck Number");
    else
        printf("Not a Duck Number");

    return 0;
}