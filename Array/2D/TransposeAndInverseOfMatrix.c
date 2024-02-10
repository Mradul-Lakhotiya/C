/*
Author: Mradul Lakhotiya
SAP ID: 500125405
Email:  Mradul.125405@stu.upes.ac.in
Batch:  Batch-50
Aim:    Find the Transpose and Inverse of a matrix.
*/
#include <stdio.h>

// Function prototypes
void mat_printer(int n, double mat[n][2 * n], int i, int j);
void mat_transpose(int n, double mat[n][2 * n], double tran_mat[n][2*n]);
void mat_invers(int n, double mat[n][2 * n]);

int main() {
    int n;

    // Input the size of the matrix
    printf("Enter a matrix for which determinant is not zero\n");
    printf("Enter the size of mat : ");
    scanf("%d", &n);

    double mat[n][2 * n], tran_mat[n][n];

    // Input elements of the matrix and create an augmented matrix with an identity matrix on the right
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Enter (%d, %d) : ", i + 1, j + 1);
            scanf("%lf", &mat[i][j]);
        }
        for (int j = n; j < 2 * n; j++) {
            // Create an identity matrix on the right side of the input matrix
            mat[i][j] = (i == (j - n)) ? 1 : 0;
        }
    }

    // Print the original matrix
    printf("Given matrix : \n");
    mat_printer(n, mat, 0, 0);

    // Print the transpose matrix
    printf("Transpose Matrix : \n");
    mat_transpose(n, mat, tran_mat);
    mat_printer(n, tran_mat, 0, 0);

    // Find the inverse of the matrix using Gauss-Jordan elimination
    printf("Inverse Matrix : \n");
    mat_invers(n, mat);

    // Print the inverse matrix
    for (int i = 0; i < n; i++) {
        for (int j = n; j < 2 * n; j++) {
            printf("%.2lf ", mat[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// Function to print a matrix
void mat_printer(int n, double mat[n][2 * n], int i, int j) {
    if (i == n) {
        return;
    } else if (j == n) {
        printf("\n");
        mat_printer(n, mat, i + 1, 0);
    } else {
        printf("%.2lf ", mat[i][j]);
        mat_printer(n, mat, i, j + 1);
    }
}

// Function to transpose a matrix
void mat_transpose(int n, double mat[n][2 * n], double tran_mat[n][2*n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tran_mat[i][j] = mat[j][i];
        }
    }
}

// Function to find the inverse of a matrix using Gauss-Jordan elimination
void mat_invers(int n, double mat[n][2 * n]) {
    for (int i = 0; i < n; i++) {
        double pivot = mat[i][i];

        // Normalize the current row
        for (int j = 0; j < 2 * n; j++) {
            mat[i][j] /= pivot;
        }

        // Eliminate other rows
        for (int k = 0; k < n; k++) {
            if (k != i) {
                double ratio = mat[k][i];
                for (int j = 0; j < 2 * n; j++) {
                    mat[k][j] -= ratio * mat[i][j];
                }
            }
        }
    }
}
