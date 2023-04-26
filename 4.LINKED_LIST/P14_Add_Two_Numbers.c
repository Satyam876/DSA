#include<stdio.h>
#include<stdlib.h>


struct Node{
    int data;
    struct Node *next;
}*first=NULL,*second=NULL;


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
void create2(int n)
{
    struct Node *t,*last;
    second = (struct Node *)malloc(sizeof(struct Node));

    printf("\nEnter #1 Element : ");
    scanf("%d",&second->data);
    
    second->next = NULL;
    last = second;

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


struct Node *add_two_LL(struct Node *p,int n1,struct Node *q,int n2)
{
    struct Node *l3=NULL,*last_ptr;
    struct Node *t=NULL;

    // l3 = (struct Node *)malloc(sizeof(struct Node));

    int sum1=0,sum2=0;
    int rem1=0,rem2=0;
    int sum=0;

    while(p != NULL)
    {
        rem1 = p->data;
        sum1 = sum1*10 + p->data;
        p = p->next;  
    }
    while(q != NULL)
    {
        rem2 = q->data;
        sum2 = sum2*10 + q->data;
        q = q->next;  
    }
    if(sum1 %10 == 0)
        sum1 = sum1*10;
    if(sum2 %10 == 0)
        sum2 = sum2*10;
    printf("\nOriginal Num 1 : %d",sum1);
    printf("\nOriginal Num 2 : %d",sum2);
    // return sum1+sum2;
        int rev_num1=0,rev_num2=0,r1=0,r2=0;
    while(sum1)
    {
        r1 = sum1%10;
        rev_num1 = rev_num1*10 + r1;
        sum1 = sum1/10;
    }

    while(sum2)
    {
        r2 = sum2%10;
        rev_num2 = rev_num2*10 + r2;
        sum2 = sum2/10;
    }

    sum = rev_num1 + rev_num2;

    // sum = sum1 + sum2;
    printf("\nSum1 : %d ",rev_num1);
    printf("\nSum2 : %d ",rev_num2);
    printf("\nSum : %d ",sum);

    if(sum !=0)
    {
        while(sum)
        {
            t = (struct Node *)malloc(sizeof(struct Node));
            t->data = sum%10;
            t->next = NULL;

            if(l3 == NULL)
            {
                l3 = t;
                last_ptr = t;
            }
            else{
                last_ptr->next = t;
                last_ptr = t;
            }
            sum = sum/10;
        }
    }
    else
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = sum%10;
        t->next = NULL;
        l3 = t;
    }
    return l3;
}


int main()
{
    struct Node *result;
    int n1,n2;
    printf("\nEnter the size of 1st Linked-List : ");
    scanf("%d",&n1);

    create(n1);
    display(first);

    printf("\nEnter the size of 1st Linked-List : ");
    scanf("%d",&n2);

    create2(n2);
    display(second);

    // printf("\nResult of 1 addition to Linked-List Number : %d\n",add_two_LL(first,n1,second,n2));

    result = add_two_LL(first,n1,second,n2);
    display(result);

    return 0;
}