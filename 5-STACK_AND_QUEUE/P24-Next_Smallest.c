#include<stdio.h>
#include<stdlib.h>

void get_input(int *A,int n)
{
    printf("\nEnter the Array\n");
    for(int i=0; i<n; i++)
    {
        printf("Enter #%d Element : ",i+1);
        scanf("%d",&A[i]);
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



void next_smaller_element(int *A,int n)
{
    int B[100];
    int k = 0;

    for(int i=0; i<n; i++)
    {
            int count = 0;
        for(int j=i+1; j<n; j++)
        {
            if(A[j] < A[i])
            {
                B[k++] = A[j];
                count++;
                break;
            }
        }
        if(count == 0)
        {
            B[k++] = -1;
        }

    }
    printf("\nNext Smaller Elements : ");
    for(int i=0; i<k; i++)
    {
        printf("%d ",B[i]);
    }
}

int main()
{
    int n;
    int *A;

    printf("\nEnter the size of Array : ");
    scanf("%d",&n);

    A = (int *)malloc(n*sizeof(int));

    get_input(A,n);
    display(A,n);

    next_smaller_element(A,n);

    return 0;
}