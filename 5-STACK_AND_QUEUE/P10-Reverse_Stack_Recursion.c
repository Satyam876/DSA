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

void recursive_reverse(struct Stack *st,int i,int j)
{
    if(i > j)
        return;
    else
    {
        swap(&st->A[i],&st->A[j]);
        recursive_reverse(st,i+1,j-1);
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
    int n;
    struct Stack s;

    printf("\nEnter the Size of Stack : ");
    scanf("%d",&n);

    create(&s,n);

    push(&s,10);
    push(&s,20);
    push(&s,30);
    push(&s,40);
    push(&s,50);
    push(&s,60);

    display(s);

    recursive_reverse(&s,0,s.top);
    printf("\nRECURSIVE DISPLAY\n");
    display(s);

    return 0;
}