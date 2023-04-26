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
    printf("\nEnter Input\n");
    for(int i=0; i<n; i++)
    {
        printf("Enter #%d Element : ",i+1);
        scanf("%d",&A[i]);
    }
}


int median_func(int *A,int n)
{
    int value=0;

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(A[j] < A[i])
                swap(&A[i],&A[j]);
        }
    }

    if(n%2 == 0)
    {
        value = (A[(n/2)-1] + A[(n/2 + 1)-1])/2;
    }
    else
        value = A[((n+1)/2)-1];
    
    return value;
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


    printf("\nEnter size of Array : ");
    scanf("%d",&n);

    A = (int *)malloc(n*sizeof(int));


    get_input(A,n);
    display(A,n);

    printf("\nMedian : %d\n",median_func(A,n));
   
    return 0;
}