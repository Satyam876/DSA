#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


struct Node{
    int data;
    struct Node *next;
}*first=NULL;

void create_circular_ll(int n)
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
        last->next = first;
    }
}

void display(struct Node *p)
{
    do
    {
        printf("%d ",p->data);
        p = p->next;
    }
    while(p != first);
}

void split_circular_in_half(struct Node *p,int n)
{
    int i = 0;
    struct Node *first2 = NULL;

    while(i < n/2)
    {
        p = p->next;
        i++;
    }

    if(p->next != first)
        first2 = p->next;
    p->next = first;

    struct Node *q = first2,*r = first2;

    while(q->next != first)
    {
        q = q->next;
    }
    q->next = first2;

    printf("\n1st Linked - List : ");
    display(first);
    printf("\n\n2nd Linked - List : ");
    do{
        printf("%d ",r->data);
        r = r->next;
    }
    while(r != first2);
}



int main()
{
    int n;

    printf("\nEnter the Number of Elements : ");
    scanf("%d",&n);

    create_circular_ll(n);
    printf("\nLinked-List Elements : ");
    display(first);

    split_circular_in_half(first,n);

    return 0;
}