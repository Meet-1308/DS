#include <stdio.h>

int main()
{
    int a[100];
    int *p;
    int n;
    int i;
    int largest;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    p = a;

    printf("Enter elements:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", p + i);
    }

    largest = *p;

    for (i = 1; i < n; i++)
    {
        if (*(p + i) > largest)
        {
            largest = *(p + i);
        }
    }

    printf("Largest element = %d", largest);

    return 0;
}
