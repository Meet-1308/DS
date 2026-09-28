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

void swapPairs(struct Node **head)
{
    struct Node *temp;
    struct Node *first;
    struct Node *second;

    temp = *head;

    while (temp != NULL && temp->next != NULL)
    {
        first = temp;
        second = temp->next;

        first->next = second->next;
        second->next = first;

        if (first == *head)
            *head = second;

        temp = first->next;
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

    swapPairs(&head);

    printf("\n\nAfter swapping consecutive nodes: ");
    display(head);

    return 0;
}
