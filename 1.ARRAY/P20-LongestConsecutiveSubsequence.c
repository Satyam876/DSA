#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
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


int longest_consecutive_subsequence(int *A,int n)
{
    int count = 0,prev=0;

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(A[j] < A[i])
                swap(&A[i],&A[j]);
        }
    }
    printf("\n");
    for(int i=0; i<n; i++)
        printf("%d ",A[i]);
    int k=0;
    while(k < n)
    {
        if(A[k+1] == A[k] + 1 && prev == 0)
            count++;
        else
            prev++;
        
        k++;
    }
    return count+1;
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

    printf("\nEnter the Size of Array : ");
    scanf("%d",&n);

    A = (int *)malloc(n*sizeof(int));

    get_input(A,n);
    display(A,n);

    printf("\nLongest Consecutive Subsequence : %d\n",longest_consecutive_subsequence(A,n));

    return 0;
}