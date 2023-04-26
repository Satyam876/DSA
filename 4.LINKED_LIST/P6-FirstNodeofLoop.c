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
    last->next = first->next;
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


void first_node_of_loop(struct Node *p,int n)
{
    int count = 1;
    
    while(count < n)
    {
        count++;
        p = p->next;
    }
    printf("\nFirst Node of Loop is at Element : %d\n",p->next->data);
}

int main()
{
    int n;

    printf("\nEnter the size of Linked-List : ");
    scanf("%d",&n);

    create(n);
    // display(first);

    first_node_of_loop(first,n);

    return 0;
}