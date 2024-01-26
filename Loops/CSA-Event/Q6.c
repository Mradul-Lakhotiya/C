#include <stdio.h>

// Find the Duplicate Number.
// Given an array of integers nums containing n + 1 integers where each integer
// is in the range [1, n] inclusive.

int findDuplicate(int arr[], int length)
{

    // Write your code here
    for (int i = 0; i < length; i++) {
        for(int j = i+1; j < length; j++) {
            if (arr[i] == arr[j]) {
                return arr[j];
            }
        }
    }

    return -1; // No duplicate found
}

int main()
{
    // Test Case 1
    int arr1[] = {1, 3, 4, 2, 2};
    printf("Test Case 1: %d\n", findDuplicate(arr1, sizeof(arr1) / sizeof(arr1[0])));

    // Test Case 2
    int arr2[] = {3, 1, 3, 4, 2};
    printf("Test Case 2: %d\n", findDuplicate(arr2, sizeof(arr2) / sizeof(arr2[0])));

    // Test Case 3
    int arr3[] = {1, 1};
    printf("Test Case 3: %d\n", findDuplicate(arr3, sizeof(arr3) / sizeof(arr3[0])));

    // Test Case 4
    int arr4[] = {1};
    printf("Test Case 4: %d\n", findDuplicate(arr4, sizeof(arr4) / sizeof(arr4[0])));

    return 0;
}