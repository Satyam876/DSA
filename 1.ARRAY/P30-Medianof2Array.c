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


int median_func(int *A,int n1,int *B,int n2)
{
    int C[100];
    int i=0,j=0,k=0;
    int value = 0;

    while(i < n1 && j < n2)
    {
        if(A[i] <= B[j])
            C[k++] = A[i++];
        else
            C[k++] = B[j++];
    }

    for(; i<n1; i++)
        C[k++] = A[i];
    for(; j<n2; j++)
        C[k++] = B[j];

    printf("\n\nMERGERD ARRAY:\n");
    for(int m=0; m<k; m++)
    {
        printf("%d ",C[m]);
    }
    

    if(k % 2 == 0)
    {
        value = (C[(k/2)-1] + C[((k/2)+1)-1])/2;
    }
    else
    {
        value = C[((k+1)/2)-1];
    }
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
    int *A,*B;
    int n1,n2;


    printf("\nEnter size of 1st Array : ");
    scanf("%d",&n1);

    A = (int *)malloc(n1*sizeof(int));

    printf("\nEnter size of 2nd Array : ");
    scanf("%d",&n2);

    B = (int *)malloc(n2*sizeof(int));


    get_input(A,n1);
    display(A,n1);

    get_input(B,n2);
    display(B,n2);

    printf("\n\nMedian : %d\n",median_func(A,n1,B,n2));
   
    return 0;
}