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
    last->next = first;
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


void delete_loop(struct Node *p,int n)
{
    int count = 1;

    while(count < n)
    {
        count++;
        p = p->next;
    }
    if(p != NULL)
        p->next = NULL;
}

int main()
{
    int n;

    printf("\nEnter the size of Linked-List : ");
    scanf("%d",&n);

    create(n);
    // display(first);

    delete_loop(first,n);
    display(first);

    return 0;
}