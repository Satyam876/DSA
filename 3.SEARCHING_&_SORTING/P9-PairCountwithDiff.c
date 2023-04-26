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


int pair_count_with_difference(int *A,int n,int N)
{
    int pair_count=0;
    int diff;

    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            diff = A[i] - A[j];
            
            if(diff < 0)
                diff = -diff;
            
            if(diff == N)
                pair_count++;
        }
    }
    return pair_count;
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
    int N;

    printf("\nEnter the size of Array : ");
    scanf("%d",&n);

    A = (int *)malloc(n*sizeof(int));

    get_input(A,n);
    
    printf("\nEnter the Difference : ");
    scanf("%d",&N);

    display(A,n);

    printf("\n\nTotal Pairs with given Difference : %d\n",pair_count_with_difference(A,n,N));

    return 0;
}