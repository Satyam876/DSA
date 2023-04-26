#include<stdio.h>
#include<stdlib.h>

int maximum(int *A,int n)
{
    int max = 0;
    for(int i=0; i<n; i++)
    {
        if(A[i] > A[max])
            max = i;
    }
    return A[max];
}

int minimum(int *A,int n)
{
    int min = 0;
    for(int i=0; i<n; i++)
    {
        if(A[i] < A[min])
            min = i;
    }
    return A[min];
}

void get_input(int *A,int n)
{
    printf("\nEnter Input\n");
    for(int i=0; i<n; i++)
    {
        printf("Enter #%d Element : ",i+1);
        scanf("%d",&A[i]);
    }
}


int minimize_height(int *A,int n,int k)
{
    int mid = (n/2) - 1;
    int diff=0;

    
    for(int i=0; i<=mid; i++)
    {
        A[i] = A[i] + k;
    }
    for(int i=mid+1; i<n; i++)
    {
        A[i] = A[i] - k;
    }

    diff = maximum(A,n) - minimum(A,n);
    
    return diff;
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
    int k;

    printf("\nEnter size of Array : ");
    scanf("%d",&n);

    A = (int *)malloc(n*sizeof(int));

    printf("\nEnter value of k : ");
    scanf("%d",&k);

    get_input(A,n);
    display(A,n);

    printf("\nHeight Difference : %d\n",minimize_height(A,n,k));
   
    return 0;
}