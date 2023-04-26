#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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


int isEmpty(struct Stack st)
{
    if(st.top == -1)
        return 1;
    else
        return 0;
}

bool redundant_paranthesis_check(struct Stack *st,char *exp)
{

    for(int i=0; exp[i] != '\0'; i++)
    {
        if(exp[i] == '(' || exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/' )
        {
            push(st,exp[i]);
        }
        else if(exp[i] == ')')
        {
            bool flag = true;
            pop(st);
            while(isEmpty(*st) && st->str[st->top] != '(')
            {
                if(st->str[st->top] == '+' || st->str[st->top] == '-' || st->str[st->top] == '*' || st->str[st->top] == '/')
                    flag = false;
                
                pop(st);
            }
            if(flag == true)
                return true;
        }
    }
    return false;
}

int main()
{
    struct Stack *s;
    int n;

    printf("\nEnter the size of Stack : ");
    scanf("%d",&n);
    create(s,n);

    char *exp = "((a+b)/c)";
    

    bool result = redundant_paranthesis_check(s,exp);

    if(result == true)
        printf("\nParenthesis are Redundant\n");
    else
        printf("\nParenthesis are Not Redundant\n");
    return 0;
}