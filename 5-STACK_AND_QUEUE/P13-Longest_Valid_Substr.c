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
        printf("\nStack OverFlow");
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

int longest_valid_substr(struct Stack *st)
{
    int count=0;

    for(int i=0; i< st->size; i++)
    {
        if(st->str[i] == '(')
        {
            int j = i+1;
            while(j < st->size)
            {
                if(st->str[j] == ')' && st->str[j] != 'a')
                {
                    st->str[j] = 'a';
                    count++;
                    break;
                }
                j++;
            }
        }
    }
    return count*2;
}

void display(struct Stack st)
{
    printf("\nStack Elements : ");
    for(int i=st.top; i>=0; i--)
    {
        printf("%c ",st.str[i]);
    }
}

int main()
{
    int n;
    struct Stack s;

    printf("\nEnter the size of Stack : ");
    scanf("%d",&n);

    create(&s,n);

    push(&s,'(');
    push(&s,')');
    push(&s,'(');
    push(&s,'(');
    push(&s,')');
    push(&s,')');
    push(&s,'(');

    display(s);

    printf("\nLongest Valid Substring : %d\n",longest_valid_substr(&s));

    return 0;
}