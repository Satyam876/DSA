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


void delete_greater_node_right(struct Node *p)
{
    struct Node *q = p->next;
    struct Node *r = NULL;

    while(q != NULL)
    {
        if(q->data > p->data)
        {
            if(p == first)
            {
               first =first->next;
               p->next = NULL;
               r = p;
               p = q;
               q = q->next;
            }
            else
            {
                r->next = p->next;
                p->next = NULL;
                p = q;
                q = q->next;
            }
        }
        else{
            r = p;
            p = q;
            q = q->next;
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
    struct Node *result;
    int n;
    printf("\nEnter the length of lInked-lIST : ");
    scanf("%d",&n);

    create(n);
    display(first);

    delete_greater_node_right(first);

    display(first);

    return 0;
}