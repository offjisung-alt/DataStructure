#include <stdio.h>


int BSearchRecur(int arr[], int first, int last, int target)
{
    if (first > last)
        return -1;
    
    int mid;
    mid = (first + last) / 2;

    if(arr[mid]==target)
    {
        return mid;
    }
    else if (arr[mid] > target)
        return BSearchRecur(arr, first, mid-1, target);
    else
        return BSearchRecur(arr,mid+1, last, target);
}




int main(void)
{
    int arr[] = {3, 5, 7, 9, 11};
    int idx;

    
    idx = BSearchRecur(arr, 0, sizeof(arr)/sizeof(int) -1, 9);
    if (idx == -1)
        printf("탐색 실패\n");
    else
        printf("타겟 인덱스: %d\n", idx);

    idx = BSearchRecur(arr, 0, sizeof(arr)/sizeof(int) -1, 8);
    if (idx == -1)
        printf("탐색 실패\n");
    else
        printf("타겟 인덱스: %d\n", idx);
    
    
}