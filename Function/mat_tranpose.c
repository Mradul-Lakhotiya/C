#include <stdio.h>

#define MAX_ROWS 10
#define MAX_COLS 10

void matrix_reader(int mat[MAX_ROWS][MAX_COLS], int row, int col, int i, int j) {
    if (i == row) {
        return;
    }

    if (j == col) {
        matrix_reader(mat, row, col, i + 1, 0);
        return;
    }

    printf("Enter the number at (%d,%d): ", i + 1, j + 1);
    scanf("%d", &mat[i][j]);

    matrix_reader(mat, row, col, i, j + 1);
}

void matrix_transpose(int mat[MAX_ROWS][MAX_COLS], int t_mat[MAX_ROWS][MAX_COLS], int row, int col, int i, int j) {
    if (i == row) {
        return;
    }

    if (j == col) {
        matrix_transpose(mat, t_mat, row, col, i + 1, 0);
        return;
    }

    t_mat[j][i] = mat[i][j];

    matrix_transpose(mat, t_mat, row, col, i, j + 1);
}

void matrix_printer(int mat[MAX_ROWS][MAX_COLS], int row, int col, int i, int j) {
    if (i == row) {
        return;
    }

    if (j == col) {
        matrix_printer(mat, row, col, i + 1, 0);
        printf("\n");
        return;
    }

    printf("%d ", mat[i][j]);

    matrix_printer(mat, row, col, i, j + 1);
}

int main() {
    int row, col;

    printf("Enter the number of rows: ");
    scanf("%d", &row);

    printf("Enter the number of columns: ");
    scanf("%d", &col);

    if (row > MAX_ROWS || col > MAX_COLS) {
        printf("Matrix size exceeds maximum allowed size (%d x %d)\n", MAX_ROWS, MAX_COLS);
        return 1; // Exit with an error code
    }

    int mat[MAX_ROWS][MAX_COLS];
    int t_mat[MAX_ROWS][MAX_COLS];

    matrix_reader(mat, row, col, 0, 0);

    // Display the entered matrix
    printf("Entered matrix:\n");
    matrix_printer(mat, row, col, 0, 0);

    // Transpose the matrix using recursion
    matrix_transpose(mat, t_mat, row, col, 0, 0);

    // Display the transposed matrix
    printf("Transposed matrix:\n");
    matrix_printer(t_mat, col, row, 0, 0);

    return 0;
}
