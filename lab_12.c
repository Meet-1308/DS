#include <stdio.h>

#define N 5

struct PriorityQueue
{
    int element;
    int priority;
};

struct PriorityQueue PQ[N];

int F = -1;
int R = -1;


void enqueue(int x, int y)
{
    if (R == N - 1)
    {
        printf("Priority Queue Overflow.\n");
        return;
    }

    R++;

    PQ[R].element = x;
    PQ[R].priority = y;

    if (F == -1)
    {
        F = 0;
    }
}

void dequeue(int type)
{
    int i;
    int index;
    struct PriorityQueue temp;

    if (F == -1)
    {
        printf("Priority Queue Underflow.\n");
        return;
    }

    if (F == R)
    {
        printf("Element Deleted: %d\n", PQ[F].element);
        printf("Priority: %d\n", PQ[F].priority);

        F = R = -1;
        return;
    }


    if (type == 1)
    {
        index = F;

        for (i = F + 1; i <= R; i++)
        {
            if (PQ[i].priority < PQ[index].priority)
            {
                index = i;
            }
        }
    }


    else
    {
        index = F;

        for (i = F + 1; i <= R; i++)
        {
            if (PQ[i].priority > PQ[index].priority)
            {
                index = i;
            }
        }
    }


    printf("Element Deleted: %d\n", PQ[index].element);
    printf("Priority: %d\n", PQ[index].priority);


    for (i = index; i < R; i++)
    {
        PQ[i] = PQ[i + 1];
    }

    R--;
}

void display()
{
    int i;

    if (F == -1)
    {
        printf("Priority Queue Underflow.\n");
        return;
    }

    printf("\nPRIORITY QUEUE:\n");

    for (i = F; i <= R; i++)
    {
        printf("%d : %d\n",
               PQ[i].element,
               PQ[i].priority);
    }
}

int main()
{
    int choice;
    int element;
    int priority;
    int type;

    printf("Enter Priority Queue Type:\n");
    printf("1. Ascending\n");
    printf("2. Descending\n");
    printf("Enter choice: ");
    scanf("%d", &type);

    do
    {
        printf("\n--- PRIORITY QUEUE MENU ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:

                printf("Enter element: ");
                scanf("%d", &element);

                printf("Enter priority: ");
                scanf("%d", &priority);

                enqueue(element, priority);

                break;


            case 2:

                dequeue(type);

                break;


            case 3:

                display();

                break;


            case 4:

                printf("Program Ended.\n");

                break;


            default:

                printf("Invalid Choice.\n");
        }

    } while (choice != 4);

    return 0;
}
