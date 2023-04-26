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


void missing_and_repeat(int *A,int n)
{
    int B[100];
    int index;
    int missing,repeat;

    for(int i=0; i<n; i++)
    {
        B[i] = 0;
    }

    for(int i=0; i<n; i++)
    {
        index = A[i];
        B[index]++;
    }

    for(int i=1; i<=n; i++)
    {
        if(B[i] == 0)
            missing = i;
        
        else if(B[i] > 1)
            repeat = i;
    }

    printf("\nMissing Element : %d\n",missing);
    printf("\nRepeated Element : %d\n",repeat);
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

    printf("\nEnter the size of Array : ");
    scanf("%d",&n);

    A = (int *)malloc(n*sizeof(int));

    get_input(A,n);
    display(A,n);

    missing_and_repeat(A,n);

    return 0;
}