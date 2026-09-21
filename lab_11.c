#include <stdio.h>
#define N 5
int F = -1;
int R = -1;
int DEQ[N];
void insert_REAR(int y)
{
    if (R == N - 1)
    {
        printf("Double Ended Queue Overflow.\n");
        return;
    }

    R++;
    DEQ[R] = y;

    if (F == -1)
        F = 0;
}


void insert_FRONT(int y)
{
    if (F == 0)
    {
        printf("Double Ended Queue Overflow.\n");
        return;
    }

    if (F == -1)
    {
        F = R = 0;
    }
    else
    {
        F--;
    }

    DEQ[F] = y;
}


int delete_FRONT()
{
    int y;

    if (F == -1)
    {
        printf("Double Ended Queue Underflow.\n");
        return -1;
    }

    y = DEQ[F];

    if (F == R)
    {
        F = R = -1;
    }
    else
    {
        F++;
    }

    return y;
}


int delete_REAR()
{
    int y;

    if (R == -1)
    {
        printf("Double Ended Queue Underflow.\n");
        return -1;
    }

    y = DEQ[R];

    if (F == R)
    {
        F = R = -1;
    }
    else
    {
        R--;
    }

    return y;
}


void display()
{
    int i;

    if (F == -1)
    {
        printf("Double Ended Queue Underflow.\n");
        return;
    }

    printf("Queue elements are:\n");

    for (i = F; i <= R; i++)
    {
        printf("%d\t", DEQ[i]);
    }

    printf("\n");
}

int main()
{
    int choice;
    int value;
    int deleted;

    do
    {
        printf("\n--- DOUBLE ENDED QUEUE ---\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at Rear\n");
        printf("3. Delete from Front\n");
        printf("4. Delete from Rear\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);

                insert_FRONT(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);

                insert_REAR(value);
                break;

            case 3:
                deleted = delete_FRONT();

                if (deleted != -1)
                {
                    printf("Deleted element is: %d\n", deleted);
                }
                break;

            case 4:
                deleted = delete_REAR();

                if (deleted != -1)
                {
                    printf("Deleted element is: %d\n", deleted);
                }
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Program Ended.\n");
                break;

            default:
                printf("Invalid Choice.\n");
        }

    } while (choice != 6);

    return 0;
}
