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

void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void rearrange_array(int *A,int n)
{
    int i=0,j;
    while(i < n)
    {
        j = i+1;
        if(A[i] < 0)
        {
            while(A[j] < 0 && j < n-1)
                j++;
        }
        else
        {
            while(A[j] >= 0 && j < n-1)
                j++;
        }
        swap(&A[i+1],&A[j]);
        i++;
    }
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

    printf("\n Enter size of Array : ");
    scanf("%d",&n);

    A = (int *)malloc(n*sizeof(int));

    get_input(A,n);
    printf("\nBEFORE RE-ARRANGING\n");
    display(A,n);

    printf("\nAFTER RE-ARRANGING\n");
    rearrange_array(A,n);
    display(A,n);

    return 0;
}