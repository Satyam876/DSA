#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
    int data;
    struct Node *next;
}*first1=NULL,*first2=NULL,*first3=NULL;


void create1(int n)
{
    struct Node *t,*last;
    first1 = (struct Node *)malloc(sizeof(struct Node));

    printf("\nEnter #1 Element : ");
    scanf("%d",&first1->data);
    
    first1->next = NULL;
    last = first1;

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

void create2(int n)
{
    struct Node *t,*last;
    first2 = (struct Node *)malloc(sizeof(struct Node));

    printf("\nEnter #1 Element : ");
    scanf("%d",&first2->data);
    
    first2->next = NULL;
    last = first2;

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



int intersectPoint(struct Node* head1, struct Node* head2,int n1,int n2)
{
    int count=0;
    int *B = (int *)malloc((n1+n2)*sizeof(int));
    int k=0;
    
    while(head1 != NULL)
    {
        while(head2 != NULL)
        {
            if(head2->data != head1->data)
            {
                head2 = head2->next;
            }
            else{
                B[k++] = head2->data;
                count++;
                head2 = head2->next;
                head1 = head1->next;
            }      
        }
        if(count == 0)
            head1 = head1->next;
    }
    printf("\nCount : %d\n",count);
    if(count > 1)
        return B[0];
    else
        return -1;
}


int main()
{
    int n1,n2;

    printf("\nEnter the size of 1st Linked-List : ");
    scanf("%d",&n1);

    create1(n1);
    display(first1);

    printf("\n\nEnter the size of 2nd Linked-List : ");
    scanf("%d",&n2);

    create2(n2);
    display(first2);

    printf("\n\nIntersection Point : %d\n",intersectPoint(first1,first2,n1,n2));

    return 0;
}