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

int search(int *A,int n,int x,int k)
{
    int i=0;
    while(i < n)
    {
        if((A[i+1] - A[i]) > k)
        {
            i = i+2;
        }
        if(A[i] == x)
        {
            return i;
        }
        i++;
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
    int n;
    int k,x;

    printf("\nEnter the size of Array : ");
    scanf("%d",&n);

    A = (int *)malloc(n*sizeof(int));

    get_input(A,n);

    printf("\nEnter the value of x : ");
    scanf("%d",&x);

    printf("\nEnter the Step Array Difference : ");
    scanf("%d",&k);

    display(A,n);

    printf("\nFirst Occurence of x is at index %d \n",search(A,n,x,k));

    return 0;
}