#include<stdio.h>
#include<stdlib.h>

    int k=0;

void get_input(int *A,int n)
{
    for(int i=0; i<n; i++)
    {
        printf("Enter #%d Element : ",i+1);
        scanf("%d",&A[i]);
    }
}


void display(int *A,int n)
{
    printf("\nArray Elements : ");
    for(int i=0; i<n; i++)
    {
        printf("%d ",A[i]);
    }
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    returnSize = (int *)malloc(numsSize*sizeof(int));
    int count=0;
    for(int i=0; i<numsSize-1; i++)
    {
        for(int j=i+1; j<numsSize; j++)
        {
            if((nums[i] + nums[j]) == target)
            {
                returnSize[k++] = nums[i];
                returnSize[k++] = nums[j];
                count++;
            }
        }
    }
    returnSize = (int *)malloc((count+1)*sizeof(int));
    return returnSize;
}

int main()
{
    int *A,*return_arr;
    int n;
    int target;

    printf("\nEnter the size of array : ");
    scanf("%d",&n);

    A = (int *)malloc(n*sizeof(int));
    return_arr = (int *)malloc(n*sizeof(int));

    printf("\nEnter target : ");
    scanf("%d",&target);

    get_input(A,n);
    display(A,n);

    return_arr = twoSum(A,n,target,return_arr);

    display(return_arr,k);

    return 0;
}