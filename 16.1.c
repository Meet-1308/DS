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
        printf("%d ", temp->data); 
        temp = temp->next; 
    } 
 
    printf("\n"); 
} 
 
void swapKth(struct Node **head, int k) 
{ 
    struct Node *temp; 
    struct Node *first; 
    struct Node *second; 
    struct Node *prevFirst; 
    struct Node *prevSecond; 
 
    int n = 0; 
    int i; 
 
    temp = *head; 
 
    /* Count total nodes */ 
    while (temp != NULL) 
    { 
        n++; 
        temp = temp->next; 
    } 
 
    /* Invalid K */ 
    if (k <= 0 || k > n) 
    { 
        printf("Invalid K\n"); 
        return; 
    } 
 
    /* Kth node from beginning and end are same */ 
    if (2 * k - 1 == n) 
    { 
        printf("Both nodes are same. No swap needed.\n"); 
        return; 
    } 
 
    first = *head; 
    prevFirst = NULL; 
 
    /* Find Kth node from beginning */ 
    for (i = 1; i < k; i++) 
    { 
        prevFirst = first; 
        first = first->next; 
    } 
 
    second = *head; 
    prevSecond = NULL; 
 
    /* Find Kth node from end */ 
    for (i = 1; i <= n - k; i++) 
    { 
        prevSecond = second; 
        second = second->next; 
    } 
 
    /* If first node is head */ 
    if (prevFirst == NULL) 
        *head = second; 
    else 
        prevFirst->next = second; 
 
    /* If second node is head */ 
    if (prevSecond == NULL) 
        *head = first; 
    else 
        prevSecond->next = first; 
 
    /* Swap next pointers */ 
    temp = first->next; 
    first->next = second->next; 
    second->next = temp; 
} 
 
void main() 
{ 
    struct Node *head = NULL; 
    struct Node *temp; 
    int n, data, k, i; 
 
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
 
    printf("\nOriginal Linked List: "); 
    display(head); 
 
    printf("Enter K: "); 
    scanf("%d", &k); 
 
    swapKth(&head, k); 
 
    printf("After Swapping: "); 
    display(head); 
 
    return 0; 
} 
