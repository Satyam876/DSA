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

void create_stack(struct Stack *st,int n1)
{
    st->stack_size = n1;
    st->top = -1;
    st->arr = (int *)malloc(n1*sizeof(int));
}

void create_queue(struct Queue *q,int n2)
{
    q->queue_size = n2;
    q->rear = q->front = -1;
    q->A = (int *)malloc(n2*sizeof(int));
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

int isEmptyQueue(struct Queue *q)
{
    if(q->front == q->rear)
        return 1;
    else
        return 0;
}

int stack_permutation(struct Stack *st,struct Queue *q1,struct Queue *q2,int n2)
{
    int B[100],k=0;
    int i = q1->front+1, j=q2->front+1;

    while(!isEmptyQueue(q1) && (i<n2 && j<n2))
    {
        if(q1->A[i] != q2->A[j])
        {
            push(st,dequeue(q1));
            i++;
        }
        else
        {
            B[k++] = dequeue(q1);
            i++;
            j++;
            while( !isEmptyStack(st) )
            {
                if(st->arr[st->top] == q2->A[j])
                {
                    B[k++] = pop(st);
                    j++;
                }
                else{
                    j++;
                    break;
                }
            }
        }
    }

    if(!isEmptyStack(st))
    {
        while( !isEmptyStack(st))
        {
            B[k++] = pop(st);
        }
    }

    int count=0;
    for(int x=0; x<n2; x++)
    {
        if(B[x] != q2->A[x])
            count++;
    }

    if(count == 0)
        return 1;
    else
        return 0;
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
    struct Stack st;
    struct Queue q1,q2;

    int n1,n2;

    printf("\nEnter the size of Stack : ");
    scanf("%d",&n1);

    create_stack(&st,n1);

    printf("\nEnter the size of Queue : ");
    scanf("%d",&n2);

    create_queue(&q1,n2);
    create_queue(&q2,n2);

    enqueue(&q1,1);
    enqueue(&q1,2);
    enqueue(&q1,3);

    enqueue(&q2,3);
    enqueue(&q2,1);
    enqueue(&q2,2);

    int result = stack_permutation(&st,&q1,&q2,n2);

    if(result == 1)
        printf("\nStack is Permutable\n");
    else
        printf("\nStack is Non-Permutable\n");

    return 0;
}