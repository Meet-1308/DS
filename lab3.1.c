
#include <stdio.h>

int main()
{
    int a[100], n, num, i, pos;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter elements in ascending order:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter number to insert: ");
    scanf("%d", &num);

    // Find position
    for(i = 0; i < n; i++)
    {
        if(a[i] > num)
        {
            break;
        }
    }

    pos = i;

    // Shift elements to the right
    for(i = n; i > pos; i--)
    {
        a[i] = a[i - 1];
    }

    // Insert number
    a[pos] = num;
    n++;

    printf("Array after insertion:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}