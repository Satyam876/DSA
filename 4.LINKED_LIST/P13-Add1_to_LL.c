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


int add_1_to_LL(struct Node *p)
{
    int sum=0;
    int rem=0;

    while(p != NULL)
    {
        rem = p->data;
        sum = sum*10 + p->data;
        p = p->next;  
    }
    return sum+1;
}


int main()
{
    int n;
    printf("\nEnter the size of Linked-List : ");
    scanf("%d",&n);

    create(n);
    display(first);

    printf("\nResult of 1 addition to Linked-List Number : %d\n",add_1_to_LL(first));

    return 0;
}