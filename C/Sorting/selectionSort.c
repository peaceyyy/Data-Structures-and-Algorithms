#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int arr[], int size)
{

    for (int i = 0; i < size - 1; i++)
    {

        int minPos = i;

        for (int j = i + 1; j < size; j++)
        {

            if (arr[j] < arr[minPos])
                minPos = j;
        }
        if (minPos != i)
            swap(&arr[i], &arr[minPos]);
    }
}

int main()
{

    int arr[5] = {12, 11, 13, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    selectionSort(arr, size);

    printf("Sorted array: \n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}