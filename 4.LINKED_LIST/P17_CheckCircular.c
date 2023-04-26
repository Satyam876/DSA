#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


struct Node{
    int data;
    struct Node *next;
}*first=NULL;

void create_circular_ll(int n)
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
        last->next = first;
    }
}


bool check_circular(struct Node *p)
{
   if(first == NULL)
        return true;
   if(first->next == first)
        return true;
   
   p = first->next;
   
   while(p != first)
   {
       if(p == NULL)
        return false;
    
    p = p->next;
   }
   return true;
}


void display(struct Node *p)
{
    printf("\nLinked-List Elements : ");
    do
    {
        printf("%d ",p->data);
        p = p->next;
    }
    while(p != first);
}

int main()
{
    int n;

    printf("\nEnter the Number of Elements : ");
    scanf("%d",&n);

    create_circular_ll(n);
    // display(first);

    bool result = check_circular(first);
    
    if(result == true)
        printf("\nLinked List is Circular\n");
    else
        printf("\nLinked List is Not Circular\n");
    
    return 0;
}