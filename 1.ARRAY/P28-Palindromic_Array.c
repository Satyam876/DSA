#include<stdio.h>
#include<stdlib.h>


void get_input(int *A,int n)
{
    printf("\nEnter Input\n");
    for(int i=0; i<n; i++)
    {
        printf("Enter #%d Element : ",i+1);
        scanf("%d",&A[i]);
    }
}


int palindromic_array(int *A,int n)
{
    for(int i=0; i<n; i++)
    {
        int org=0,rem=0,rev=0;
        org = A[i];

        while(A[i] != 0)
        {
            rem = A[i] % 10;
            rev = rev*10 + rem;
            A[i] = A[i]/10;
        }
        
        if(rev != org)
            return 0;
    }
    return 1;
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
    int result;

    printf("\nEnter size of Array : ");
    scanf("%d",&n);

    A = (int *)malloc(n*sizeof(int));


    get_input(A,n);
    display(A,n);

    result = palindromic_array(A,n);

    if(result == 1)
        printf("\nArray is Palindromic\n");
    else
        printf("\nArray is not Palindromic\n");
   
    return 0;
}