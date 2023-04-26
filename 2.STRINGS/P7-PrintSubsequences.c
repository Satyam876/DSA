#include<stdio.h>
#include<stdlib.h>

void print_all_subsequences(char *str,int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
                for(int m=i; m<=j; m++)
                {
                    printf("%c\t",str[m]);
                }
        }
    }
}

int main()
{
    char *str = "abc";
    int n = 3;

    print_all_subsequences(str,n);

    return 0;
}