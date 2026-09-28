#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* createNode(int data)
{
    struct Node *newNode;

    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

void display(struct Node *head)
{
    struct Node *temp = head;

    while (temp != NULL)
    {
        printf("%d", temp->data);

        if (temp->next != NULL)
            printf(" -> ");

        temp = temp->next;
    }
}

void insertGCD(struct Node *head)
{
    struct Node *temp;
    struct Node *newNode;
    int g;

    temp = head;

    while (temp != NULL && temp->next != NULL)
    {
        g = gcd(temp->data, temp->next->data);

        newNode = createNode(g);

        newNode->next = temp->next;
        temp->next = newNode;

        temp = newNode->next;
    }
}

void main()
{
    struct Node *head = NULL;
    struct Node *temp;
    int n, data, i;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++)
    {
        printf("Enter data: ");
        scanf("%d", &data);

        if (head == NULL)
        {
            head = createNode(data);
            temp = head;
        }
        else
        {
            temp->next = createNode(data);
            temp = temp->next;
        }
    }

    printf("\nOriginal List: ");
    display(head);

    insertGCD(head);

    printf("\n\nAfter inserting GCD: ");
    display(head);

    return 0;
}
