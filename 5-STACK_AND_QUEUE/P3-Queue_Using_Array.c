#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int size;
    int front;
    int rear;
    int *A;
};

void create(struct Queue *q,int n)
{
    q->size = n;
    q->front = -1;
    q->rear = -1;
    q->A = (int *)malloc(n*sizeof(int));
}

void enqueue(struct Queue *q,int value)
{
    if(q->rear == q->size-1)
    {
        printf("\nQueue is Full\n");
    }
    else
    {
        q->rear++;
        q->A[q->rear] = value;
    }
}

int dequeue(struct Queue *q)
{
    int value = -1;

    if(q->front == q->rear)
        printf("\nQueue is Empty\n");
    else{
        q->front++;
        value = q->A[q->front];
    }
    return value;
}

void display(struct Queue q)
{
    printf("\nQueue Elements : ");
    for(int i=q.front+1; i<= q.rear; i++)
    {
        printf("%d ",q.A[i]);
    }
}

int main()
{
    struct Queue q;
    int n;
    printf("\nEnter the size of Queue : ");
    scanf("%d",&n);

    create(&q,n);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    enqueue(&q,50);

    display(q);

    printf("\nDequeued Element : %d",dequeue(&q));

    display(q);

    return 0;
}