#include <stdio.h>

// Function to print array elements recursively
void arr_printer(int start, int end, int arr[]) {
    if (start == end) {
        return;
    }
    printf("%d, ", arr[start]);
    arr_printer(start + 1, end, arr);
}

// Recursive function to remove an element at a specific index
void index_remover(int size, int remove_index, int arr[]) {
    if (remove_index == size) {
        return;
    }
    arr[remove_index] = arr[remove_index + 1];
    index_remover(size, remove_index + 1, arr);
}

// Function to remove an element via index
void via_index(int size, int remove_index, int arr[]) {
    index_remover(size, remove_index, arr);

    printf("\nThe new array will be:\n");
    arr_printer(0, size - 1, arr);
}

// Function to remove all occurrences of a given number
void via_a_give_number(int size, int remove_number, int arr[]) {
    int count = 0;

    for (int i = (size - 1); i >= 0; i--) {
        if (arr[i] == remove_number) {
            count++;
            index_remover(size, i, arr);
        }
    }

    printf("\nThe new array will be:\n");
    arr_printer(0, size - count, arr);
}

int main() {
    int size, option, to_remove;

    // Input array size
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    int arr[size];

    // Input array elements
    for (int i = 0; i < size; i++) {
        printf("Enter arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    // Select removal option
    printf("Enter how you want to remove:\n1. Via index\n2. Via a given number\nYour choice: ");
    scanf("%d", &option);

    switch (option) {
        case 1:
            printf("Enter which index you want to remove: ");
            scanf(" %d", &to_remove);
            via_index(size, to_remove, arr);
            break;

        case 2:
            printf("Enter the number you want to remove: ");
            scanf(" %d", &to_remove);
            via_a_give_number(size, to_remove, arr);
            break;

        default:
            printf("Enter a valid value ");
            break;
    }

    return 0;
}
