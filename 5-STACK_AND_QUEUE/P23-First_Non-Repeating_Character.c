#include<stdio.h>
#include<stdlib.h>

struct Queue{
    int size;
    int front;
    int rear;
    char *A;
};

void create(struct Queue *q,int n)
{
    q->size = n;
    q->front = q->rear =-1;
    q->A =(char *)malloc(n*sizeof(char));
}

void enqueue(struct Queue *q,char ch)
{
    if(q->rear == q->size-1)
        printf("\nQueue is Full\n");
    else
    {
        q->rear++;
        q->A[q->rear] = ch;
    }
}

char dequeue(struct Queue *q)
{
    char value;
    if(q->front == q->rear)
        printf("\nQueue is Empty\n");
    else
    {
        q->front++;
        value = q->A[q->front];
    }
    return value;
}

void display(struct Queue *q)
{
    printf("\nQueue : ");
    for(int i=q->front+1; i<=q->rear; i++)
    {
        printf("%c ",q->A[i]);
    }
}

void first_nonrepeating_character(struct Queue *q,char *exp,int n)
{
    int count_same = 0,count_alag = 0,index = 0;

    for(int i=0; exp[i] != '\0'; i++)
    {
        if(i == 0)
        {
            enqueue(q,exp[i]);
            printf("\nQueue Rear : %d",q->rear);
        }
        else{
          for(int j=0; j<n; j++)
          {
                if(exp[j+1] != exp[j])
                {
                    index = j+1;
                    break;
                }
          }
          printf("\nIndex  : %c\n",exp[index]);
          for(int j=0; j<n; j++)
          {
            if(exp[j+1] == exp[j])
                count_same++;
            else
                count_alag++;
          }
          for(int j=0; j<count_same; j++)
          {
                enqueue(q,'#');
          }
          for(int j=0; j<count_alag; j++)
          {
                enqueue(q,exp[index]);
          }
        }
    }
}


int main()
{
    int n;
    printf("Enter the size : ");
    scanf("%d",&n);

    struct Queue q;
    char *exp = "xyzaaabbcd";

    create(&q,n);
    first_nonrepeating_character(&q,exp,n);
    display(&q);

    return 0;
}