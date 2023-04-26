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

void display(int *A,int n)
{
    printf("\nArray Elements : ");
    for(int i=0; i<n; i++)
    {
        printf("%d ",A[i]);
    }
}

void first_negative_in_window(int *A,int n,int k)
{
    int B[100];
    int m = 0;

    for(int i=0; i<n; i++)
    {
        int count = 0;
        for(int j=i; j<i+k; j++)
        {
            if(A[j] < 0)
            {
                B[m++] = A[j];
                count++;
                break;
            }
        }
        if(count == 0)
        {
            B[m++] = 0;
        }
    }
    display(B,m);
}

int main()
{
    int n;
    int *A;
    int k;

    printf("\nEnter size of Array : ");
    scanf("%d",&n);

    A = (int *)malloc(n*sizeof(int));

    get_input(A,n);
    display(A,n);

    printf("\nEnter the Window size : ");
    scanf("%d",&k);

    first_negative_in_window(A,n,k);

    return 0;
}
