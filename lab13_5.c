#include <stdio.h>

int main()
{
    int a[100];
    int *p;
    int n;
    int i, j;
    int temp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    p = a;

    printf("Enter elements:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", p + i);
    }

    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (*(p + i) > *(p + j))
            {
                temp = *(p + i);
                *(p + i) = *(p + j);
                *(p + j) = temp;
            }
        }
    }

    printf("Sorted array:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d ", *(p + i));
    }

    return 0;
}
