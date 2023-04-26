#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int size;
    int top;
    int count;
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
    st->count = 0;
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
        st->count++;
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


int find_middle(struct Stack *st)
{
    int mid;
    mid = st->count/2;
    
    return st->A[mid];
}

void delete_middle_element(struct Stack *st)
{
    int mid = st->count/2;
    int result;
    if(st->top != -1)
    {
        swap(&st->A[mid],&st->A[st->top]);
    }
     pop(st);
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
    push(&s,10);
    push(&s,20);
    push(&s,30);
    push(&s,40);
    push(&s,50);

    display(s);

    printf("\nMiddle Element : %d\n",find_middle(&s));

    delete_middle_element(&s);

    display(s);

    return 0;
}