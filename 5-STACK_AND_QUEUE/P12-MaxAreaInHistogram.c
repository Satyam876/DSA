#include<stdio.h>
#include<stdlib.h>

void get_input(int *A,int n)
{
    for(int i=0; i<n; i++)
    {
        printf("\nEnter #%d Element : ",i+1);
        scanf("%d",&A[i]);
    }
}

int get_max_area_histogram(int *A,int n)
{
    int B[100],m=0;

    for(int i=0; i<n; i++)
    {
        int count=1;
        int j=i,k=i;

        while(j >= 0)
        {
            if(A[j-1] > A[j])
            {
                count++;
                j--;
            }
            else
                break;
        }
        while(k < n)
        {
            if(A[k+1] > A[k])
            {
                count++;
                k++;
            }
            else
                break;
        }
        B[m++] = A[i]*count;
    }

    int max = 0;
    for(int i=0; i<n; i++)
    {
        if(B[i] > B[max])
            max = i;
    }
    return B[max];
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

    printf("\nEnter the Size of Array : ");
    scanf("%d",&n);

    A = (int *)malloc(n*sizeof(int));

    get_input(A,n);
    display(A,n);

    printf("\nMaximum Area of Histogram : %d\n",get_max_area_histogram(A,n));

    return 0;
}