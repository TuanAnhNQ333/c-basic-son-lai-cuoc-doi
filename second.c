// tim so lon thu 2
#include<stdio.h>
#include<limits.h>
int solution(int arr[], int length)
{
    int max = INT_MIN;
    int second = INT_MIN;
    for(int i = 0; i < length; i ++)
    {
        if(arr[i] > max)
        {
            second = max;
            max = arr[i];
        }
        else if((arr[i] >= second) && (arr[i] < max))
        {
            second = arr[i];
        }
    }
    if(second == INT_MIN)
    {
        printf("Khong tim duoc\n");
        return -1;
    }
    return second;
}
int main()
{
    int length;
    scanf("%d", &length);
    int arr[length];
    for(int i = 0; i < length; i ++)
    {
        scanf("%d", &arr[i]);
        
    }
    int result = solution(arr, length);
    if(result != -1)
    {
        printf("%d", result);
    }
    return 0;
}



