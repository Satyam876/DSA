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


int zero_sum_subarrays(int *A,int n)
{
    int count = 0;

    for(int i=0; i<n; i++)
    {
        int sum = A[i];

        if(sum == 0)
            count++;
        
        for(int j = i+1; j<n; j++)
        {
            sum += A[j];
            if(sum == 0)
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
    int sum;

    printf("\nEnter the size of Array : ");
    scanf("%d",&n);

    A = (int *)malloc(n*sizeof(int));

    get_input(A,n);
    display(A,n);

    printf("\n\nTotal Number of Zero Sum Subarrays : %d\n",zero_sum_subarrays(A,n));

    return 0;
}