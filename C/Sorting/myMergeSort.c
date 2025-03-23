#include <stdio.h>

void mergeAndSort(int arr[], int start, int middle, int end)
{
    int leftSubArrLen = middle - start + 1, rightSubArrLen = end - middle;
    int leftSubArr[leftSubArrLen], rightSubArr[rightSubArrLen];

    for (int i = 0; i < leftSubArrLen; i++)
    {
        leftSubArr[i] = arr[start + i];
    }

    for (int j = 0; j < rightSubArrLen; j++)
    {
        rightSubArr[j] = arr[middle + j + 1];
    }

    for (int i = 0, j = 0, k = start; k <= end; k++)
    {
        if (i < leftSubArrLen && (j >= rightSubArrLen || leftSubArr[i] <= rightSubArr[j])) 
        {
            arr[k] = leftSubArr[i++];
        }
        else
        {
            arr[k] = rightSubArr[j++];
        }
    }
}

void mergeSort(int arr[], int start, int end)
{
    if (start < end) 
    {
        int middle = start + (end - start) / 2;

        mergeSort(arr, start, middle);
        mergeSort(arr, middle + 1, end);

        mergeAndSort(arr, start, middle, end);
    }
}

int main()
{
  // test array and length
  int array[] = { 9, 4, 8, 1, 7, 0, 3, 2, 5, 6};
  int length = 10;
  
  // sort the array using merge sort
  mergeSort(array, 0, length - 1);
  
  // print out the array elements to verify they have been sorted
  for (int i = 0; i < length; i++)
    printf("%d ", array[i]);
  printf("\n");
  
  return 0;
}
