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
    printf("\nEnter Array Elements :\n");
    for(int i=0; i<n; i++)
    {
        printf("\nEnter #%d Element : ",i+1);
        scanf("%d",&A[i]);
    }
}


int minimum_swaps_to_sort(int *A,int n)
{
    int swap_count=0;

    for(int i=0; i<n-1; i++)
    {
        int min = i;
        int temp = A[i];

        for(int j=i; j<n; j++)
        {
            if(A[j] < A[min])
                min = j;
        }
        swap(&A[i],&A[min]);

        if(A[i] != temp)
            swap_count++;
    }

    printf("\nSorted : ");
    for(int k=0; k<n; k++)
    {
        printf("%d ",A[k]);
    }
    return swap_count;
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

    printf("\n\nMinimum Number of Swaps to Sort the Array : %d\n",minimum_swaps_to_sort(A,n));

    return 0;
}