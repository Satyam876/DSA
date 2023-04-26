#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *next;
}*first=NULL;

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


void display(struct Node *p)
{
    printf("\nLINKED LIST ELEMENTS : ");
    while(p != NULL)
    {
        printf("%d->",p->data);
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

    return 0;
}