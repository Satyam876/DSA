#include<stdio.h>
#include<stdlib.h>

int minimum(int *a,int *b)
{
    if(*a > *b)
        return *b;
    else
        return *a;
}

void get_input(int *A,int n)
{
    printf("\nEnter Input\n");
    for(int i=0; i<n; i++)
    {
        printf("Enter #%d Element : ",i+1);
        scanf("%d",&A[i]);
    }
}


int trapping_rain_water_func(int *A,int n)
{
    int boundary = minimum(&A[0],&A[n-1]);
    int water = 0;

    for(int i=1; i<=n-2; i++)
    {
        if(A[i] < boundary)
        {
            water += boundary - A[i];
        }
    }
    return water;
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

    printf("\nTotal Trapped Water is : %d\n",trapping_rain_water_func(A,n));

    return 0;
}