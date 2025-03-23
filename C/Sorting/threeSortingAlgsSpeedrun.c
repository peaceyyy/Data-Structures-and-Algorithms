















#include <stdio.h>

void swap (int* a, int* b){


    int temp = *a;
    *a = *b;
    *b = temp;
}


void bubbleSort (int* arr, int size){

    for (int i = 0; i < size - 1; i ++)

    {

        for (int j= 0; j< size - 1; j ++)
        {
            if (arr[j] > arr [j + 1]) swap (&arr[j], &arr [j + 1]);
        }
    }
}


void insertionSort (int* arr, int size)
{

    for (int i = 1; i < size; i++)
    {


        int key = arr[i], j = i - 1;

        while (j >= 0 && arr[j] > key){
        arr[j + 1] = arr[j];
        j--;
    }
    
    arr[j + 1] = key;
} 

}

void selectionSort (int* arr, int size)
{

    for (int i = 0; i < size; i++)
    {
        int minPosIndex = i;

        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minPosIndex]) minPosIndex = j;
        }

        if (i != minPosIndex) swap (&arr[i], &arr[minPosIndex]);
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

    selectionSort(arr, size);

    printf("Sorted array: \n");
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");



    return 0;
}