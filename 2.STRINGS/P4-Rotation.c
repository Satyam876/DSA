#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int check_rotation(char *s1,char *s2,int n)
{
    int k;

    for(int i=0; s1[i] != '\0'; i++)
    {
        if(s1[i] == s2[0])
        {
            k = i;
        }
    }
    int i=0, count = 0;

    while(s1[i] !=- '\0' && count < n)
    {
        if(s1[k] != s2[i])
            return 0;
        count++;
        i++;
        k = (k+1)%n;
    }
    return 1;
}

int main()
{
    // char *s1,*s2;

    // printf("\nEnter First String : ");
    // scanf("%s",s1);
    // printf("\nEnter Second String : ");
    // scanf("%s",s2);

    char *s1 = "ABCD";
    char *s2 = "ACBD";
    int n = 4;

    int result = check_rotation(s1,s2,n);

    if(result == 1)
        printf("\nIt is a Rotated String\n");
    else
        printf("\nNot Rotated String\n");
}