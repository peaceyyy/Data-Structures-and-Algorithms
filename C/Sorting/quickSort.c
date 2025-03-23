#include <stdio.h>


void swap (int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition (int arr[], int start, int end)
{
    int pivot = arr[end]; // Choose the last element as the pivot
    int i = start - 1; // Index of the smaller element
    int j = start; // Index for iterating through the array

    for (; j <= end - 1; j++) // Iterate from start to the element before the pivot
        if (arr[j] < pivot) // If the current element is smaller than the pivot
            swap(&arr[++i], &arr[j]); // Swap the element with the element at i+1 and increment i

    swap(&arr[++i], &arr[end]); // Swap the pivot element with the element at i+1

    return i; // Return the partitioning index
}

void quickSort(int arr[], int start, int end)
{
    if (end <= start) return; // Base case: if the array has one or no elements, it's already sorted

    int pivot = partition(arr, start, end); // Partition the array and get the pivot index

    quickSort(arr, start, pivot - 1); // Recursively sort the elements before the pivot
    quickSort(arr, pivot + 1, end); // Recursively sort the elements after the pivot
}

int main() {
    int array[] = {9, 4, 8, 1, 7, 0, 3, 2, 5, 6};
    int length = sizeof(array) / sizeof(array[0]);

   quickSort(array, 0, length - 1);

    for (int i = 0; i < length; i++)
        printf("%d ", array[i]);
    printf("\n");

    return 0;
}