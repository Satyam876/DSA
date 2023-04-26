#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


void get_input(int *A,int n)
{
    printf("\n Enter Input \n");
    for(int i=0; i<n; i++)
    {
        printf("Enter #%d Element : ",i+1);
        scanf("%d",&A[i]);
    }
}

int max_stock_profit(int *A,int n)
{
    int profit=0,tr1,tr2;

    tr1 = A[1] - A[0];
    
    for(int i=2; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            if(A[j] < A[i])
                swap(&A[i],&A[j]);
        }
    }

    tr2 = A[n-1] - A[2];
    profit = tr1 + tr2;

    return profit;
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

    printf("\nEnter size of Array : ");
    scanf("%d",&n);

    A = (int *)malloc(n*sizeof(int));

    get_input(A,n);
    display(A,n);

    printf("\nThe Maximum Profit is : %d\n",max_stock_profit(A,n));

    return 0;
}