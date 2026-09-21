#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *head = NULL;


void insertFront()
{
    struct Node *newNode;
    int value;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = head;

    head = newNode;

    printf("Node inserted at front.\n");
}


void insertEnd()
{
    struct Node *newNode;
    struct Node *temp;
    int value;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    printf("Node inserted at end.\n");
}


void orderedInsertion()
{
    struct Node *newNode;
    struct Node *temp;
    int value;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    printf("Enter value: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL || value < head->data)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL &&
               temp->next->data < value)
        {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    printf("Node inserted in ordered manner.\n");
}


void display()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("Linked List is empty.\n");
        return;
    }

    temp = head;

    printf("Linked List:\n");

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void deleteFirst()
{
    struct Node *temp;

    if (head == NULL)
    {
        printf("Linked List is empty.\n");
        return;
    }

    temp = head;
    head = head->next;

    printf("Deleted node = %d\n", temp->data);

    free(temp);
}


void deleteLast()
{
    struct Node *temp;
    struct Node *prev;

    if (head == NULL)
    {
        printf("Linked List is empty.\n");
        return;
    }

    if (head->next == NULL)
    {
        printf("Deleted node = %d\n", head->data);

        free(head);
        head = NULL;

        return;
    }

    temp = head;

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    printf("Deleted node = %d\n", temp->data);

    prev->next = NULL;

    free(temp);
}


void deletePosition()
{
    struct Node *temp;
    struct Node *prev;
    int position;
    int i;

    if (head == NULL)
    {
        printf("Linked List is empty.\n");
        return;
    }

    printf("Enter position: ");
    scanf("%d", &position);

    if (position <= 0)
    {
        printf("Invalid position.\n");
        return;
    }

    if (position == 1)
    {
        temp = head;
        head = head->next;

        printf("Deleted node = %d\n", temp->data);

        free(temp);
        return;
    }

    temp = head;

    for (i = 1; i < position && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Position does not exist.\n");
        return;
    }

    prev->next = temp->next;

    printf("Deleted node = %d\n", temp->data);

    free(temp);
}


void countNodes()
{
    struct Node *temp;
    int count = 0;

    temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    printf("Total number of nodes = %d\n", count);
}


void main()
{
    int choice;

    do
    {
        printf("\n\n--- SINGLY LINKED LIST ---\n");

        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Ordered Insertion\n");
        printf("4. Display\n");
        printf("5. Delete First Node\n");
        printf("6. Delete Last Node\n");
        printf("7. Delete from Specified Position\n");
        printf("8. Count Nodes\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                insertFront();
                break;

            case 2:
                insertEnd();
                break;

            case 3:
                orderedInsertion();
                break;

            case 4:
                display();
                break;

            case 5:
                deleteFirst();
                break;

            case 6:
                deleteLast();
                break;

            case 7:
                deletePosition();
                break;

            case 8:
                countNodes();
                break;

            case 9:
                printf("Program Ended.\n");
                break;

            default:
                printf("Invalid Choice.\n");
        }

    } while (choice != 9);

    return 0;
}
