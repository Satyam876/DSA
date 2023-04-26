#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int size;
    int top;
    int *A;
};

void create(struct Stack *st,int n)
{
    st->size = n;
    st->top = -1;
    st->A = (int *)malloc(n*sizeof(int));
}

void push(struct Stack *st,int value)
{
    if(st->top == st->size-1)
        printf("\nStack OverFlow\n");
    else
    {
        st->top++;
        st->A[st->top] = value;
    }
}

int pop(struct Stack *st)
{
    int value = -1;

    if(st->top == -1)
        printf("\nStack UnderFlow");
    else
    {
        value = st->A[st->top];
        st->top--;
    }
    return value;
}

int isEmpty(struct Stack *st)
{
    if(st->top == -1)
        return 1;
    else
        return 0;
}

void enqueue(struct Stack *s1,struct Stack *s2,int value)
{
    if(s1->top == s1->size-1)
        printf("\nStack 1 OverFlow\n");
    else
    {
        push(s1,value);

        while(!isEmpty(s1))
        {
            push(s2,pop(s1));
        }
    }
}

int dequeue(struct Stack *s1,struct Stack *s2)
{
    int value = -1;

    if(s2->top == -1)
        printf("\nStack 2 UnderFlow\n");
    else
    {
        while(!isEmpty(s2))
        {
            push(s1,pop(s2));
        }
        value = pop(s1);

        while(!isEmpty(s1))
        {
            push(s2,pop(s1));
        }
    }
    return value;
}

int main()
{
    int n;
    struct Stack s1,s2;

    printf("\nEnter the size of Stack : ");
    scanf("%d",&n);

    create(&s1,n);
    create(&s2,n);

    enqueue(&s1,&s2,2);
    enqueue(&s1,&s2,3);
    printf("\nQueue Elements : %d ",dequeue(&s1,&s2));
    enqueue(&s1,&s2,4);
    printf("%d ",dequeue(&s1,&s2));

    return 0;
}