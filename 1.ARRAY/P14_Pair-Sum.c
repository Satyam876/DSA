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

int getPairsCount(int arr[], int n, int k) {
    int count = 0;
        
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
                if(arr[i] + arr[j] == k)
                    count++;
        }
    }
    return count;
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
    int k;

    printf("\nEnter number of Elements : ");
    scanf("%d",&n);
    printf("\nEnter the Sum Value : ");
    scanf("%d",&k);

    A = (int *)malloc(n*sizeof(int));

    get_input(A,n);
    display(A,n);

    printf("\n\nTOTAL PAIRS : %d\n",getPairsCount(A,n,k));
    return 0;
}