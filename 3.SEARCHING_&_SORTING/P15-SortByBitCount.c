#include<stdio.h>
#include<stdlib.h>

void get_input(int *A,int n)
{
    printf("\nEnter Array Elements :\n");
    for(int i=0; i<n; i++)
    {
        printf("\nEnter #%d Element : ",i+1);
        scanf("%d",&A[i]);
    }
}


void sort_by_bit_count(int *A,int n)
{
    int B[100];

    for(int i=0,j=0; i<n,j<n; i++,j++)
    {
            int rem=0;
            int count=0;

            while(A[i] != 0)
            {
                rem = A[i]%2;
                if(rem == 1)
                    count++;
                A[i] = A[i]/2;
            }
                B[j] = count;
    }


    printf("\n\nSorted Array By Bit-Count : ");

    for(int i=0; i<n; i++)
    {
        int max = 0;
        for(int j=0; j<n; j++)
        {
            if(B[j] != -1)
            {
                if(B[j] > max)
                     max = j;
            }
        }
        printf("%d ",A[max]);
        B[max] = -1;
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

    printf("\nEnter the Size of Array : ");
    scanf("%d",&n);

    A = (int *)malloc(n*sizeof(int));

    get_input(A,n);
    display(A,n);

    sort_by_bit_count(A,n);

    return 0;
}