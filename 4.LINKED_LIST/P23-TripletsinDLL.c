#include<stdio.h>
#include<stdlib.h>

struct Node{
    struct Node *prev;
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
    first->prev = NULL;
    last = first;

    for(int i=1; i<n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter #%d Element : ",i+1);
        scanf("%d",&t->data);
        t->next = NULL;
        t->prev = last;
        last->next = t;
        last = t;
    }
}


void find_triplet_sum(struct Node *p,int x)
{
    struct Node *q=p;

    while(q->next != NULL)
    {
        q = q->next;
    }

    while(q != p && q->next != p)
    {
        if((p->data + q->data + q->prev->data) == x)
        {
            printf("(%d, %d, %d) ",p->data,q->prev->data,q->data);
            p = p->next;
            q = q->prev;
        }
        else{
            if((p->data +q->prev->data + q->data) > x)
            {
                q = q->prev;
            }
            else if((p->data+q->data+q->prev->data) < x)
            {
                p = p->next;
            }
        }
    }
}

void display(struct Node *p)
{
    printf("\nLinked - List Element : ");
    while( p != NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
}

int main()
{
    int n;
    int sum;

    printf("\nEnter the length of Linked-List : ");
    scanf("%d",&n);

    create(n);
    display(first);

    printf("\nEnter the Sum value : ");
    scanf("%d",&sum);

    find_triplet_sum(first,sum);

    return 0;
}