#include <stdio.h>
#include <stdlib.h>

struct Element {
    int i;
    int j;
    int value;
};

struct Sparse {
    int rows;
    int cols;
    int num;
    struct Element *elements;
};

// Function to create a sparse matrix
void create(struct Sparse *mat) {
    printf("Enter The Number of Rows : ");
    scanf("%d", &(mat->rows));
    printf("Enter The Number of Cols : ");
    scanf("%d", &(mat->cols));
    printf("Enter The Number of Elements : ");
    scanf("%d", &(mat->num));

    mat->elements = (struct Element *)malloc(mat->num * sizeof(struct Element));

    for (int i = 0; i < mat->num; i++) {
        printf("Enter The row, col, value Separated by spaces : ");
        scanf("%d %d %d", &mat->elements[i].i, &mat->elements[i].j, &mat->elements[i].value);
    }
}

// Function to add two sparse matrices
void add(struct Sparse *mat1, struct Sparse *mat2, struct Sparse *sumMat) {
    int i = 0, j = 0, k = 0;

    // Check if matrices have the same dimensions
    if (mat1->cols != mat2->cols || mat1->rows != mat2->rows) {
        printf("The Rows or cols are not the same\n");
        return;
    }

    // Allocate memory for the sum matrix
    sumMat->elements = (struct Element *)malloc((mat1->num + mat2->num) * sizeof(struct Element));
    
    while (i < mat1->num && j < mat2->num) {
        // If elements at the same position in both matrices, add their values
        if (mat1->elements[i].i == mat2->elements[j].i  && mat1->elements[i].j == mat2->elements[j].j ) {
            sumMat->elements[k].i = mat2->elements[j].i;
            sumMat->elements[k].j = mat2->elements[j].j;
            sumMat->elements[k].value = mat1->elements[i].value + mat2->elements[j].value;
            i++;
            j++;
            k++;
        }
        // If the element in mat1 has a higher row index, use the value from mat2
        else if (mat1->elements[i].i > mat2->elements[j].i) {
            sumMat->elements[k].i = mat2->elements[j].i;
            sumMat->elements[k].j = mat2->elements[j].j;
            sumMat->elements[k].value = mat2->elements[j].value;
            j++; 
            k++;
        }
        // If the row indices are the same, but the col index in mat1 is higher, use the value from mat2
        else if (mat1->elements[i].i == mat2->elements[j].i && mat1->elements[i].j > mat2->elements[j].j) {
            sumMat->elements[k].i = mat2->elements[j].i;
            sumMat->elements[k].j = mat2->elements[j].j;
            sumMat->elements[k].value = mat2->elements[j].value;
            j++;
            k++;
        }
        // Otherwise, use the value from mat1
        else {
            sumMat->elements[k].i = mat1->elements[i].i;
            sumMat->elements[k].j = mat1->elements[i].j;
            sumMat->elements[k].value = mat1->elements[i].value;
            i++;
            k++;
        }
    }

    while (i < mat1->num) {
        sumMat->elements[k].i = mat1->elements[i].i;
        sumMat->elements[k].i = mat1->elements[i].j;
        sumMat->elements[k].value = mat1->elements[i].value;
        i++;
        k++;
    }

    while (j < mat1->num) {
        sumMat->elements[k].i = mat2->elements[j].i;
        sumMat->elements[k].i = mat2->elements[j].j;
        sumMat->elements[k].value = mat2->elements[j].value;
        j++;
        k++;
    }

    sumMat->num = k;
}

// Function to print a sparse matrix
void print(struct Sparse *mat) {
    if (mat == NULL) {
        printf("CREATE A MATRIX FIRST");
        return;
    }

    int k = 0;

    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            if (mat->elements[k].i == i && mat->elements[k].j == j) {
                printf("%d", mat->elements[k].value);
                k++;
            } 
            else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    struct Sparse mat1;
    struct Sparse mat2;
    struct Sparse sumMat;

    // Create two sparse matrices
    create(&mat1);
    create(&mat2);

    // Print the matrices
    printf("Matrix 1:\n");
    print(&mat1);
    printf("Matrix 2:\n");
    print(&mat2);

    // Add the matrices and print the result
    add(&mat1, &mat2, &sumMat);   
    printf("Sum Matrix:\n");
    print(&sumMat);

    free(mat1.elements);
    free(mat2.elements);
    free(sumMat.elements);

    return 0;
}