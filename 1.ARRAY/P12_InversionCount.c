#include<stdio.h>
#include<stdlib.h>

void get_input(int *A,int n)
{
    printf("\nEnter Array Elements\n\n");
    for(int i=0; i<n; i++)
    {
        printf("Enter #%d Element : ",i+1);
        scanf("%d",&A[i]);
    }
}

int InversionCount(int *A,int n)
{
    int count=0;
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            if(A[i] > A[j] && i<j)
                count++;
        }
    }
    return count;
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
    int *A;
    int n;

    printf("\nEnter number of Elements : ");
    scanf("%d",&n);

    A = (int *)malloc(n*sizeof(int));

    get_input(A,n);
    display(A,n);

    printf("\nInversion Count : %d\n",InversionCount(A,n));
    return 0;
}