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


void four_numbers_of_sum(int *A,int n,int sum)
{
    int B[100];
    int m=0;

    printf("\nOUTPUT :\n");
    printf("\nq1->q2->q3->q4\n");

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            for(int k=j+1; k<n; k++)
            {
                for(int l=k+1; l<n; l++)
                {
                    if((A[i] + A[j] + A[k] + A[l]) == sum)
                    {
                        printf("%d %d %d %d\n",A[i],A[j],A[k],A[l]);   
                    }
                }
            }
        }
    }
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

    four_numbers_of_sum(A,n,sum);

    return 0;
}