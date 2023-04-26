#include<stdio.h>
#include<stdlib.h>

void get_input(int *A,int n)
{
    for(int i=0; i<n; i++)
    {
        printf("Enter #%d Element : ",i+1);
        scanf("%d",&A[i]);
    }
}

void find_common_element(int *A,int *B,int *C,int n1,int n2,int n3)
{
    int D[100];
    int i=0,j=0,k=0,m=0;

    printf("\n1\n");
    while(i < n1 && j < n2 && k < n3)
    {
        if(A[i] == B[j] == C[k])
        {
            D[m++] = A[i];
            i++;
            j++;
            k++;
        }
        else if(A[i] < B[j] && A[i] < C[k])
            i++;
        else if(B[j] < A[i] && B[j] < C[k])
            j++;
        else if(C[k] < A[i] && C[k] < B[j])
            k++;
    }
    printf("\n2\n");

    printf("\n\nCommon Elements in all 3-Array are : ");
    int x=0;
    while(x < m)
    {
        printf("%d ",D[x]);
        x++;
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
    int *A,*B,*C;
    int n1,n2,n3;

    printf("\nEnter the Size of 1st Array : ");
    scanf("%d",&n1);
    A = (int *)malloc(n1*sizeof(int));
    printf("\nEnter 1st Array Elements\n");
    get_input(A,n1);
    display(A,n1);

    printf("\nEnter the Size of 2nd Array : ");
    scanf("%d",&n2);
    B = (int *)malloc(n2*sizeof(int));
    printf("\nEnter 2nd Array Elements\n");
    get_input(B,n2);
    display(B,n2);
    
    printf("\nEnter the Size of 3rd Array : ");
    scanf("%d",&n3);
    C = (int *)malloc(n3*sizeof(int));
    printf("\nEnter 3rd Array Elements\n");
    get_input(C,n3);
    display(C,n3);


   find_common_element(A,B,C,n1,n2,n3);

    return 0;
}