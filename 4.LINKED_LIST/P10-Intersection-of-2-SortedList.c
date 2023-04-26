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


void intersection_sorted_list(struct Node *head1,struct Node *head2)
{
    struct Node *last3;
    int count = 0;
    while(head1 != NULL && head2 != NULL)
    {
        if(head1->data < head2->data)
            head1 = head1->next;
        else if(head2->data < head1->data)
            head2 = head2->next;
        else
        {
            struct Node *temp;
            temp = (struct Node *)malloc(sizeof(struct Node));

            temp->data = head1->data;
            temp->next = NULL;
            
            if(first3 == NULL)
            {
                first3 = temp;
                last3 = temp;
            }
            else{
                last3->next = temp;
                last3 = temp;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
    }
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

    intersection_sorted_list(first1,first2);
    display(first3);

    return 0;
}