#include<stdio.h>
#include<stdlib.h>


void get_input(int *A,int n)
{
    for(int i=0; i<n; i++)
    {
        printf("Enter #%d Element : ",i+1);
        scanf("%d",&A[i]);
    }
}


int subset_array(int *A1,int n1,int *A2,int n2)
{
    int count = 0,unique_count = 0;

    for(int j=0; j<n2; j++)
    {
        for(int i=0; i<n1; i++)
        {
            if(A2[j] == A1[i])
            {
                count++;
               // unique_count++;
            }
        }
    }
    if(count >= n2)
        return 1;
    else
        return 0;
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
    int subset;

    printf("\nEnter the size of 1st Array : ");
    scanf("%d",&n1);
    printf("\nEnter the size of 2nd Array : ");
    scanf("%d",&n2);

    A1 = (int *)malloc(n1*sizeof(int));
    A2 = (int *)malloc(n2*sizeof(int));

    printf("\nFIRST ARRAY\n\n");
    get_input(A1,n1);
    display(A1,n1);

    printf("\n\nSECOND ARRAY\n\n");
    get_input(A2,n2);
    display(A2,n2);

    subset = subset_array(A1,n1,A2,n2);
    if(subset == 1)
        printf("\n\nYES\n");
    else
        printf("\n\nNO\n");

    return 0;
}