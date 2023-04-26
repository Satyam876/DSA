#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int stack_size;
    int top;
    int *arr;
};

struct Queue{
    int queue_size;
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

void create_stack(struct Stack *st,int n)
{
    st->stack_size = n;
    st->top = -1;
    st->arr = (int *)malloc(n*sizeof(int));
}

void create_queue(struct Queue *q,int n)
{
    q->queue_size = n;
    q->rear = q->front = -1;
    q->A = (int *)malloc(n*sizeof(int));
}

void push(struct Stack *st,int value)
{
    if(st->top == st->stack_size-1)
        printf("\nStack OverFlow\n");
    else
    {
        st->top++;
        st->arr[st->top] = value;
    }
}

int pop(struct Stack *st)
{
    int value = -1;
    if(st->top == -1)
        printf("\nStack UnderFlow\n");
    else
    {
        value = st->arr[st->top];
        st->top--;
    }
    return value;
}

int isEmptyStack(struct Stack *st)
{
    if(st->top == -1)
        return 1;
    else
        return 0;
}

void enqueue(struct Queue *q,int value)
{
    if(q->rear == q->queue_size-1)
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


void display_queue(struct Queue q)
{
    printf("\nQueue Elements : ");
    for(int i=q.front+1; i <= q.rear; i++)
    {
        printf("%d ",q.A[i]);
    }
}


void interleave_half(struct Stack *st,struct Queue *q,int n)
{
    int i = q->front+1;
    int j = n/2;

    while(i < j && j < n)
    {
            push(st,q->A[i]);
            push(st,q->A[j]);
            i++;
            j++;
    }
    q->rear = q->front = -1;
    for(int k=st->top; k>=0; k--)
    {
        enqueue(q,pop(st));
    }

    printf("\nElements After Interleaving : ");

    for(int k=q->rear; k>=0; k--)
    {
        printf("%d ",q->A[k]);
    }
}

int main()
{
    int n;
    struct Queue q;
    struct Stack st;

    printf("\nEnter the Size : ");
    scanf("%d",&n);

    create_queue(&q,n);
    create_stack(&st,n);

    enqueue(&q,11);
    enqueue(&q,12);
    enqueue(&q,13);
    enqueue(&q,14);
    enqueue(&q,15);
    enqueue(&q,16);
    enqueue(&q,17);
    enqueue(&q,18);
    enqueue(&q,19);
    enqueue(&q,20);

    display_queue(q);

    interleave_half(&st,&q,n);

    return 0;
}