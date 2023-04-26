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

int stockProfit(int *A,int n)
{
    int min = 0;
    for(int i=0; i<n; i++)
    {
        if(A[i] < A[min])
            min = i;
    }
    
    int max = min;

    for(int j=min; j<n; j++)
    {
        if(A[j] > A[max])
            max = j;
    }

    if(min == n-1)
        return 0;
    else
        return A[max]-A[min];
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

    printf("\n\nMaximum Stock Profit : %d\n",stockProfit(A,n));
    return 0;
}