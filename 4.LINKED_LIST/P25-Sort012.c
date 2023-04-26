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
    printf("\nEnter #1 Node Element : ");
    scanf("%d",&first->data);

    first->next = NULL;
    last = first;

    for(int i=1; i<n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter #%d Node Element : ",i+1);
        scanf("%d",&t->data);
        t->next = NULL;
        last->next = t;
        last = t;
    }
}


void sort012(struct Node *p)
{
    struct Node *q=p->next;
    struct Node *r=p;

    while(r->next != NULL)
    {
        r = r->next;
    }

    while(q != NULL)
    {
        if(p->data == 0)
        {
            p->next = q->next;
            q->next = first;
            first = q;
            q = p->next;
        }
        else if(q->data == 2)
        {
            p->next = q->next;
            r->next = q;
            r = q;
            q->next = NULL;
            q = p->next;
        }
        else{
            p = p->next;
            q = p->next;
        }
    }
}


void display(struct Node *p)
{
    printf("\nLinked-List Elements : ");
    
    while(p != NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
}


int main()
{
    int n;
    printf("\nEnter the length of lInked-lIST : ");
    scanf("%d",&n);

    create(n);
    display(first);

    sort012(first);
    display(first);

    return 0;
}