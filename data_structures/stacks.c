#include<stdio.h>
#include<stdlib.h>

#define MAX 5

typedef struct
{
    int data[MAX];
    int top;

}Stack;

void init(Stack *s){
    s->top = -1;
}

int isEmpty(Stack *s){
    return s->top == -1;
}
int isFull(Stack *s){
    return s->top == MAX-1;
}

void push(Stack *s, int value){
    if(isFull(s)){
        printf("OVERFLOW! Stack is Full.");
        return;
    }
    s->data[++(s->top)] = value;
    printf("%d pushed to stack\n", value);
}

int pop(Stack *s){
    if(isEmpty(s)){
        printf("UNDERFLOW! Stack is Empty.");
        return -1;
    }
    return s->data[(s->top)--];
}

int peek(Stack *s){
    if(isEmpty(s)){
        printf("Stack is Empty!");
        return -1;
    }
    return s->data[s->top];
}


int main(){
    Stack s;
    init(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);
    push(&s, 50);
    push(&s, 60);

    printf("Top element: %d\n", peek(&s));

    printf("Popped: %d\n", pop(&s));
    printf("Popped: %d\n", pop(&s));

    printf("Top element: %d\n", peek(&s));

    printf("Size of stack: %ld\n", sizeof(s)/sizeof(&s+1));

    return 0;
}
