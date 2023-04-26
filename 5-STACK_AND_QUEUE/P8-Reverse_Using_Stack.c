#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int size;
    int top;
    char *str;
};

void create(struct Stack *st,int n)
{
    st->size = n;
    st->top = -1;
    st->str = (char *)malloc(n*sizeof(char));
}

void push(struct Stack *st,char ch)
{
    if(st->top == st->size-1)
        printf("\nStack OverFlow\n");
    else
    {
        st->top++;
        st->str[st->top] = ch;
    }
}

char pop(struct Stack *st)
{
    char ch;
    if(st->top == -1)
        printf("\nStack UnderFlow\n");
    else
    {
        ch = st->str[st->top];
        st->top--;
    }
    return ch;
}

char *reverse(struct Stack *st,char *arr,int len)
{
    char *reverse_array;

    reverse_array = (char *)malloc(len*sizeof(char));

    for(int i=0; i<len; i++)
    {
        push(st,arr[i]);
    }

    for(int i=0; i<len; i++)
    {
        arr[i] = pop(st);
    }
    return arr;
}

void display(struct Stack st)
{
    printf("\nStack Elements : ");
    for(int i=st.top; i>=0; i++)
    {
        printf("%c ",st.str[i]);
    }
}

int main()
{
    struct Stack st;
    char *S;
    char *reverse_str;
    int n;

    printf("\nEnter the size of String : ");
    scanf("%d",&n);

    S = (char *)malloc(n*sizeof(char));
    reverse_str = (char *)malloc(n*sizeof(char));

    printf("\nEnter the String : ");
    for(int i=0; i<n; i++)
    {
        scanf("%c",&S[i]);
    }

    create(&st,n);

    reverse_str = reverse(&st,S,n);

    printf("\nReversed String : ");
    for(int i=0; i<n; i++)
    {
        printf("%c",reverse_str[i]);
    }

    return 0;
}