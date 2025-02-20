#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct
{
    int data[MAX_SIZE];
    int front;
    int rear;
    int size;
}Queue;

void init(Queue *q){
    q->front = 0;
    q->rear = -1;
    q->size = 0;
}

int isFull(Queue *q){
    return q->size == MAX_SIZE;
}
int isEmpty(Queue *q){
    return q->size == 0;
}

void enqueue(Queue *q, int val){
    if(isFull(q)){
        printf("Queue is full!");
        return;
    }
    q->rear = (q->rear +1) % MAX_SIZE;
    q->data[q->rear] = val;
    q->size++;
    printf("%d enqueued\n",val);
}

int dequeue(Queue *q){
    if(isEmpty(q)){
        printf("Queue is empty!");
        return -1;
    }
    int dequeuedValue = q->data[q->front];
    q->front = (q->front + 1) % MAX_SIZE;
    q->size--;
    return dequeuedValue;
}

int peek(Queue *q){
    if (isEmpty(q)){
        printf("Queue is empty!");
        return -1;
    }
    return q->data[q->front];
}

void display(Queue *q){
    if (isEmpty(q)){
        printf("Queue is empty!");
        return;
    }
    for (int i = 0 ; i < q->size ; i++){
        int index = (q->front+i)%MAX_SIZE;
        printf("%d|",q->data[index]);
    }
    printf("\n");

}


int main(){
    Queue q;
    init(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    display(&q);

    printf("Dequeued element: %d\n", dequeue(&q));
    display(&q);

    printf("Front element: %d\n", peek(&q));

    enqueue(&q, 40);
    enqueue(&q, 50);
    enqueue(&q, 60);
    display(&q);

    return 0;
}