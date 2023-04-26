#include<stdio.h>
#include<stdlib.h>

void longest_palindrome_substring(char *str,int n)
{
    char s2[100];
    int x =0;
    int index=0;
    int count1 = 0,count2 = 0;

    for(int i=0; i<n-1; i++)
    {
        int k=i,j=n-1;

        while(k<n && j>=i)
        {
            if(str[k] != str[j])
            {
                count1++;
            }
            else
            {
                count2++;
                index = i;
            }
            k++;
            j--;
        }
    }
    
    printf("\nLongest Plaindrome SubString : ");
    printf("%d",index);
    if(count1 < n/2 && count2 > n/2)
    {
        for(int i=index; i<n; i++)
        {
            printf("%c ",str[i]);
        }
    }
    else if(count1 == 0 && count2 > n/2)
    {
        printf("%c ",str[0]);
    }
}




int main()
{
    char *str = "aaabbaa";
    int n = 8;
    
    longest_palindrome_substring(str,n);

    return 0;
}