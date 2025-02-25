#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
typedef struct Node Node;

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
    if (head == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }
    Node *current = head;
    while (current->next != head)
    {
        current = current->next;
    }

    newNode->next = head;
    current->next = newNode;

    return newNode;
}

Node *inserAtEnd(Node *head, int data)
{
    Node *newNode = createNode(data);
    if (newNode == NULL)
    {
        return head;
    }
    if (head == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }
    Node *current = head;
    while (current->next != head)
    {
        current = current->next;
    }
    current->next = newNode;
    newNode->next = head;
    return head;
}

int insertAfter(Node *head, int after, int data)
{
    if (head == NULL)
    {
        return 0;
    }
    Node *current = head;
    do
    {
        if (current->data == after)
        {
            Node *newNode = createNode(data);
            newNode->next = current->next;
            current->next = newNode;
            return 1;
        }
        current = current->next;
    } while (current != head);

    return 0;
}

Node *deleteHead(Node *head)
{
    if (head == NULL)
    {
        printf("Empty");
        return NULL;
    }
    if (head->next == head)
    {
        free(head);
        return NULL;
    }
    Node *current = head;
    while (current->next != head)
    {
        current = current->next;
    }
    Node *newHead = head->next;
    current->next = newHead;
    free(head);

    return newHead;
}

Node *deleteTail(Node *head)
{
    if (head == NULL)
    {
        printf("Empty list\n");
        return NULL;
    }
    if (head->next == head)
    {
        free(head);
        return NULL;
    }
    Node *current = head;
    while (current->next->next != head)
    {
        current = current->next;
    }
    free(current->next);
    current->next = head;
    return head;
}

Node *deleteNode(Node *head, int key)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->data == key)
    {
        return deleteHead(head);
    }
    Node *current = head;
    while (current->next->data != key && current->next != head)
    {
        current = current->next;
    }
    if (current->next == head)
    {
        printf("%d not in list", key);
        return head;
    }
    Node *temp = current->next;
    current->next = temp->next;
    free(temp);
    return head;
}

Node *search(Node *head, int key)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *current = head;
    do
    {
        if (current->data == key)
        {
            return current;
        }
        current = current->next;

    } while (current != head);

    return NULL;
}

void freeList(Node *head)
{
    if (head == NULL)
        return;

    Node *current = head->next;
    Node *temp;

    while (current != head)
    {
        temp = current;
        current = current->next;
        free(temp);
    }
}

void printList(Node *head)
{
    if (head == NULL)
    {
        printf("Empty list\n");
        return;
    }

    Node *current = head;
    do
    {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != head);
    printf("(back to start %d)\n", head->data);
}

int main()
{
    Node *head = NULL;

    printf("Adding 10 at beginning\n");
    head = insertAtBeginning(head, 10);
    printf("\nAdding 20 at beginning\n");
    head = insertAtBeginning(head, 20);
    printf("\nAdding 30 at end\n");
    head = inserAtEnd(head, 30);

    printf("Initial list: ");
    printList(head);

    insertAfter(head, 10, 40);
    printf("After inserting 40 after 10: ");
    printList(head);

    Node *found = search(head, 30);
    if (found != NULL)
    {
        printf("Found node with data: %d\n", found->data);
    }
    head = deleteNode(head, 20);
    printf("After deleting 20: ");
    printList(head);

    freeList(head);
    return 0;

    return 0;
}