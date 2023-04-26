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

void reverse(struct Node *p)
{
    struct Node *q = p->next;
    struct Node *r =NULL;

    while( q!= NULL)
    {
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    first->next = NULL;
    first = p;
}

int check_palindrome(struct Node *p)
{
    int A[100];
    int B[100];
    int k = 0,m=0;

    while(p != NULL)
    {
        A[k++] = p->data;
        p = p->next;
    }
    p = first;

    reverse(first);

    struct Node *q=first;
    while(q != NULL)
    {
        B[m++] = q->data;
        q = q->next;
    }

    int i=0,j=0;
    int count = 0;
    
    while(i < k && j < m)
    {
        if(A[i] != B[j])    
            count++;
        i++;
        j++;
    }
    if(count == 0)
        return 1;
    else
        return 0;
}

int main()
{
    int n;

    printf("\nEnter the size of Linked-List : ");
    scanf("%d",&n);

    create(n);
    display(first);

    int result = check_palindrome(first);

    if(result == 1)
        printf("\nLinked List is Plaindrome\n");
    else
        printf("\nLinked List is Not Plaindrome\n");

    return 0;
}