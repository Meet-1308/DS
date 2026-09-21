#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *i;
    char *c;
    float *f;

    i = (int *)malloc(sizeof(int));
    c = (char *)malloc(sizeof(char));
    f = (float *)malloc(sizeof(float));

    if (i == NULL || c == NULL || f == NULL)
    {
        printf("Memory not allocated.\n");
        return 0;
    }

    printf("Enter integer: ");
    scanf("%d", i);

    printf("Enter character: ");
    scanf(" %c", c);

    printf("Enter float: ");
    scanf("%f", f);

    printf("\nInteger = %d\n", *i);
    printf("Character = %c\n", *c);
    printf("Float = %.2f\n", *f);

    free(i);
    free(c);
    free(f);

    printf("\nMemory de-allocated successfully.\n");

    return 0;
}
