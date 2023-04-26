#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}


int main()
{
    int T;
    printf("\nEnter Number of Test Cases : ");
    scanf("%d",&T);

    for(int i=0; i<T; i++)
    {
        int N,Q;
        printf("\nEnter value of N and Q : ");
        scanf("%d%d",&N,&Q);

        for(int j=0; j<N; j++)
        {
            int A,B;
            printf("\nEnter value of A and B : ");
            scanf("%d%d",&A,&B);

            int *K;
            K = (int *)malloc(Q*sizeof(int));

            for(int m=0; m<Q; m++)
            {
                printf("\nEnter #%d Element : ",m+1);
                scanf("%d",&K[m]);
            }

            for(int m=0; m<Q; m++)
            {
                for(int l=m+1; l<Q; l++)
                {
                    if(K[l] < K[m])
                        swap(&K[m],&K[l]);
                }
            }

            for(int m=0; m<Q; m++)
            {
                if(K[m] >= A && K[m] <= B)
                    printf("%d\n",K[m]);
                else
                    printf("-1\n");
            }
        }
    }
}