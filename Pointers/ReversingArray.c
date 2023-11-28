#include <stdio.h>

void sawp (int *prt1, int *prt2) {
    *prt1 = *prt1 ^ *prt2;
    *prt2 = *prt1 ^ *prt2;
    *prt1 = *prt1 ^ *prt2;
}

int main () {
    int size;

    printf ("Enter the size of arr : ");
    scanf ("%d", &size);

    int* arr = (int*)malloc(size*sizeof(int));

    for (int i = 0; i < size; i++) {
        printf ("arr[%d] : ", i);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < size/2; i++) {
        sawp(&arr[i], &arr[size-1-i]);
        // arr[i] = arr[i] ^ arr[size-1-i];
        // arr[size-1-i] = arr[i] ^ arr[size-1-i];
        // arr[i] = arr[size-1-i] ^ arr[i];
    }

    for (int i = 0; i < size; i++) {
        printf ("%d, ", arr[i]);
    }
}