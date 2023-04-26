#include<stdio.h>
#include<stdlib.h>


struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}*first = NULL;


void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}



void create(int n)
{
    struct Node *t,*last;

    first = (struct Node *)malloc(sizeof(struct Node));
    printf("\nEnter #1 Node Element : ");
    scanf("%d",&first->data);
    first->prev = NULL;
    first->next = NULL;
    last = first;

    for(int i=1; i<n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter #%d Node Element : ",i+1);
        scanf("%d",&t->data);
        t->next = NULL;
        t->prev = last;
        last->next = t;
        last = t;
    }
}


void sort_k_sorted_dll(struct Node *p,int k)
{
    struct Node *q=p,*r=NULL,*s=p,*m=NULL;

    while(p != NULL)
    {
        int i=0;

        while(i < k && q != NULL)
        {
            q = q->next;
            i++;
        }

        if( p != first)
        {
            int j=0;
            while( j < k && s != NULL)
            {
                s = s->prev;
                j++;
            }
            r = s;

            do
            {
                if(r->data > p->data)
                {
                    swap(&r->data,&p->data);
                }
                r = r->next;
            }
            while(r != p);
        }

        m = p->next;

        do
        {
            if(m->data < p->data)
            {
                swap(&m->data,&p->data);
            }
            m = m->next;
        }
        while(m != q);
    }
}

void display(struct Node *p)
{
    printf("\nLinked - List Elements  : ");
    while(p != NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
}


int main()
{
    int n;
    int k;

    printf("\nEnter the length of Doubly Linked-List : ");
    scanf("%d",&n);

    create(n);
    display(first);

    printf("\nEnter the 'K' Value : ");
    scanf("%d",&k);

    sort_k_sorted_dll(first,k);
    display(first);

    return 0;
}