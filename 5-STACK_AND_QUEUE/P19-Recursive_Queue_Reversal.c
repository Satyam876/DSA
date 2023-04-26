#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int size;
    int rear;
    int front;
    int *A;
};

void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void create(struct Queue *q,int n)
{
    q->size = n;
    q->rear = q->front = -1;
    q->A = (int *)malloc(n*sizeof(int));
}

void enqueue(struct Queue *q,int value)
{
    if(q->rear == q->size-1)
        printf("\nQueue is Full");
    else
    {
        q->rear++;
        q->A[q->rear] = value;
    }
}

int dequeue(struct Queue *q)
{
    int value=-1;

    if(q->front == q->rear)
        printf("\nQueue is Empty\n");
    else
    {
        q->front++;
        value = q->A[q->front];
    }
}

void recursive_queue_reversal(struct Queue *q,int i,int j)
{
    if(j < i)
        return;
    else
    {
        swap(&q->A[i],&q->A[j]);
        recursive_queue_reversal(q,i+1,j-1);
    }   
}

void reverse_first_k_elements(struct Queue *q,int k)
{
    int i=q->front+1,j=k-1;

    while(i <= j)
    {
        swap(&q->A[i],&q->A[j]);
        i++;
        j--;
    }
}

void display(struct Queue q)
{
    printf("\nQueue Elements : ");
    for(int i=q.front+1; i <= q.rear; i++)
    {
        printf("%d ",q.A[i]);
    }
}

int main()
{
    int n;
    int k;
    struct Queue q;

    printf("\nEnter the size of Queue : ");
    scanf("%d",&n);

    create(&q,n);

    enqueue(&q,4);
    enqueue(&q,3);
    enqueue(&q,1);
    enqueue(&q,10);
    enqueue(&q,2);
    enqueue(&q,6);

    display(q);

    printf("\nEnter the Value of K : ");
    scanf("%d",&k);

    // recursive_queue_reversal(&q,q.front+1,q.rear);
    reverse_first_k_elements(&q,k);
    display(q);

    return 0;
}