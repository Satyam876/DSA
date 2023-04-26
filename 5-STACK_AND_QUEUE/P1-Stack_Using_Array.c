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
        printf("\nStack Overflow\n");
    else
    {
        st->top++;
        st->A[st->top] = value;
    }
}

int get_min(struct Stack *st)
{
        int min = st->size-1;
        for(int i=st->top; i>=0; i--)
        {
            if(st->A[i] < st->A[min])
                min=i;
        }
    return st->A[min];
}

void next_greater(struct Stack *st)
{
    int i=0;
    while(i < st->size)
    {
        if(i == st->size-1)
                printf("\nNext Greater Element of %d is -1",st->A[i]);
        
        else
        {
            int j=i+1;
            while(j < st->size)
            {
                int great=i;
                if(st->A[j] > st->A[i])
                {
                    great = j;
                    printf("\nNext Greater Element of %d is %d",st->A[i],st->A[great]);
                    break;
                }
                j++;
            }
        }
        i++;
    }
}

int pop(struct Stack *st)
{
    int value;

    if(st->top == -1)
        printf("\nStack Underflow\n");
    else
    {
        value = st->A[st->top];
        st->top--;
    }
    return value;
}

int peek(struct Stack *st,int pos)
{
    if(pos <= 0 || pos >= st->size)
        return 0;
    else
        return st->A[pos];
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
    struct Stack *s;
    int n;
    int pos;

    printf("\nEnter the Size of Stack : ");
    scanf("%d",&n);

    create(s,n);
    push(s,1);
    // push(s,20);
    push(s,3);
    push(s,2);
    push(s,4);
    // push(s,60);

    display(*s);

    // printf("\nEnter the Position to Peek : ");
    // scanf("%d",&pos);
    // printf("\nElement at Position %d is : %d\n",pos,peek(s,pos));

    // printf("\nPopped Element : %d\n",pop(s));
    printf("\nMinimum Element is : %d\n",get_min(s));
    next_greater(s);

    return 0;
}