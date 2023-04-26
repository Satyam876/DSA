#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first = NULL;

void create(int n)
{
    struct Node *t,*last;
    first = (struct Node *)malloc(sizeof(struct Node));

    printf("\nEnter #1 Element : ");
    scanf("%d",&first->data);

    first->next = NULL;
    last = first;

    for(int i=1; i<n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter #%d Element : ",i+1);
        scanf("%d",&t->data);

        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void reverse(struct Node *p)
{
    struct Node *q = p->next;
    struct Node *r = NULL;

    while(q != NULL)
    {
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    first->next = NULL;
    first = p;
}

void recursive_reverse(struct Node *q,struct Node *p)
{
    if(p != NULL)
    {
        recursive_reverse(p,p->next);
        p->next = q;
    }
    else{
        first = q;
    }
}

void display(struct Node *p)
{
    printf("\nLinked-List Element : ");
    while(p != NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
}

int main()
{
    int n;
    printf("\nEnter the Number of Elements : ");
    scanf("%d",&n);

    create(n);
    display(first);

    //printf("\nITERATIVE REVERSE\n");
    // reverse(first);
    // display(first);

    printf("\n\nRECURSIVE REVERSE");
    recursive_reverse(NULL,first);
    display(first);

    return 0;
}