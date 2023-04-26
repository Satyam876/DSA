#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int size[100];
    int top[100];
    int total_size;
    int *A;
};

void create(struct Stack *st,int k)
{
    st->total_size = 0;

    for(int i=0; i<k; i++)
    {
        printf("\nEnter the Size of #%d Stack : ",i+1);
        scanf("%d",&st->size[i]);
    }
    st->top[0] = -1;
    st->top[1] = st->size[0]-1;

    for(int i=2; i<k; i++)
    {
        st->top[i] = st->size[i-1] + st->size[i] - 1;
    }

    for(int i=0; i<k; i++)
    {
        st->total_size += st->size[i];
    }
    st->A = (int *)malloc((st->total_size)*sizeof(int));
}

void push(struct Stack *st,int value,int stk)
{
    for(int i=0; i<st->total_size; i++)
    {
        if(stk == i)
        {
            st->top[i]++;
            st->A[st->top[i]] = value;
        }
    }
}

int pop(struct Stack *st,int stk)
{
    int value = -1;
    
    for(int i=0; i<st->total_size; i++)
    {
        if(stk == i)
        {
            value = st->A[st->top[i]];
            st->top[i]--;
        }
    }
    return value;
}

void display(struct Stack *st)
{
    printf("\nArray Elements : ");
    for(int i=0; i<st->total_size; i++)
    {
        printf("%d ",st->A[i]);
    }
}

int main()
{
    struct Stack s;
    int k;

    printf("\nEnter the value of K : ");
    scanf("%d",&k);

    create(&s,k);

    push(&s,10,0);
    push(&s,20,0);
    push(&s,30,0);
    push(&s,1,1);
    push(&s,2,1);
    push(&s,99,2);
    push(&s,98,2);
    push(&s,97,2);

    display(&s);

    printf("\nPopped Element from Stack 1 : ",pop(&s,0));
    printf("\nPopped Element from Stack 2 : ",pop(&s,1));
    printf("\nPopped Element from Stack 3 : ",pop(&s,2));


    return 0;
}