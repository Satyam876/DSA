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
    printf("\nEnter Array Elements\n\n");
    for(int i=0; i<n; i++)
    {
        printf("Enter #%d Element : ",i+1);
        scanf("%d",&A[i]);
    }
}

void sort012(int *A,int n)
{
   int B[100];
   int k=0;

   for(int i=0; i<n; i++)
   {
        if(A[i] == 0)
            B[k++] = A[i];
   }
   for(int i=0; i<n; i++)
   {
        if(A[i] == 1)
            B[k++] = A[i];
   }
   for(int i=0; i<n; i++)
   {
        if(A[i] == 2)
            B[k++] = A[i];
   }

    printf("\n012 SORTED ARRAY : ");
   for(int j=0; j<k; j++)
   {
        printf("%d ",B[j]);
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
    printf("\n** Before Sorting **\n");
    display(A,n);


    sort012(A,n);

    return 0;
}