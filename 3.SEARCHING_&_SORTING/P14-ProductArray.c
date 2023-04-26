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



void product_array(int *A,int n)
{
    int *P;
    P = (int *)malloc((n)*sizeof(int));

    int product = 1;
    int count = 0;
    int j=0;

    while(j < n)
    {
        if(A[j] == 0)
        {
            j++;
            count++;
        }   
        else
            product = product*A[j];
        j++;
    }

    for(int i=0; i<n; i++)
    {
        if(A[i] != 0 && count == 0)
        {
            P[i] = product/A[i];
        }
        else if(A[i] != 0 && count > 0)
        {
            P[i] = 0;
        } 
        else
        {
            P[i] = product;
        }
    }

    printf("\n\nProduct Array : ");
    for(int i=0; i<n; i++)
    {
        printf("%d ",P[i]);
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
    int sum;

    printf("\nEnter the size of Array : ");
    scanf("%d",&n);

    A = (int *)malloc(n*sizeof(int));

    get_input(A,n);
    display(A,n);

    product_array(A,n);

    return 0;
}