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


int majority_element(int *A,int n)
{
    int *B;
    int index;
    int element = -1;

    B = (int *)malloc(n*sizeof(int));

    for(int i=0; i<n; i++)
    {
        B[i] = 0;
    }

    for(int i=0; i<n; i++)
    {
        index = A[i];
        B[index]++;
    }

    for(int i=0; i<n; i++)
    {
        if(B[i] > n/2)
            element = B[i];
    }
    return element;
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

    printf("\nEnter the size of Array : ");
    scanf("%d",&n);

    A = (int *)malloc(n*sizeof(int));

    get_input(A,n);
    display(A,n);

    printf("\n\nElement that appeared for more than N/2 times : %d\n",majority_element(A,n));

    return 0;
}