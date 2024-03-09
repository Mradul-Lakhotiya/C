#include <stdio.h>
#include <stdlib.h>

void rearrange(int[], int);
void deleteHeap(int[], int);
void createHeap();
void heapSort(int[], int);
void heapify(int[], int);

int main() {
    createHeap();
    return 0;
}

void rearrange(int arr[], int n) {
    int i = n, temp;
    temp = arr[n];
    while (i > 1 && temp > arr[i/2]) {
        arr[i] = arr[i/2];
        i /= 2;
    }
    arr[i] = temp;
}

void createHeap() {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    for (int i = 2; i < (sizeof(arr)/sizeof(arr[0])); i++) {
        rearrange(arr, i);
    }

    for (int i = 1; i < (sizeof(arr)/sizeof(arr[0])); i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");

    int arr2[] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    heapify(arr2, (sizeof(arr)/sizeof(arr[0])));

    for (int i = 1; i < (sizeof(arr)/sizeof(arr[0])); i++) {
        printf("%d, ", arr[i]);
    }
    printf("\n");
    heapSort(arr, (sizeof(arr)/sizeof(arr[0])) - 1);

    for (int i = 1; i < (sizeof(arr)/sizeof(arr[0])); i++) {
        printf("%d, ", arr[i]);
    }
}

void deleteHeap(int arr[], int n) {
    if (n <= 1) {
        return;
    }
    int largest = arr[1];
    arr[1] = arr[n];

    int i = 1; 
    int j = 2*i;
    while(j <= n) {

        if (arr[j+1] > arr[j]) {
            j += 1;
        }

        if (arr[i] < arr[j]) {
            // swap
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            i = j;
            j *= 2;
        }
        else {
            break;
        }

    }
    arr[n] = largest;
}

void heapSort(int arr[], int size) {
    for (int i = size; i > 1; i--) {
        int temp = arr[1];
        arr[1] = arr[i];
        arr[i] = temp;

        deleteHeap(arr, i - 1);
    }
}


void heapify(int arr[], int size) {
    for (int i = (size)/2 - 1; i >= 0; i++) {
        int j = 2 * i + 1; // left child
        
        while(j <= size) {
            if (arr[j] < arr[j+1]) {
                j += 1;
            }

            if (arr[i] < arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = arr[i];

                i = j;
                j = 2 * i + 1;
            }
            else {
                break;
            }
        }
    }
}