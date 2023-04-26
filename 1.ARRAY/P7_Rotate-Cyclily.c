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

void rotate(int *A,int n)
{
    int i = n-2;
    int x = A[n-1];

    while(i >= 0)
    {
        A[i+1] = A[i];
        i--;
    }
    A[i+1] = x;
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

    printf("\nAfter Rotation\n");
    rotate(A,n);
    display(A,n);

    return 0;
}