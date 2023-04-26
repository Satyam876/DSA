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


int getNthFromLast(struct Node *p, int n)
{
    struct Node *q=p;
       int count=0;
       
       while(p != NULL)
       {
           count++;
           p = p->next;
       }
       
       int i=0;
       while(i < count-n)
       {
           q = q->next;
           i++;
       }
       return q->data;
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

    int N;
    printf("\nEnter the Index from Last : ");
    scanf("%d",&N);

    printf("\n%dth Node From Last : %d\n",N,getNthFromLast(first,N));

    return 0;
}