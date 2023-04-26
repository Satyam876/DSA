#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*front=NULL,*rear=NULL;

void enqueue(int value)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));

    if(t == NULL)
        printf("\nQueue is Full\n");
    else
    {
        t->data = value;
        t->next = NULL;

        if(front == NULL)
        {
            front = rear = t;
        }
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue()
{
    struct Node *t;
    int value = -1;

    if(front == NULL)
        printf("\nQueue is Empty\n");
    else
    {
        t = front;
        value = front->data;
        front = front->next;
        free(t);
    }
    return value;
}

void display()
{
    struct Node *t=front;
    printf("\nQueue Elements : ");
    while(t != rear)
    {
        printf("%d ",t->data);
        t = t->next;
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);
    enqueue(70);

    display();

    printf("\nDequeued Element : %d\n",dequeue());

    display();

    return 0;
}