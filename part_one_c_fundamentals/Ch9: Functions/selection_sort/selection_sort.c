#include <stdio.h>

#define SIZE ((int) sizeof(arr)/sizeof(arr[0]))

void selection_sort(int n, int arr[]);

int main(void) 
{
    int arr[] = {0,234,2,3,1,6,9,8,4,5,10,9};

    printf("Before sorting: ");
    for (int i = 0; i < SIZE; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");

    selection_sort(SIZE, arr);

    printf("After sorting : ");
    for (int i = 0; i < SIZE; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");

    return 0;
}

void selection_sort(int n, int arr[])
{
    if (n <= 0) return;

    int max = arr[0], max_pos = 0;
    for (int i = 0; i < n; i++) {
        if (max < arr[i]) {
            max_pos = i;
            max = arr[i];
        }
    }

    // Swap max and last
    arr[max_pos] = arr[n - 1];
    arr[n - 1] = max;

    selection_sort(n - 1, arr);
}