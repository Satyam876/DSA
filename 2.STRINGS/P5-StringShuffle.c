#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdio.h>

int check_string_shuffle(char *s1,char *s2)
{
    for(int i=0; s1[i] != '\0'; i++)
    {
        int count = 0;
        for(int j=0; s2[j] != '\0'; j++)
        {
            if(s1[i] == s2[j])
                count++;
        }
        if(count > 1)
            return 0;
    }
    return 1;
}


int main()
{
    char *s1 = "XY";
    char *s2 = "Y21XX";

    int result = check_string_shuffle(s1,s2);

    if(result == 0)
        printf("\nString 3 is not a shuffle of String 1 and String 2\n");
    else
        printf("\nString 3 is a shuffle of String 1 and String 2\n");

    return 0;
}