/*
Author: Mradul Lakhotiya
SAP ID: 500125405
Email: Mradul.125405@stu.upes.ac.in
Batch: Batch-50
Aim: Copy all elements of 'arr' into another array 'CopyOfarr' using pointers.
Display the contents of both the arrays using pointers.
*/
#include <stdio.h>

int main() {
    int size;

    // Input the size of the array
    printf("Enter the size of array : ");
    scanf("%d", &size);

    // Declare arrays
    int arr[size], CopyOfarr[size];

    // Input elements for the 'arr' array
    for (int i = 0; i < size; i++) {
        printf("Enter the element in arr[%d] : ", i);
        scanf("%d", &arr[i]);
    }

    // Pointers to arrays
    int* prt_arr = arr;
    int* prt_CopyOfarr = CopyOfarr;

    // Copy elements from 'arr' to 'CopyOfarr' using pointers
    for (int i = 0; i < size; i++) {
        *(prt_CopyOfarr + i) = *(prt_arr + i);
    }

    // Display the elements of the initial 'arr'
    printf("The Elements of initial arr : ");
    for (int i = 0; i < size; i++) {
        printf("%d, ", arr[i]);
    }

    // Display the elements of the copied 'CopyOfarr'
    printf("\nThe Elements of copied arr : ");
    for (int i = 0; i < size; i++) {
        printf("%d, ", CopyOfarr[i]);
    }

    return 0;
}
