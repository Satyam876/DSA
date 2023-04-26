#include<stdio.h>
#include<stdlib.h>

int B[1000];
int k=0;

int func1(long int num)
{
    if(num == 0)
        return 1;
    else
    {
        B[k++] = num;
        func1(num-1);
    }
}


int main()
{
    long int n;
    int result = 1;

    printf("\nEnter the Number : ");
    scanf("%d",&n);
    func1(n);

    for(int i=0; i<k; i++)
    {
        result *= B[i];
    }
    printf("\nFactorial of %d is %d\n",n,result);
    return 0;
}