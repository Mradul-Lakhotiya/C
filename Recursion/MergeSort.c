#include <stdio.h>
#include <stdlib.h>

void arrayprinter (int *arr, int size, int i);
void mergesort (int *arr, int start, int end);
void merge (int *arr, int start, int mid, int end);

int main () {
    int size;

    printf ("Enter the Size of array : ");
    scanf ("%d", &size);

    int *arr = (int *)malloc(sizeof(int) * size);

    for (int i =0 ; i < size; i++) {
        printf ("arr[%d] : ", i);
        scanf ("%d", (arr + i));
    }

    printf ("\nThe given arr is : ");
    arrayprinter (arr, size, 0);

    mergesort(arr, 0, size - 1);

    printf ("\nThe sorted arr is : ");
    arrayprinter (arr, size, 0);

    free(arr);

    return 0;
}

void arrayprinter (int *arr, int size, int i) {
    if (i == size) {
        return;
    }

    printf("%d, ", *(arr + i));
    arrayprinter (arr, size, i + 1);    
}

void mergesort (int *arr, int start, int end) {
    int mid = start + (end - start)/2;

    if (start >= end) {
        return;
    }

    mergesort(arr, start, mid);
    mergesort(arr, mid + 1, end);

    merge(arr, start, mid, end);
}

void merge (int *arr, int start, int mid, int end) {
    int *temp = (int *)malloc(sizeof(int) * (end - start + 1));
    int i = start;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= end) {
        if (*(arr + i) > *(arr + j)) {
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

    return;
}