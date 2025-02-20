#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node *insertAtBeginning(Node *head, int data)
{
    Node *newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

Node *insertAtEnd(Node *head, int data)
{
    Node *newNode = createNode(data);
    if (head == NULL)
    {
        return newNode;
    }
    Node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
    return head;
}

int insertAfter(Node *prevNode, int data)
{
    if (prevNode == NULL)
    {
        return 0;
    }
    Node *newNode = createNode(data);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    return 1;
}

Node *deleteNode(Node *head, int key)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->data == key)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    Node *current = head;
    while (current->next != NULL && current->next->data != key)
    {
        current = current->next;
    }
    if (current->next == NULL)
    {
        return head;
    }
    Node *temp = current->next;
    current->next = current->next->next;
    free(temp);
    return head;
}

Node *search(Node *head, int key)
{
    Node *current = head;
    while (current != NULL)
    {
        if (current->data == key)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void printList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void freeList(Node *head)
{
    Node *current = head;
    while (current != NULL)
    {
        Node *next = current->next;
        free(current);
        current = next;
    }
}

int main()
{
    Node *head = NULL;

    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 20);
    head = insertAtEnd(head, 30);
    insertAfter(head->next, 40);

    printf("Linked list: ");
    printList(head);

    Node *foundNode = search(head, 30);
    if (foundNode != NULL)
    {
        printf("Found node with data: %d\n", foundNode->data);
    }

    head = deleteNode(head, 20);
    printf("Linked list after deletion: ");
    printList(head);

    freeList(head);
    head = NULL;
    return 0;
}