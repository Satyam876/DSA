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

void partioning(int *A,int n,int a,int b)
{
    int B[100];
    int k=0;

    for(int i=0; i<n; i++)
    {
        if(A[i] < a)
            B[k++] = A[i];
    }
    for(int i=0; i<n; i++)
    {
        if(A[i] >= a && A[i] <= b)
            B[k++] = A[i];
    }
    for(int i=0; i<n; i++)
    {
        if(A[i] > b)
            B[k++] = A[i];
    }

    printf("\nModified Partitioned Array : ");
    for(int j=0; j<k; j++)
    {
        printf("%d ",B[j]);
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
    int a,b;

    printf("\nEnter size of Array : ");
    scanf("%d",&n);

    A = (int *)malloc(n*sizeof(int));

    printf("\nEnter the Lower limit & Upper limit : ");
    scanf("%d%d",&a,&b);

    get_input(A,n);
    display(A,n);

    partioning(A,n,a,b);

    return 0;
}