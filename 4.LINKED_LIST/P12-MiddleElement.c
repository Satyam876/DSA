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

int middle_element(struct Node *p)
{
    int count=0;
    struct Node *q=p;

    while(p != NULL)
    {
        count++;
        p = p->next;
    }
    int i = 0;

    while(i < count/2)
    {
        i++;
        q = q->next;
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
    printf("\nEnter the size of Linked-List : ");
    scanf("%d",&n);

    create(n);
    display(first);

    printf("\nMiddle Element is : %d\n",middle_element(first));

    return 0;
}