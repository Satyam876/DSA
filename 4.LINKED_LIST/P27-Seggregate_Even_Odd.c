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


void seggregate_even_odd(struct Node *p,int N)
{
    struct Node *q=p,*r=NULL;

    while(q->next != NULL)
    {
        q = q->next;
    }
    int i=0;

    while(i < N)
    {
        if(p->data%2 != 0)
        {
            if(p == first)
            {
                q->next = p;
                q = q->next;
                first = first->next;
                p = p->next;
                q->next = NULL;
            }
            else{
                q->next = p;
                q = q->next;
                r->next = p->next;
                p = p->next;
                q->next = NULL;
            }
        }
        else{
            r = p;
            p = p->next;
        }
        i++;
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

    seggregate_even_odd(first,n);

    display(first);

    return 0;
}