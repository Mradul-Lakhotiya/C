#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Polynomial {
    int coff;
    int exp;
    struct Polynomial* next;
};

typedef struct Polynomial * polyPTR;

void addTerm(polyPTR *poly, int coff, int exp);
void removeByExp(polyPTR *poly, int exp);  
void printPolynomial(polyPTR poly);
void deletePolynomial(polyPTR poly);
void userInput(polyPTR *poly);  
void addTwoPolynomial(polyPTR ploy1, polyPTR ploy2, polyPTR *sumPoly);  
double valueOfPolynomial(polyPTR poly, int x);

int main() {
    polyPTR poly1 = NULL;
    polyPTR poly2 = NULL;
    polyPTR sumPoly = NULL;
    int choice, x;

    do {
        printf("\nMenu:\n");
        printf("1. Add two polynomials\n");
        printf("2. Evaluate a polynomial\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (poly1 == NULL) {
                    printf("Enter the First Polynomial:\n");
                    userInput(&poly1);
                }

                printf("Enter the Second Polynomial:\n");
                userInput(&poly2);

                if (sumPoly != NULL) {
                    deletePolynomial(sumPoly);
                    sumPoly = NULL;
                }

                sumPoly = (polyPTR)malloc(sizeof(struct Polynomial));
                if (sumPoly == NULL) {
                    printf("Memory Allocation Failed\n");
                    exit(EXIT_FAILURE);
                }
                sumPoly->next = NULL;

                addTwoPolynomial(poly1, poly2, &sumPoly);
                printf("Resultant Polynomial: ");
                printPolynomial(sumPoly);
                break;

            case 2:
                if (poly1 == NULL) {
                    printf("Enter the Polynomial to Evaluate:\n");
                    userInput(&poly1);
                }

                printf("Enter the value of x: ");
                scanf("%d", &x);
                printf("Result: %.2f\n", valueOfPolynomial(poly1, x));
                break;

            case 0:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 0);

    deletePolynomial(poly1);
    deletePolynomial(poly2);
    deletePolynomial(sumPoly);

    return 0;
}

void addTerm(polyPTR *poly, int coff, int exp) {
    polyPTR newTerm = (polyPTR)malloc(sizeof(struct Polynomial));

    if (newTerm == NULL) {
        printf("Memory Allocation Failed\n");
        exit(EXIT_FAILURE);
    }

    newTerm->next = *poly;
    newTerm->coff = coff;
    newTerm->exp = exp;

    *poly = newTerm;
}

void removeByExp(polyPTR *poly, int exp) {
    if (*poly == NULL) {
        printf("No Polynomial To Remove");
        return;
    }

    polyPTR current = *poly;
    polyPTR temp = NULL;

    while (current != NULL) {
        if (current->exp == exp) {
            if (temp != NULL) {
                temp->next = current->next;
            }

            free(current);
            return;
        }
        temp = current;
        current = current->next;
    }
}

void printPolynomial(polyPTR poly) {
    polyPTR current = poly;

    while (current != NULL) {
        printf(" %d*x^%d +", current->coff, current->exp);
        current = current->next;
    }
    printf("\b \n");
}

void deletePolynomial(polyPTR poly) {
    polyPTR current = poly;
    polyPTR temp = NULL;

    while (current != NULL) {
        temp = current->next;
        free(current);
        current = temp;
    }
}

void userInput(polyPTR *poly) {
    int n, exp, coff;
    printf("Enter the Number of Terms To Enter: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter the coefficient: ");
        scanf("%d", &coff);
        printf("Enter the exponent: ");
        scanf("%d", &exp);

        addTerm(poly, coff, exp);
    }
}

void addTwoPolynomial(polyPTR ploy1, polyPTR ploy2, polyPTR *sumPoly) {
    polyPTR current1 = ploy1;
    polyPTR current2 = ploy2;

    int sumExp, sumCoff;

    while (current1 != NULL && current2 != NULL) {
        if (current1->exp == current2->exp) {
            sumExp = current1->exp;
            sumCoff = current1->coff + current2->coff;
            addTerm(sumPoly, sumCoff, sumExp);

            current1 = current1->next;
            current2 = current2->next;
        } else if (current1->exp > current2->exp) {
            addTerm(sumPoly, current1->coff, current1->exp);
            current1 = current1->next;
        } else {
            addTerm(sumPoly, current2->coff, current2->exp);
            current2 = current2->next;
        }
    }

    while (current1 != NULL) {
        addTerm(sumPoly, current1->coff, current1->exp);
        current1 = current1->next;
    }

    while (current2 != NULL) {
        addTerm(sumPoly, current2->coff, current2->exp);
        current2 = current2->next;
    }
}
