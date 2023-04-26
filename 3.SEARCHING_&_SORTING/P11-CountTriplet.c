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


int triplet_count(int *A,int n,int sum)
{
    int count=0;

    for(int i=0; i<n-2; i++)
    {
        for(int j=i+1; j<n-1; j++)
        {
            for(int k=j+1; k<n; k++)
            {
                    if((A[i] + A[j] + A[k]) < sum)
                    {
                        count++;  
                    }
            }
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
    int sum;

    printf("\nEnter the size of Array : ");
    scanf("%d",&n);

    A = (int *)malloc(n*sizeof(int));

    get_input(A,n);
    
    printf("\nEnter the Sum : ");
    scanf("%d",&sum);

    display(A,n);

    printf("\n\nTotal Number of Triplets with sum smaller than %d : %d\n",sum,triplet_count(A,n,sum));

    return 0;
}