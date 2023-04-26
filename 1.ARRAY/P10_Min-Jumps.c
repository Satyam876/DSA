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

int minimum_jumps(int *A,int n)
{
    int i=0,count=0;

    if(n == 0)
        return -1;
    else
    {
        while(i <= n)
        {
            i += A[i];
            if(i != n-1)
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

    printf("\nEnter the size of Array : ");
    scanf("%d",&n);

    A = (int *)malloc(n*sizeof(int));

    printf("\nBefore Roatation\n");
    get_input(A,n);
    display(A,n);

    printf("\n\nMinimum Number of Jumps to Reach End of Array : %d\n",minimum_jumps(A,n));

    return 0;
}