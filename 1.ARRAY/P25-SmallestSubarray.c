#include<stdio.h>
#include<stdlib.h>


void get_input(int *A,int n)
{
    printf("\nEnter Input\n");
    for(int i=0; i<n; i++)
    {
        printf("Enter #%d Element : ",i+1);
        scanf("%d",&A[i]);
    }
}


int smallest_subarray(int *A,int n,int x)
{
    int sum,count;

    for(int i=0; i<n; i++)
    {
        sum=0;
        count=0;

        for(int j=i; j<n; j++)
        {
            sum += A[j];
            count++;

            if(sum > x)
            {
                return count-1;
            }
        }
    }
    return 0;
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
    int x;

    printf("\nEnter size of Array : ");
    scanf("%d",&n);

    printf("\nEnter the X value : ");
    scanf("%d",&x);

    A = (int *)malloc(n*sizeof(int));

    get_input(A,n);
    display(A,n);

    printf("\nSmallest Subarray : %d\n",smallest_subarray(A,n,x));

    return 0;
}