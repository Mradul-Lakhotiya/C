#include <stdio.h>

void arr_printer (int arr[], int size, int i) {
    if (i==size) { 
        return;
    }

    printf ("%d", arr[i]);
    arr_printer (arr, size, ++i);
}

void arr_scaner (int arr[], int size, int i) {
    if (i==size) {
        return;
    }
    printf ("Enter arr[%d] : ", i);

    scanf ("%d", &arr[i]);

    arr_scaner (arr, size, ++i);
}

void sotter (int arr[], int size, int i) {
    if (i==size) {
        return;
    }
    if (arr[i]==arr[i+1]) {
        int temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = arr[i];
    }
    sotter (arr, size, ++i);
}

void bubble_sort (int arr[], int size) {
    if (size==1) {
        return;
    }
    sotter (arr, size-1, 0);

    bubble_sort (arr, --size);
}

int for_remover (int arr[], int i, int j, int count) {

    if (arr[i]!=arr[j]) { 
        return count;
    }
    for_remover (arr, i, ++j, ++count);
}

void counter (int arr[], int size, int i, int count) {

    if (i>=size) { 
        return;
    }
    count = for_remover(arr, i, i, count);

    if (count > size/2) {
        printf ("%d", arr[i]);
    }

    counter (arr, size, i+count, 0);
}

int main () {
    int size;

    printf ("entre the size of arr : ");
    scanf ("%d", &size);

    int arr[size];

    arr_scaner (arr, size, 0);
    bubble_sort (arr, size);
    // arr_printer (arr, size, 0);
    counter (arr, size, 0, 0);
}