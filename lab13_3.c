#include <stdio.h>

int main()
{
    int a[100];
    int *p;
    int n;
    int i;
    int sum = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    p = a;

    printf("Enter elements:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", p + i);
    }

    for (i = 0; i < n; i++)
    {
        sum = sum + *(p + i);
    }

    printf("Sum = %d", sum);

    return 0;
}
