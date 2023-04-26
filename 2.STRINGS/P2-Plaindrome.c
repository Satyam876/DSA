#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void swap(char *a,char *b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

char * reverse_string(char *S,int size)
{
    int i=0;
    int j = size-1;

    while(i < j)
    {
        swap(&S[i],&S[j]);
        i++;
        j--;
    }
    return S;
}

int check_palindrome(char *str1,char *str2)
{
    int i=0;
    int count=0;

    while(str1[i] != '\0' && str2[i] != '\0')
    {
        if(str2[i] != str1[i])
            count++;
        i++;
    }
    if(count != 0)
        return 0;
    else
        return 1;
}

int main()
{
    int size;
    char *org_str;
    char *stored_str;
    char *rev_str;

    printf("\nEnter the String Size : ");
    scanf("%d",&size);

    printf("\nEnter the String : ");
    scanf("%s",org_str);

    stored_str = org_str;

    rev_str = reverse_string(org_str,size);

    int result = check_palindrome(stored_str,rev_str);

    if(result == 1)
        printf("\n\nString is Palindrome\n");
    else
        printf("\n\nString is Not Palindrome\n");

    return 0;
}