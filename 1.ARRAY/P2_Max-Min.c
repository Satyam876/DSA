#include<stdio.h>
#include<stdlib.h>

    int max;
    int min;

void get_input(int *A,int n)
{
    printf("\nEnter Array Elements\n");
    for(int i=0; i<n; i++)
    {
        printf("Enter #%d Element : ",i+1);
        scanf("%d",&A[i]);
    }
}

void max_min(int *A,int l,int h)
{
    int max1,min1,mid;

    if(l == h)
    {
        max = A[l];
        min = A[l];
    }
    else if(l == h-1)
    {
        if(A[l] > A[h])
        {
            max = A[l];
            min = A[h];
        }
        else{
            max = A[h];
            min = A[l];
        }
    }
    else
    {
        mid = (l+h)/2;

        max_min(A,l,mid);
        
        max1 = max;
        min1 = min;

        max_min(A,mid+1,h);

        if(max1 > max)
            max = max1;
        if(min1 < min)
            min = min1;
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

    printf("\nEnter the size of Array : ");
    scanf("%d",&n);

    A = (int *)malloc(n*sizeof(int));

    get_input(A,n);
    display(A,n);

    max_min(A,0,n-1);

    printf("\nMaximum Element : %d",max);
    printf("\nMinimum Element : %d",min);

    return 0;
}