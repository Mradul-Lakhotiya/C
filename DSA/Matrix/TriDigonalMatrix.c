#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n, choice, value, i, j;
    
    printf("Enter the size of the matrix: ");
    scanf("%d", &n);

    int *mat = (int *)calloc(3 * n - 2, sizeof(int));
    if (mat == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    do {
        printf("\nMENU:\n");
        printf("1. Create a diagonal matrix\n");
        printf("2. Set an element\n");
        printf("3. Get an element\n");
        printf("4. Print the matrix\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                for (i = 0; i < n; i++) {
                    printf("Enter value for element (%d, %d): ", i + 1, i + 1);
                    scanf("%d", &value);
                    setElement(mat, i + 1, i + 1, n, value);
                }

                free(mat);
                break;

            case 2:
                printf("Enter the row and column of the element to set: ");
                scanf("%d %d", &i, &j);

                if (i <= 0 || j <= 0 || i > n || j > n) {
                    printf("Invalid row or column.\n");
                    break;
                }

                printf("Enter the value to set: ");
                scanf("%d", &value);

                setElement(mat, i, j, n, value);
                break;

            case 3:
                printf("Enter the row and column of the element to get: ");
                scanf("%d %d", &i, &j);

                if (i <= 0 || j <= 0 || i > n || j > n) {
                    printf("Invalid row or column.\n");
                    break;
                }

                value = getElement(mat, i, j, n);
                printf("Element (%d, %d): %d\n", i, j, value);
                break;

            case 4:
                printf("Matrix:\n");
                printMatrix(mat, n);
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 0);

    free(mat);

    return 0;
}

void setElement(int *mat, int i, int j, int n, int value) {
    if (i - j == -1) {
        mat[i - 1] = value;
    } else if (i - j == 0) {
        mat[n + i - 2] = value;
    } else if (i - j == 1) {
        mat[2 * n + i - 2] = value;
    }
}

int getElement(int *mat, int i, int j, int n) {
    if (i - j == -1) {
        return mat[i - 1];
    } else if (i - j == 0) {
        return mat[n + i - 2];
    } else if (i - j == 1) {
        return mat[2 * n + i - 2];
    } else {
        return 0; 
    }
}
void printMatrix(int *mat, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            printf("   ");
        }
        for (int j = i; j < n; j++) {
            if (abs(i - j) <= 1) {
                printf("%d ", getElement(mat, i + 1, j + 1, n));
            }
        }
        printf("\n");
    }
}
