#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// void count_duplicate(char *str,int n)
// {
//     for(int i=0; i<n; i++)
//     {
//         int count = 0;
//         for(int j=i+1; j<n; j++)
//         {
//             if(str[j] == str[i] && str[j] != '0' && str[i] != '0')
//             {
//                 count++;
//                 str[j] = '0';
//             }
//         }
//         // if(count > 0)
//             printf("\n%c : %d\n",str[i],count+1);
//     }
// }


void duplicate(char *S,int n)
{
    int count=0;
    int B[256];

    for(int i=0; i<256; i++)
    {
        B[i] = 0;
    }

    for(int i=0; i<n; i++)
    {
        B[S[i]]++;
    }

    for(int i=0; i<256; i++)
    {
        if(B[i] > 0)
        {
            // printf("\n%c : %d\n",i,B[i]);
            printf("Index %d , Count = %d ",i,B[i]);
        }
    }
}

int main()
{
    int n;
    char *str;
    printf("\nEnter the Length of String : ");
    scanf("%d",&n);
    printf("\nEnter the String : ");
    scanf("%d",str);

    duplicate(str,n);

    return 0;
}