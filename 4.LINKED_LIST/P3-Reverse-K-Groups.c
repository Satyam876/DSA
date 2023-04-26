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

void display(struct Node *p)
{
    while(p != NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
}


void reverse_k_groups(struct Node *p,int K)
{
    struct Node *q = p;
    int count = 1;

    struct Node *r = q->next;
    struct Node *s = NULL;

    while(count < K && p->next != NULL)
    {
        count++;
        p = p->next;
    }

    while(q->data != p->data)
    {
        s = r->next;
        r->next = q;
        q = r;
        r = s;
    }

    first->next = NULL;
    first = q;

    display(first);

    first = r;

    if(r != NULL)
        reverse_k_groups(first,K);

}

int main()
{
    int n,k;
    printf("\nEnter the size of Linked-List : ");
    scanf("%d",&n);

    create(n);
    display(first);

    printf("\nEnter the Value of K : ");
    scanf("%d",&k);

    reverse_k_groups(first,k);

    return 0;
}