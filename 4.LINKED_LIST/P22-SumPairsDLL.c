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
    first->prev = NULL;
    first->next = NULL;
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

void display(struct Node *p)
{
    printf("\nLinked-List Elements : ");
    while(p != NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
}


void find_sum_pairs(struct Node *p,int sum)
{
    struct Node *q=p;
    while(q->next != NULL)
    {
        q = q->next;
    }

    while(q->next != p && q != p)
    {
        if((p->data+q->data) == sum)
        {
            printf("(%d ,%d) ",p->data,q->data);
            p = p->next;
            q = q->prev;
        }
        else 
        {
            if((p->data + q->data) > sum)
            {
                q = q->prev;
            }
            else if((p->data + q->data) < sum)
            {
                p = p->next;
            }
        }
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

    find_sum_pairs(first,sum);

    return 0;
}