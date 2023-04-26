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

void positive_negative_sorting(int *A,int n)
{
    int i=0,j=i+1;
    while(i < n-1 && j < n)
    {
        if(A[i] > 0 && A[j] < 0)
            swap(&A[i],&A[j]);
        else if(A[i] > 0 && A[j] > 0)
            j++;
        else{
            i++;
            j++;
        }
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

    positive_negative_sorting(A,n);

    printf("\n\n** After Sorting **\n");
    display(A,n);

    return 0;
}