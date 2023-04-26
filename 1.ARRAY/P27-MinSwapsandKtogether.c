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


int minimum_swaps(int *A,int n,int k)
{
    int i=0;
    int j= n-1;
    int count = 0 ;

    while(i < j)
    {
        while(A[i] < k)
            i++;
        while(A[j] > k)
            j--;

        if(i < j)
        {
            swap(&A[i],&A[j]);
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
    int k;

    printf("\nEnter size of Array : ");
    scanf("%d",&n);

    A = (int *)malloc(n*sizeof(int));

    printf("\nEnter the value of k : ");
    scanf("%d",&k);

    get_input(A,n);
    display(A,n);

    printf("\nMinimum Number of Swaps to bring smaller than k elements Together : %d\n",minimum_swaps(A,n,k));

    return 0;
}