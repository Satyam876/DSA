#include<stdio.h>
#include<stdlib.h>


void get_input(int *A,int n)
{
    printf("\n Enter Input \n");
    for(int i=0; i<n; i++)
    {
        printf("Enter #%d Element : ",i+1);
        scanf("%d",&A[i]);
    }
}

int subarray_zero_sum(int *A,int n)
{
    int B[100];
    int sum;
    int k=0,count=0;

    for(int i=0; i<n; i++)
    {
        sum = A[i];
        B[k++] = A[i];
        for(int j=i+1; j<n; j++)
        {
            sum += A[j];
            B[k++] = sum;
        }
    }

    for(int i=0; i<k; i++)
    {
       if(B[i] == 0)
        return 1;
    }
    return 0;
}

void display(int *A,int n)
{
    printf("\nArray Elements : ");
    for(int i=0; i<n ;i++)
    {
        printf("%d ",A[i]);
    }
}


int main()
{
    int *A;
    int n;

    printf("\nEnter size of Array : ");
    scanf("%d",&n);

    A = (int *)malloc(n*sizeof(int));

    get_input(A,n);
    display(A,n);

    int result = subarray_zero_sum(A,n);

    if(result == 1)
        printf("\nYES\n");
    else
        printf("\nNO\n");

    return 0;
}