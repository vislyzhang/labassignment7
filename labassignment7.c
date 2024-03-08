#include <stdio.h>

void bubbleSort(int arr[], int n, int swaps[]) {
    int i, j, temp, total_swaps = 0;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swaps[arr[j+1]]++;
                total_swaps++;
            }
        }
    }
    printf("Total number of swaps in Bubble Sort: %d\n", total_swaps);
}

void selectionSort(int arr[], int n, int swaps[]) {
    int i, j, min_index, temp, total_swaps = 0;
    for (i = 0; i < n-1; i++) {
        min_index = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
            swaps[arr[i]]++;
            total_swaps++;
        }
    }
    printf("Total number of swaps in Selection Sort: %d\n", total_swaps);
}

void printSwaps(int arr[], int n, int swaps[]) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d: # of times %d is swapped\n", arr[i], swaps[arr[i]]);
    }
}

int main() {
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n1 = sizeof(array1) / sizeof(array1[0]);
    int n2 = sizeof(array2) / sizeof(array2[0]);
    int swaps1[101] = {0}; // Assuming the maximum value in the array is 100
    int swaps2[101] = {0};

    printf("array1:\n");
    bubbleSort(array1, n1, swaps1);
    printSwaps(array1, n1, swaps1);

    printf("\narray2:\n");
    selectionSort(array2, n2, swaps2);
    printSwaps(array2, n2, swaps2);

    return 0;
}
