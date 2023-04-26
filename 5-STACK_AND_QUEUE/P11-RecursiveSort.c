#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int size;
    int top;
    int *A;
};

void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

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
        printf("\nStack UnderFlow\n");
    else
    {
        value = st->A[st->top];
        st->top--;
    }
    return value;
}


void recursive_sort(struct Stack *st,int i,int j)
{
    if(i >= j)
        return;
    else
    {
        swap(&st->A[i],&st->A[j]);

        if(st->A[i] > st->A[j])
        {
            recursive_sort(st,i+1,j);
        }
        else if(st->A[i] < st->A[j])
            recursive_sort(st,i,j+1);
        else
            recursive_sort(st,i+1,j+1);
    }
}


void display(struct Stack st)
{
    printf("\nStack Elements : ");
    for(int i=st.top; i>=0; i--)
    {
        printf("%d ",st.A[i]);
    }
}

int main()
{
    struct Stack s;
    int n;

    printf("\nEnter the size of Stack : ");
    scanf("%d",&n);

    create(&s,n);
    push(&s,3);
    push(&s,2);
    push(&s,1);
    push(&s,4);

    display(s);

    recursive_sort(&s,0,s.top);

    display(s);
    return 0;
}