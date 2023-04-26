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

int isEmpty(struct Stack st)
{
    if(st.top == -1)
        return 1;
    else
        return 0;
}

int paranthesis_matching(struct Stack *st,char *exp)
{
    for(int i=0; exp[i] != '\0'; i++)
    {
        if(exp[i] == '(')
        {
            push(st,exp[i]);
        }

        if(exp[i] == ')')
        {
            if(isEmpty(*st))
                return 0;
            else
                pop(st);
        }
    }
    if(isEmpty(*st))
        return 1;
    else
        return 0;
}



int main()
{
    int n;
    struct Stack s;

    printf("\nEnter the Length of String : ");
    scanf("%d",&n);

    create(&s,n);

    char *exp = "((a+b)*(c-d))";

    int result = paranthesis_matching(&s,exp);

    if(result == 1)
        printf("\nParanthseis are Matched\n");
    else
        printf("\nParanthseis are Not Matched\n");
    
    return 0;
}