// Question 3
// Program to Search array in O(logn) complexity.

#include <stdio.h>

// Function to perform binary search on a sorted array
int search(int arr[], int size, int target)
{
    int start = 0;
    int end = size - 1;

    while (start <= end)
    {
        // Write Your Code Here
        int mid = (start + end)/2;

        if (arr[mid] == target) {
            return mid;
        }
        else if (arr[mid] > target)
        {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }   
    }

    return -1;
}

int main()
{

    int array1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Test Case 1
    int target1 = 5;
    printf("Test Case 1: %d\n", search(array1, sizeof(array1) / sizeof(array1[0]), target1));

    // Test Case 2
    int array2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target2 = 1;
    printf("Test Case 2: %d\n", search(array2, sizeof(array2) / sizeof(array2[0]), target2));

    // Test Case 3
    int array3[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target3 = 10;
    printf("Test Case 3: %d\n", search(array3, sizeof(array3) / sizeof(array3[0]), target3));

    // Test Case 4
    int array4[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int target4 = 15;
    printf("Test Case 4: %d\n", search(array4, sizeof(array4) / sizeof(array4[0]), target4));

    // Test Case 5
    int array5[] = {};
    int target5 = 5;
    printf("Test Case 5: %d\n", search(array5, sizeof(array5) / sizeof(array5[0]), target5));

    return 0;
}