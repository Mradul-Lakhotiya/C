/*
Author: Mradul Lakhotiya
SAP ID: 500125405
Email: Mradul.125405@stu.upes.ac.in
Batch: Batch-50
Aim: Merge the contents of 'arr1' and 'arr2' into a new array 'Merge_arr'.
*/
#include <stdio.h>

int main() {
    int size1, size2;

    // Input the size of array '1'
    printf("Enter the size of array '1': ");
    scanf("%d", &size1);

    int arr1[size1];

    // Input elements for array '1'
    for (int i = 0; i < size1; i++) {
        printf("arr1[%d] : ", i);
        scanf("%d", &arr1[i]);
    }

    // Input the size of array '2'
    printf("Enter the size of array '2': ");
    scanf("%d", &size2);

    int arr2[size2];

    // Input elements for array '2'
    for (int i = 0; i < size2; i++) {
        printf("arr2[%d] : ", i);
        scanf("%d", &arr2[i]);
    }

    // Declare the merged array
    int Merge_arr[size1 + size2];

    // Copy elements from arr1 to Merge_arr
    for (int i = 0; i < size1; i++) {
        Merge_arr[i] = arr1[i];
    }

    // Copy elements from arr2 to Merge_arr
    for (int i = 0; i < size2; i++) {
        Merge_arr[i + size1] = arr2[i];
    }

    // Display the merged array
    printf("Merged Array will Be : ");
    for (int i = 0; i < size1 + size2; i++) {
        printf("%d, ", Merge_arr[i]);
    }

    return 0;
}
