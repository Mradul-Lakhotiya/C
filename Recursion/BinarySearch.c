#include <stdio.h>

int binarySearch (int* arr, int size, int key) {

    int left = 0;
    int right = size - 1;

    while(left <= right) {
        int mid = left + (right - left)/2;
        
        if (arr[mid] == key) {
            return mid;
        }
        else if (arr[mid] > key) {
            right = mid -1;
        }
        else {
            left = mid + 1;
        }
    }

    return -1;
}

int binarySearchRecursion (int* arr, int key, int left, int right) {

    int mid = left + (right - left)/2;
    

    if (left > right) {
        return -1;
    }

    if (arr[mid] == key) {
        return mid;
    }
    else if (arr[mid] > key) {
        return binarySearchRecursion(arr, key, left, mid - 1);
    }
    else {
        return binarySearchRecursion(arr, key, mid + 1, right);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("%d\n", binarySearch(arr, size, 3));
    printf("%d", binarySearchRecursion(arr, 3, 0, size - 1));

    return 0;
}