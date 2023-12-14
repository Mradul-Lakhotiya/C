#include <stdio.h>
#include <stdlib.h>

int main() {
    int row[2], col[2];
    float ***matrix;
    float **multimatrix;
    
    matrix = (float ***)malloc(2 * (sizeof(float **)));

    for (int i = 0; i < 2; i++) {

        printf ("--------------------------------------------\n");
        printf ("Enter the specification for matrix[%d]\n", i+1);

        printf ("Enter the number of rows[%d] : ", i+1);
        scanf ("%d", &row[i]);
        printf ("Enter the number of cols[%d] : ", i+1);
        scanf ("%d", &col[i]);

        matrix[i] = (float **)malloc(row[i] * (sizeof(float *)));
        for (int j = 0; j < row[i]; j++) {
            matrix[i][j] = (float *)malloc(col[i] * (sizeof(float)));
        }

        printf ("Enter the value of matrix[%d]\n", i+1);

        for (int j = 0; j < row[i]; j++) {
            for (int k = 0; k < col[i]; k++) {
                printf ("(%d, %d) : ", j+1, k+1);
                scanf ("%f", &matrix[i][j][k]);
            }
        }
    }
    if (col[0] != row[1]) {
        printf ("col of one is not equal to other row\n");
        return 0;
    }

    multimatrix = (float **)malloc(row[0] * (sizeof(float *)));
    for (int i = 0; i < row[0]; i++) {
        multimatrix[i] = (float *)malloc(col[1] * (sizeof(float)));
    }

    for (int i = 0; i < row[0]; i++) {
        for (int j = 0; j < col[1]; j++) {
            multimatrix[i][j] = 0;
            for (int k = 0; k < col[0]; k++) {
                multimatrix[i][j] += matrix[0][i][k] * matrix[1][k][j];
            }
        }
    }

    for (int i = 0; i < row[0]; i++) {
        for (int j = 0; j < col[0]; j++) {
            printf ("%.1f ", multimatrix[i][j]);
        }
        printf ("\n");
    }

    for (int i = 0; i < 2; i++) {
        for(int j = 0; j < row[i]; j++) {
            free(matrix[i][j]);
        }
        free(matrix[i]);
    }
    free(matrix);

    for (int i = 0; i < row[0]; i++) {
        free(multimatrix[i]);
    }
    free(multimatrix);

    return 0;
}