/*
Author: Mradul Lakhotiya
SAP ID: 500125405
Email: Mradul.125405@stu.upes.ac.in
Batch: Batch-50
Aim: Find sum of all array elements using recursion.
*/

#include <stdio.h>

// Function prototype
int SumOfArray(int arr[], int i, int size, int sum);

int main() {
    int size;

    // Input the size of the array
    printf("Enter the size of array: ");
    scanf("%d", &size);

    int arr[size];

    // Input array elements
    for (int i = 0; i < size; i++) {
        printf("Enter the value of arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    // Print the sum of the array using the SumOfArray function
    printf("The sum of arr will be: %d\n", SumOfArray(arr, 0, size, 0));

    return 0;
}

// Recursive function to calculate the sum of array elements
int SumOfArray(int arr[], int i, int size, int sum) {
    if (i == size) {
        return sum;
    }
    // Recursively call SumOfArray with updated index and sum
    return SumOfArray(arr, i + 1, size, sum + arr[i]);
}
