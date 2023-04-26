#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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
    printf("\nLinked-List Elements : ");
    while(p != NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
}


void delete_duplicate(struct Node *p)
{
    struct Node *q = p->next;

    while(q != NULL)
    {
        if(q->data == p->data)
        {
            p->next = q->next;
            q->next = NULL;
            free(q);
            q = p->next;
        }
        else{
            p = q;
            q = q->next;
        }     
    }
}

int main()
{
    int n;

    printf("\nEnter the size of Linked-List : ");
    scanf("%d",&n);

    create(n);
    display(first);

    delete_duplicate(first);
    display(first);

    return 0;
}