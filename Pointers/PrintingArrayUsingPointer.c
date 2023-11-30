// Write a C program to input and print array elements using a pointer.

#include <stdio.h>

int main () {
    int size;

    printf ("Enter the size of array : ");
    scanf ("%d", &size);

    int arr[size];
    int *prt = arr;

    for (int i = 0; i < size; i++) {
        scanf ("%d", prt + i);
    }

    for (int i = 0; i < size; i++) {
        printf ("%d, ", *(prt+i));
    }

    return 0;
}