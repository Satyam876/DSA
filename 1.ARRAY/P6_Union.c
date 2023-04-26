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

void union_array(int *A,int *B,int n1,int n2)
{
    int C[100];
    int i=0,j=0,k=0;

    while(i < n1 && j < n2)
    {
        if(A[i] != B[j])
        {
            C[k++] = A[i++];
            C[k++] = B[j++];
        }
        else{
            C[k++] = A[i++];
            j++;
        }
    }
    for(; i<n1; i++)
        C[k++] = A[i];
    for(; j<n2; j++)
        C[k++] = B[j];

    for(; k<(n1+n2); k++)
        C[k] = -1;

    int m=0,count=0;
    printf("\n\nUNION OF ARRAYS : ");
    while( C[m] != -1 && m < (n1+n2))
    {
        printf("%d ",C[m]);
        m++;
        count++;
    }
    printf("\n\nCount of Union Array : %d\n",count);

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


    printf("\n\n** FIRST ARRAY **\n");
    printf("\nEnter the size of 1st Array : ");
    scanf("%d",&n1);

    A = (int *)malloc(n1*sizeof(int));

    get_input(A,n1);
    display(A,n1);

    printf("\n\n** SECOND ARRAY **\n");
    printf("\nEnter the size of 2nd Array : ");
    scanf("%d",&n2);

    B = (int *)malloc(n2*sizeof(int));

    get_input(B,n2);
    display(B,n2);

    union_array(A,B,n1,n2);

    return 0;
}