#include <stdio.h>

void swap (int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort (int* arr, int size){

    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - 1; j++)

        if (arr[j] > arr[j + 1]) swap(&arr[j], &arr[j + 1]);

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

    bubbleSort(arr, size);

    printf("Sorted array: \n");
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");



    return 0;
}