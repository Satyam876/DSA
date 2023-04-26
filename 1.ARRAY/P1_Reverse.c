#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void get_input(int *A,int n)
{
    printf("\nEnter Array Elements\n");
    for(int i=0; i<n; i++)
    {
        printf("Enter #%d Element : ",i+1);
        scanf("%d",&A[i]);
    }
}

void reverse(int *A,int n)
{
    int i=0;
    int j = n-1;

    while(i < j)
    {
        swap(&A[i],&A[j]);
        i++;
        j--;
    }
}

void display(int *A,int n)
{
    printf("Array Elements : ");
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
    printf("\n** Before Reversing **\n");
    display(A,n);

    reverse(A,n);

    printf("\n** After Reversing **\n");
    display(A,n);

    return 0;
}