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


void common_element(int *A,int n1,int *B,int n2,int *C,int n3)
{
    int D[100];
    int i=0,j=0,k=0,m=0;

    while(i<n1 && j<n2 && k<n3)
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

    printf("\n\nCommom Elements : ");
    for(int x=0; x<m; x++)
    {
        printf("%d ",D[x]);
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


    printf("\nEnter size of 1st Array : ");
    scanf("%d",&n1);

    A = (int *)malloc(n1*sizeof(int));

    printf("\nEnter size of 2nd Array : ");
    scanf("%d",&n2);

    B = (int *)malloc(n2*sizeof(int));

    printf("\nEnter size of 3rd Array : ");
    scanf("%d",&n3);

    C = (int *)malloc(n3*sizeof(int));


    printf("\nEnter 1st Array Input\n");
    get_input(A,n1);
    display(A,n1);

    printf("\n\nEnter 2nd Array Input\n");
    get_input(B,n2);
    display(B,n2);

    printf("\n\nEnter 3rd Array Input\n");
    get_input(C,n3);
    display(C,n3);

    common_element(A,n1,B,n2,C,n3);
   
    return 0;
}