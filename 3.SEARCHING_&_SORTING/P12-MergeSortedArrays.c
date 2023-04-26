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


void merge_sorted_array(int *A1,int *A2,int n1,int n2)
{
    int *C;
    C = (int *)malloc((n1+n2)*sizeof(int));

    int i=0,j=0,k=0;

    while(i < n1 && j < n2)
    {
        if(A1[i] < A2[j])
            C[k++] = A1[i++];
        else
            C[k++] = A2[j++];
    }

    for(; i<n1; i++)
        C[k++] = A1[i];
    for(; j<n2; j++)
        C[k++] = A2[j];

    printf("\n\nMerged Sorted Array : ");
    for(int m=0; m<k; m++)
        printf("%d ",C[m]);
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
    int *A1,*A2;
    int n1,n2;
    int sum;

    printf("\nEnter the size of 1st Array : ");
    scanf("%d",&n1);

    A1 = (int *)malloc(n1*sizeof(int));

    get_input(A1,n1);
    display(A1,n1);

    printf("\n\nEnter the size of 2nd Array : ");
    scanf("%d",&n2);

    A2 = (int *)malloc(n2*sizeof(int));

    get_input(A2,n2);
    display(A2,n2);

    merge_sorted_array(A1,A2,n1,n2);

    return 0;
}