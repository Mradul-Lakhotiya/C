#include <stdio.h>

int main() {
    int r[2], c[2];

    // Define matrices
    float mat[2][100][100];  // Assuming a maximum size of 100x100 for each matrix

    // Scanning the dimensions and elements of the matrices
    for (int i = 0; i < 2; i++) {
        int di = i + 1;

        printf("Enter the Rows of the %d matrix: ", di);
        scanf("%d", &r[i]);
        printf("Enter the Cols of the %d matrix: ", di);
        scanf("%d", &c[i]);

        printf("Enter the values for %d matrix:\n", di);

        for (int j = 0; j < r[i]; j++) {
            for (int k = 0; k < c[i]; k++) {
                int dj = j + 1, dk = k + 1;
                printf("Enter the value of (%d,%d) position: ", dj, dk);
                scanf("%f", &mat[i][j][k]);
            }
        }
    }

    // Check if the matrices can be multiplied
    if (c[0] != r[1]) {
        printf("Matrix multiplication not possible. Invalid dimensions.\n");
        return 0;
    }

    float matimat[100][100]; // Resultant matrix, assuming a maximum size of 100x100

    // Perform matrix multiplication
    for (int i = 0; i < r[0]; i++) {
        for (int j = 0; j < c[1]; j++) {
            matimat[i][j] = 0;
            for (int k = 0; k < c[0]; k++) {
                matimat[i][j] += mat[0][i][k] * mat[1][k][j];
            }
        }
    }

    // Display the resultant matrix
    printf("Resultant matrix after multiplication:\n");
    for (int i = 0; i < r[0]; i++) {
        for (int j = 0; j < c[1]; j++) {
            printf("%.2f ", matimat[i][j]);
        }
        printf("\n");
    }

    return 0;
}
