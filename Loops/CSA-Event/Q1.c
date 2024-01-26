#include <stdio.h>
#include <limits.h>

// Function to find the second highest number in an array
int findSecondHighest(int array[], int length)
{
    // Initialize variables
    int highest = array[0];
    int secondHighest = INT_MIN;

    // WRITE YOUR CODE HERE
    for (int i = 0; i < length; i++) {
        if (highest < array[i]) {
            highest = array[i];
        }
    }

    for (int i = 0; i < length; i++) {
        if (secondHighest < array[i] && array[i] < highest) {
            secondHighest = array[i];
        }
    }
    // Return the second highest element
    return secondHighest;
}

int main()
{
    // Test Case 1
    int array1[] = {10, 5, 8, 15, 7};
    printf("Test Case 1: %d\n", findSecondHighest(array1, 5));

    // Test Case 2
    int array2[] = {-5, -10, -3, -8};
    printf("Test Case 2: %d\n", findSecondHighest(array2, 4));

    // Test Case 3
    int array3[] = {5, 9, 8, 3};
    printf("Test Case 3: %d\n", findSecondHighest(array3, 4));

    // Test Case 4
    int array4[] = {7, 8};
    printf("Test Case 4: %d\n", findSecondHighest(array4, 2));

    return 0;
}