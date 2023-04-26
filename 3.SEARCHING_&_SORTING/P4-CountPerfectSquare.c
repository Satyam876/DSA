#include<stdio.h>

int count_perfect_numbers(int n)
{
    int count = 0;

    for(int i=1; i<n; i++)
    {
        if(i*i < n)
            count++;
    }
    return count;
}

int main()
{
    int n;
    printf("\nEnter the Number : ");
    scanf("%d",&n);

    printf("\nTotal Perfect Square Numbers : %d\n",count_perfect_numbers(n));

    return 0;
}