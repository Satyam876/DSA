#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*top=NULL;

void push(int value)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));

    if(t == NULL)
        printf("\nStack OverFlow\n");
    else
    {
        t->data = value;
        t->next = top;
        top = t;
    }
}

int pop()
{
    int value;
    struct Node *t=top;

    if(top == NULL)
        printf("\nStack UnderFlow\n");
    else
    {
        value = top->data;
        top = top->next;
        t->next = NULL;
        free(t);
    }
    return value;
}

void display(struct Node *p)
{
    printf("\nStack Elements : ");
    while(p)
    {
        printf("%d ",p->data);
        p = p->next;
    }
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    push(50);
    push(60);

    display(top);

    printf("\nPopped Element : %d",pop());

    // display(top);

    return 0;
}