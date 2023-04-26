#include<stdio.h>
#include<stdlib.h>

void get_input(int *A,int n)
{
    for(int i=0; i<n ;i++)
    {
        printf("\nEnter #%d Element : ",i+1);
        scanf("%d",&A[i]);
    }
}

int sum_min_max_k_subarray(int *A,int n,int k)
{
    int sum_subarray=0;
    
    for(int i=0; i<= n-k; i++)
    {
        int max = i,min = i;

        for(int j=i; j<= k+i-1; j++)
        {
            if(A[j] > A[max])
                max = j;
        }
        for(int j=i; j<= k+i-1; j++)
        {
            if(A[j] < A[min])
                min = j;
        }
        sum_subarray += (A[max] + A[min]);
    }
    return sum_subarray;
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
    int k;

    printf("\nEnter the Size of Array : ");
    scanf("%d",&n);

    A = (int *)malloc(n*sizeof(int));

    get_input(A,n);
    display(A,n);

    printf("\nEnter the value of k : ");
    scanf("%d",&k);

    printf("\nSum of All Subarrays of size %d is : %d\n",k,sum_min_max_k_subarray(A,n,k));

    return 0;
}