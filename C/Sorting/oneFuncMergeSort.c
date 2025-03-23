#include <stdio.h>

void merge_sort_single(int a[], int l, int r)
{
    if (l >= r)
        return;              // Check if the left index is less than the right index
    int m = l + (r - l) / 2; // Find the middle point

    // Recursively sort first and second halves
    merge_sort_single(a, l, m);     // Sort the first half
    merge_sort_single(a, m + 1, r); // Sort the second half

    // Merge the sorted halves
    int i, j, k;
    int n1 = m - l + 1; // Size of the first half
    int n2 = r - m;     // Size of the second half

    int L[n1], R[n2]; // Temporary arrays to hold the two halves

    for (i = 0; i < n1; i++) // Copy data to temporary array L
        L[i] = a[l + i];
    for (j = 0; j < n2; j++) // Copy data to temporary array R
        R[j] = a[m + 1 + j];

    i = 0; // Initial index of the first subarray
    j = 0; // Initial index of the second subarray
    k = l; // Initial index of the merged subarray
    while (i < n1 && j < n2)
    { // Merge the temporary arrays back into a[]
        if (L[i] <= R[j])
        {                // If the element in L is smaller or equal
            a[k] = L[i]; // Copy the element from L to a
            i++;         // Move to the next element in L
        }
        else
        {                // If the element in R is smaller
            a[k] = R[j]; // Copy the element from R to a
            j++;         // Move to the next element in R
        }
        k++; // Move to the next position in a
    }

    while (i < n1)
    { // Copy the remaining elements of L, if any
        a[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    { // Copy the remaining elements of R, if any
        a[k] = R[j];
        j++;
        k++;
    }
}

int main()
{
    int array[] = {9, 4, 8, 1, 7, 0, 3, 2, 5, 6};
    int length = sizeof(array) / sizeof(array[0]);

    merge_sort_single(array, 0, length - 1);

    for (int i = 0; i < length; i++)
        printf("%d ", array[i]);
    printf("\n");

    return 0;
}