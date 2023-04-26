#include<stdio.h>
#include<stdlib.h>

struct Stack{
    int size;
    int top;
    char *A;
};

void create(struct Stack *st,int n)
{
    st->size = n;
    st->top = -1;
    st->A = (char *)malloc(n*sizeof(char));
}

void push(struct Stack *st,char ch)
{
    if(st->top == st->size-1)
        printf("\nStack OverFlow\n");
    else
    {
        st->top++;
        st->A[st->top] = ch;
    }
}

char pop(struct Stack *st)
{
    char ch;
    if(st->top == -1)
        printf("\nStack UnderFlow\n");
    else
    {
        ch = st->A[st->top];
        st->top--;
    }
    return ch;
}

int min_value_string(struct Stack *st,char *exp,int n,int k)
{
    int value = 0;

    for(int i=st->top; i>=n-k ; i--)
    {
        pop(st);
        // exp[i] = 0;
    }
    
    int i=0;
    char last_duplicate;

    while(i < n-k)
    {
        if(st->A[i] != '0')
        {
            int count = 1;

            for(int j=i+1; j < n-k; j++)
            {
                if(st->A[j] == st->A[i])
                {
                    count++;
                    st->A[j] = '0';
                }
            }
            value += (count*count);
        }
        i++;
    }
    return value;
}

void display(struct Stack st)
{
    printf("\nString : ");
    for(int i=0; i<=st.top; i++)
    {
        printf("%c ",st.A[i]);
    }
}

int main()
{
    int n;
    int k;
    struct Stack s;

    printf("\nEnter the size : ");
    scanf("%d",&n);

    char *exp = "aabcbcbcabcc";

    create(&s,n);

    printf("\nEnter the value of k : ");
    scanf("%d",&k);

    for(int i=0 ;exp[i] != '\0'; i++)
    {
        push(&s,exp[i]);
    }

    display(s);

    printf("\nMinimum Value of String : %d\n",min_value_string(&s,exp,n,k));

    return 0;
}