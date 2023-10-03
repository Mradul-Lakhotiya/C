#include <stdio.h>

int main () {
    int row, col, n;

    printf ("Enter the noumber of rows : ");
    scanf ("%d",&row);

    printf ("Enter the number of cols : ");
    scanf ("%d",&col);

    printf ("Enter the number of Matrix'es to add : ");
    scanf ("%d",&n);

    int mat[row][col][n];
    int summat[row][col][1];

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            summat[i][j][0] = 0;
        }
    }

    for (int i=0; i<n; i++) {
        int di = i+1;
        printf ("Enter the Value for %d Matrix\n",di);
        for (int j=0; j<row; j++) {
            for (int k=0; k<col; k++) {
                int dj = j+1, dk =k+1;
                printf ("Enter the value of (%d,%d) position : ",dj,dk);
                scanf ("%d",&mat[j][k][i]);
            }
        }
    }
    for (int i=0; i<n; i++) {
        int di = i+1;
        printf ("Enter the Value Enterd %d Matrix are \n",di);
        for (int j=0; j<row; j++) {
            for (int k=0; k<col; k++) {
                printf ("%d ",mat[j][k][i]);
            }
            printf ("\n");
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<row; j++) {
            for (int k=0; k<col; k++) {
                summat[j][k][0] += mat[j][k][i];
            }
        }
    }
    printf ("The Sum of the Given Matrie'es is : \n");
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            printf ("%d ",summat[i][j][0]);
        }
        printf ("\n");
    }
    return 0;
}