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


void display(int *A,int n)
{
    printf("\nArray Elements : ");
    for(int i=0; i<n; i++)
    {
        printf("%d ",A[i]);
    }
}

int number_of_boats(int *A,int n,int limit)
{
    int count=0;

    for(int i=0; i<n; i++)
    {
            for(int j=i+1; j<n; j++)
            {
                if(A[i] != -1)
                {
                    if((A[i]+A[j]) <= limit)
                    {
                        count++;
                         printf("\n%d",count);
                        A[i] = A[j] = -1;
                          display(A,n);
                    }
                }
            }
    }


    for(int i=0; i<n; i++)
    {
        if(A[i] <= limit && A[i] != -1)
            count++;
    }
    return count;
}




int main()
{
    int *A;
    int n;
    int limit;

    printf("\nEnter the size of Array : ");
    scanf("%d",&n);

    printf("\nEnter the Boat limit : ");
    scanf("%d",&limit);

    get_input(A,n);
    display(A,n);

    printf("\nTotal Number of Boats : %d\n",number_of_boats(A,n,limit));

    return 0;
}