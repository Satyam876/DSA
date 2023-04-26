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


int maxSubarray_sum(int *A,int n)
{
    int C[100];
    int k=0,count=0,max;

    for(int i=0; i<n; i++)
    {
        int sum=0;
        for(int j=i; j<n; j++)
        {
            sum += A[j];
            C[k++] = sum;
            count++;
        }
        sum=0;
    }
    max = C[0];
    for(int i=0; i<count; i++)
    {
        if(C[i] > max)
            max = C[i];
    }
    return max;
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

    printf("\nEnter the size of Array : ");
    scanf("%d",&n);

    A = (int *)malloc(n*sizeof(int));

    get_input(A,n);
    display(A,n);

    printf("\n\nMaximum Subarray Sum : %d\n",maxSubarray_sum(A,n));

    return 0;
}