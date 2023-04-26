#include<stdio.h>
#include<stdlib.h>

void get_input(int *A,int n)
{
    printf("\nEnter Array Elements\n");
    for(int i=0; i<n; i++)
    {
        printf("Enter #%d Element : ",i+1);
        scanf("%d",&A[i]);
    }
}

void first_last_occurence(int *A,int n,int X)
{
    int i=0,j=0,last_dup=0;

    for(int i=0; i<n; i++)
    {
        if(A[i] == X)
        {
            last_dup = i;
            j = i+1;

            while(j < n)
            {
                if(A[j] == A[i] && A[j] != -1)
                {
                    last_dup = j;
                    A[j] = -1;
                }
                j++;
            }
            printf("\nElement %d First Occurence is at Index %d and Last is at Index %d\n",X,i,last_dup);
        }
    }
}


void display(int *A,int n)
{
    printf("\nArray Elements : ");
    for(int i=0; i<n; i++)
    {
        printf("%d ",A[i]);
    }
}

int main()
{
    int n;
    int *A;
    int x;

    printf("\nEnter the Size of Array : ");
    scanf("%d",&n);

    A = (int *)malloc(n*sizeof(int));

    get_input(A,n);
    display(A,n);

    printf("\n\nEnter the Element to Search : ");
    scanf("%d",&x);

    first_last_occurence(A,n,x);

    return 0;
}