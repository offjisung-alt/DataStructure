#include <stdio.h>


void swap(int arr[], int a, int b)
{
    int temp;

    temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

void SelSort(int arr[], int n)
{
    int i, j;
    int idx;
    int min;

    for(i=0; i<n-1; i++)
    {
        idx = i;
        min = arr[i];

        for(j=i+1; j<n;j++)
        {
            if(arr[j]<min)
            {
                idx = j;
                min = arr[idx];
            }
        }
        swap(arr, i, idx);
    }

}

int main(void)
{
    int arr[4] = {3,4,2,1};
    int i;
    
    SelSort(arr, sizeof(arr)/sizeof(int));
    for(i=0; i<4; i++)
        printf("%d ", arr[i]);

    printf("\n");
    return 0;
}