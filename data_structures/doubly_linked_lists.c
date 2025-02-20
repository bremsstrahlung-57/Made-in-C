#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        perror("Memory allocation failed!");
        return NULL;
    }
    newNode->next = NULL;
    newNode->data = data;
    newNode->prev = NULL;
    return newNode;
}

Node *insertAtBeginning(Node *head, int data)
{
    Node *newNode = createNode(data);
    if (newNode == NULL)
    {
        return head;
    }
    newNode->next = head;
    if (head != NULL)
    {
        head->prev = newNode;
    }
    return newNode;
}

Node *insertAtEnd(Node *head, int data)
{
    Node *newNode = createNode(data);
    if (newNode == NULL)
    {
        return head;
    }
    if (head == NULL)
    {
        return newNode;
    }
    Node *currentNode = head;
    while (currentNode->next != NULL)
    {
        currentNode = currentNode->next;
    }
    currentNode->next = newNode;
    newNode->prev = currentNode;
    return head;
}

int insertAfter(Node *prevNode, int data)
{
    if (prevNode == NULL)
    {
        return 0;
    }
    Node *newNode = createNode(data);
    if (newNode == NULL)
    {
        return 0;
    }
    newNode->next = prevNode->next;
    newNode->prev = prevNode;
    if (prevNode->next != NULL)
    {
        prevNode->next->prev = newNode;
    }
    prevNode->next = newNode;
    return 1;
}

void printListForward(Node *head)
{
    Node *currentNode = head;
    while (currentNode != NULL)
    {
        printf("%d -> ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("NULL\n");
}

void printListBackward(Node *tail)
{
    Node *currentNode = tail;
    while (currentNode != NULL)
    {
        printf("%d -> ", currentNode->data);
        currentNode = currentNode->prev;
    }
    printf("NULL\n");
}

Node *findTail(Node *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *currentNode = head;
    while (currentNode->next != NULL)
    {
        currentNode = currentNode->next;
    }
    return currentNode;
}

void freeList(Node *head)
{
    Node *currentNode = head;
    while (currentNode != NULL)
    {
        Node *next = currentNode->next;
        free(currentNode);
        currentNode = next;
    }
}

Node *deleteNode(Node *head, int key)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *current = head;
    while (current != NULL && current->data != key)
    {
        current = current->next;
    }
    if (current == NULL)
    {
        return head;
    }
    if (current->prev != NULL)
    {
        current->prev->next = current->next;
    }
    else
    {
        head = current->next;
    }
    if (current->next != NULL)
    {
        current->next->prev = current->prev;
    }
    free(current);
    return head;
}

int main()
{
    Node *head = NULL;

    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 20);
    head = insertAtEnd(head, 30);
    insertAfter(head->next, 40);

    printf("Doubly Linked List Forward: ");
    printListForward(head);

    Node *tail = findTail(head);
    if (tail)
        printf("Tail -> %d\n", tail->data);
    else
        printf("List is empty.\n");

    printf("Doubly Linked List Backward: ");
    printListBackward(tail);

    head = deleteNode(head, 40);
    printf("After Deleting 40: ");
    printListForward(head);

    freeList(head);
    return 0;
}
