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


bool detect_loop(struct Node *p,int n)
{
    int count = 0;

    while(p != NULL)
    {
        count++;
        if(count > n)
            return true;
        p = p->next;
    }
    if(count == n)
        return false;
}

int main()
{
    int n;

    printf("\nEnter the size of Linked-List : ");
    scanf("%d",&n);

    create(n);
    // display(first);

    bool detect = detect_loop(first,n);

    if(detect == true)
        printf("\nLoop is detected !\n");
    else
        printf("\nLoop Not detected !\n");

    return 0;
}