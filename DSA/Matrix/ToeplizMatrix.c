#include <stdio.h>
#include <stdlib.h>

int getElement(int *mat, int i, int j, int n);
void printMatrix(int *mat, int n);
void setElement(int *mat, int i, int j, int n, int value);

int main() {
    int n, choice, value, i , j;

    printf("Entre the size of the matrix : ");
    scanf("%d", &n);

    int *mat = (int *)calloc(2 * n - 1, sizeof(int));
    if (mat == NULL) {
        printf("MEMORY ALLOCATION FAILED");
        return 1;
    }

    do {
        printf("\n1. Set The value\n\
2. get The value\n\
3. Print The Matrix\n\
0. Exit\n\
Entre The option : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            printf("Exiting The System\n");
            break;

        case 1:
            printf("Entre i, j, value : ");
            scanf("%d %d %d", &i , &j, &value);

            if (i <= 0 || j <= 0 || i > n || j > n) {
                printf("Invalid row or column.\n");
                break;
            }

            setElement(mat, i, j, n ,value);
            break;

        case 2:
            printf("Entre i, j : ");
            scanf("%d %d", &i,&j);

            if (i <= 0 || j <= 0 || i > n || j > n) {
                printf("Invalid row or column.\n");
                break;
            }
            printf("%d is at %d, %d", getElement(mat, i, j, n), i, j);
            break;

        case 3:
            printMatrix(mat, n);
            break;

        default:
            printf("INVALID OPTION");
            break;
        }

    } while (choice != 0);

    free(mat);

    return 0;
}

void setElement(int *mat, int i, int j, int n, int value) {
    if (i >= j) {
        mat[i - j] = value;
    }
    else {
        mat[n + j - i - 1] =  value;
    }
} 

int getElement(int *mat, int i, int j, int n) {
    if (i >= j) {
        return mat[i - j];
    }
    else {
       return mat[n + j - i - 1];
    }
}

void printMatrix(int *mat, int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d ", getElement(mat, i, j, n));
        }
        printf("\n");
    }
}