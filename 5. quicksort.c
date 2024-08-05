#include <stdio.h>
#include <time.h> // Include the time library

void swap(int *a, int *b){
    int t = *a; 
    *a = *b; 
    *b = t;
}

int partition(int arr[], int low, int high){
    int i = low - 1;
    for (int j = low; j < high; j++){
        if (arr[j] < arr[high])
            swap(&arr[++i], &arr[j]);
    }
    swap(&arr[++i], &arr[high]);
    return i;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = 6; // Calculate the size of the array

    clock_t start = clock(); // Record the start time
    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Calculate and print the execution time
    double time_taken = (double)(clock() - start) / CLOCKS_PER_SEC;
    printf("Time taken: %f seconds\n", time_taken);

    return 0;
}
