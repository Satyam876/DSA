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
    first->next = first;
    last = first;

    for(int i=1; i<n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter #%d Element : ",i+1);
        scanf("%d",&t->data);
        t->next = first;
        last->next = t;
        last = t;
    }
}



void delete_from_circular(struct Node *p,int key)
{
    struct Node *q=NULL,*r=NULL;
    struct Node *s=p->next;

    while(s->next != first)
    {
        s = s->next;
    }

    if(first->data == key)
    {
        q = first;
        s->next = first->next;
        first = first->next;
        q->next = NULL;
        free(q);
    }
    else{
        do{
            q = p->next;
            r = p;
            p = q;

            if(q->data == key)
            {
                r->next = q->next;
                q->next = NULL;
                free(q);
                break;
            }
        }
        while(p != first);
    }
}


void display(struct Node *p)
{
    printf("\nLinked-List Elements : ");
    do{
        printf("%d ",p->data);
        p = p->next;
    }
    while(p != first);
}

int main()
{
    int n;
    int key;

    printf("\nEnter Size of Linked List : ");
    scanf("%d",&n);

    create(n);
    display(first);

    printf("\nEnter the Element to Delete : ");
    scanf("%d",&key);

    delete_from_circular(first,key);
    display(first);

    return 0;
}