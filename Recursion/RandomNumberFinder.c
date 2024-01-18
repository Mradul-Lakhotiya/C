// The provided code implements merge sort and binary search on a dynamically allocated array.

#include <stdio.h>
#include <stdlib.h>

void merge(int* arr, int start, int mid, int end);
void mergeSort(int* arr, int start, int end);
int binarySearch(int* arr, int key, int left, int rigth);

int main() {
    int size;

    printf("Enter the size of arr : ");
    scanf("%d", &size);

    int* arr = (int *)(malloc(sizeof(int) * size));

    if (arr == NULL) {
        printf("\nlol");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 100;
    }

    mergeSort(arr, 0, size - 1);

    for (int i = 0; i < size; i++) {
        printf("%d, ", arr[i]);
    }

    int key = rand() % 100;

    int ans = binarySearch(arr, key, 0, size - 1);

    if (ans == -1) {
        printf("\nThe %d is not ther is the arr", key);
    }
    else {
        printf("\n%d is there in the arr", key);
    }

    free(arr);

    return 0;
}

void merge(int* arr, int start, int mid, int end) {
    int i = start;
    int j = mid + 1;
    int k = 0;
    int* temp = (int *)(malloc(sizeof(int) * (end - start + 1)));

    while (i <= mid && j <= end) {
        if (arr[i] > arr[j]) {
            temp[k++] = arr[j++];
        }
        else {
            temp[k++] = arr[i++];
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= end) {
        temp[k++] = arr[j++];
    }

    for (k = 0, i = start; k < (end - start + 1); i++, k++) {
        arr[i] = temp[k];
    }

    free(temp);
}

void mergeSort(int* arr, int start, int end) {
    if (start < end) {
        int mid = start + (end - start) / 2;

        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);

        merge(arr, start, mid, end);
    }
}

int binarySearch(int* arr, int key, int left, int rigth) {
    int mid = rigth + (left - rigth)/2;

    if (left > rigth) {
        return -1;
    } 

    if (arr[mid] == key) {
        return mid;
    }
    else if (arr[mid] > key) {
        return binarySearch(arr, key, left, mid - 1);
    }
    else {
        return binarySearch(arr, key, mid + 1, rigth);
    }
}

