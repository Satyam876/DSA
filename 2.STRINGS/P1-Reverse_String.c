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

void reverseString(char* s, int sSize){
    int i=0;
    int j=sSize-1;

    while(i < j)
    {
        swap(&s[i],&s[j]);
        i++;
        j--;
    }
}

int main()
{
    char *str;
    int n;
    printf("\nEnter the String Size : ");
    scanf("%d",&n);

    printf("\nEnter the String : ");
    scanf("%s",str);

    reverseString(str,n);

    printf("\nReversed String : %s",str);

    return 0;
}   