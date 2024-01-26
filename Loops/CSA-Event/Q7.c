#include <stdio.h>

// Find the Missing Number
// Given an array containing n distinct numbers taken from 0, 1, 2, ..., n
// find the one that is missing from the array.

int findMissingNumber(int *nums, int size)
{
    // Write your code here
    int j = 0; 

    for (int i = 0; i < size; i++, j++) {
        if (nums[i] != j) {
            return j;
        }
    }
    
    return (size);

}

int main()
{
    // Test Case 1
    int nums1[] = {0, 1, 3};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    printf("Test Case 1: %d\n", findMissingNumber(nums1, size1));

    // Test Case 2
    int nums2[] = {1, 2, 3};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    printf("Test Case 2: %d\n", findMissingNumber(nums2, size2));

    // Test Case 3
    int nums3[] = {0, 1, 2};
    int size3 = sizeof(nums3) / sizeof(nums3[0]);
    printf("Test Case 3: %d\n", findMissingNumber(nums3, size3));

    // Test Case 4
    int nums4[] = {0, 1, 2, 3};
    int size4 = sizeof(nums4) / sizeof(nums4[0]);
    printf("Test Case 4: %d\n", findMissingNumber(nums4, size4));

    // Test Case 5
    int nums5[] = {1, 2, 3, 4};
    int size5 = sizeof(nums5) / sizeof(nums5[0]);
    printf("Test Case 5: %d\n", findMissingNumber(nums5, size5));

    return 0;
}