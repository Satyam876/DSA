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

void count_nk_times(int *A,int n,int k)
{
    int B[100];
    int count;
    int m=0;

    for(int i=0; i<n; i++)
    {
        count = 0;
        for(int j=i; j<n; j++)
        {
            if(A[j] == A[i])
                count++;
        }
        if(count > n/k)
            B[m++] = A[i];
    }

    printf("\nOUTPUT : ");
    for(int i=0; i<m; i++)
    {
        printf("%d ",B[i]);
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


int main()
{
    int *A;
    int n,k;

    printf("\nEnter size of Array : ");
    scanf("%d",&n);

    A = (int *)malloc(n*sizeof(int));

    printf("\nEnter the Value of k : ");
    scanf("%d",&k);

    get_input(A,n);
    display(A,n);
    count_nk_times(A,n,k);

    return 0;
}