#include<stdio.h>
#include<stdlib.h>

int max_func(int *A,int n)
{
    int max = 0;

    for(int i=0; i<n; i++)
    {
        if(A[i] > A[max])
            max = i;
    }
    return A[max];
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

int max_product_subarray(int *A,int n)
{
    int B[100];
    int k=0;

    for(int i=0; i<n; i++)
    {
        int product = A[i];
        B[k++] = A[i];

        for(int j=i+1; j<n; j++)
        {
            product *= A[j];
            if(product < 0)
            {
                product = -product;
            }
            B[k++] = product;
        }
    }

    return max_func(B,k);
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

    printf("\nMaximum Product of Subarray : %d\n",max_product_subarray(A,n));

    return 0;
}