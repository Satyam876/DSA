#include<stdio.h>

int middle_element(int a,int b,int c)
{
    int mid;

    if(a > b && a > c)
    {
        if(a < c)
            mid = c;
        else
            mid = b;
    }
    else if(b > a && b > c)
    {
        if(a < c)
            mid = c;
        else
            mid = a;
    }
    else
    {
        if(a < b)
            mid = a;
        else
            mid = b;
    }
    return mid;
}


int main()
{
    int A,B,C;
    printf("\nEnter the 3 Numbers : ");
    scanf("%d%d%d",&A,&B,&C);

    printf("\nMiddle Element : %d\n",middle_element(A,B,C));

    return 0;
}