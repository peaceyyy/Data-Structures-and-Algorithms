#include <stdio.h>

void insertionSort(int arr[], int size){

    for (int i = 1; i < size; i++){
        
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr [j + 1] = key;

    }
}

int main(){

    int arr[5] = {12, 11, 13, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Unsorted array: \n");
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    insertionSort(arr, size);

    printf("Sorted array: \n");
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");



    return 0;
}