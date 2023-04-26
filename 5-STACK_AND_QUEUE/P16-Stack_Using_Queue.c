#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int size;
    int rear;
    int front;
    int *A;
};

void create(struct Queue *q,int n)
{
    q->size = n;
    q->rear = q->front = -1;
    q->A = (int *)malloc(n*sizeof(int));
}

void enqueue(struct Queue *q,int value)
{
    if(q->rear == q->size-1)
        printf("\nQueue is Full\n");
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
    else
    {
        q->front++;
        value = q->A[q->front];
    }
    return value;
}

int isEmpty(struct Queue *q)
{
    if(q->front == q->rear)
        return 1;
    else
        return 0;
}

void push(struct Queue *q1,struct Queue *q2,int value)
{
    if(isEmpty(q1))
    {
        enqueue(q1,value);
    }
    else
    {
        while(!isEmpty(q1))
        {
            enqueue(q2,dequeue(q1));
        }
        q1->rear = q1->front = -1;
        enqueue(q1,value);

        while(!isEmpty(q2))
        {
            enqueue(q1,dequeue(q2));
        }
        q2->rear = q2->front = -1;
    }
}

int pop(struct Queue *q1,struct Queue *q2)
{
    int value = -1;
    if(isEmpty(q1))
        return -1;
    else
    {
        value = dequeue(q1);
    }
    return value;
}

void display(struct Queue *q)
{
    printf("\nQueue : ");
    for(int i=q->front+1; i<=q->rear; i++)
    {
        printf("%d ",q->A[q->rear]);
    }
}

int main()
{
    int n;
    struct Queue q1,q2;

    printf("\nEnter the size of Queue : ");
    scanf("%d",&n);

    create(&q1,n);
    create(&q2,n);

    push(&q1,&q2,1);
    push(&q1,&q2,5);
    push(&q1,&q2,3);
    printf("\nElements : %d ",pop(&q1,&q2));
    push(&q1,&q2,2);
    printf("%d ", pop(&q1,&q2));

    return 0;
}