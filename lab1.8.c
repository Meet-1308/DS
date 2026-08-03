#include <stdio.h>

int main()
{
    int num, temp, sum = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    temp = num;

    while (temp > 0)
    {
        sum = sum + (temp % 10);
        temp = temp / 10;
    }

    if (num % sum == 0)
        printf("Harshad Number");
    else
        printf("Not a Harshad Number");

    return 0;
}