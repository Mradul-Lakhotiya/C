#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Term {
    int coff;
    int exp;
};

struct Polynomial {
    int n;
    struct Term *terms;
};

void create(struct Polynomial *poly) {
    printf("Entre the NUmber of non-Zero Terms : ");
    scanf("%d", &poly->n);

    poly->terms = (struct Term *)malloc(poly->n * sizeof(struct Term));
 
    for (int i = 0; i < poly->n; i++) {
        printf("Entre the coff and Exp : ");
        scanf("%d %d", &poly->terms[i].coff, &poly->terms[i].exp);
    }
}

void sum(struct Polynomial *poly1, struct Polynomial *poly2, struct Polynomial *sum) {
    int i = 0, j = 0, k = 0;
    sum->terms = (struct Term *)malloc((poly1->n + poly2->n) * sizeof(struct Polynomial));

    while(i < poly1->n && j < poly2->n) {
        if (poly1->terms[i].exp == poly1->terms[j].exp) {
            sum->terms[k].coff = poly1->terms[i].coff + poly2->terms[j].coff;
            sum->terms[k].exp = poly1->terms[i].exp;
            i++;
            j++;
            k++;
        }
        else if (poly1->terms[i].exp > poly2->terms[j].exp) {
            sum->terms[k].coff = poly1->terms[i].coff;
            sum->terms[k].exp = poly1->terms[i].exp;
            i++;
            k++;
        }
        else {
            sum->terms[k].coff = poly1->terms[j].coff;
            sum->terms[k].exp = poly1->terms[j].exp;
            j++;
            k++;
        }
    }

    while (i < poly1->n) {
        sum->terms[k].coff = poly1->terms[i].coff;
        sum->terms[k].exp = poly1->terms[i].exp;
        i++;
        k++;  
    }

    while (j < poly2->n) {
        sum->terms[k].coff = poly1->terms[j].coff;
        sum->terms[k].exp = poly1->terms[j].exp;
        j++;
        k++;
    }

    sum->n = k;
}

void print(struct Polynomial *poly) {

    for (int i = 0; i < poly->n; i++) {
        printf("%d*X^%d + ", poly->terms[i].coff, poly->terms[i].exp);
    }
}

double findTheValueAt(int x, struct Polynomial *poly) {
    double sum = 0;
    for (int i = 0; i < poly->n; i++) {
        sum += poly->terms[i].coff * pow(x, poly->terms[i].exp);
    }

    return sum;
}

int main() {
    struct Polynomial poly1, poly2, sumPoly;
    int x;

    // Create the first polynomial
    printf("Enter details for the first polynomial:\n");
    create(&poly1);

    // Create the second polynomial
    printf("\nEnter details for the second polynomial:\n");
    create(&poly2);

    // Display the first polynomial
    printf("\nFirst Polynomial: ");
    print(&poly1);

    // Display the second polynomial
    printf("\nSecond Polynomial: ");
    print(&poly2);

    // Sum the polynomials
    sum(&poly1, &poly2, &sumPoly);

    // Display the sum of polynomials
    printf("\nSum of Polynomials: ");
    print(&sumPoly);

    // Evaluate the sum at a specific value of x
    printf("\nEnter a value for x to find the sum at that point: ");
    scanf("%d", &x);

    double result = findTheValueAt(x, &sumPoly);
    printf("The value of the sum at x = %d is: %.2f\n", x, result);

    // Free allocated memory
    free(poly1.terms);
    free(poly2.terms);
    free(sumPoly.terms);

    return 0;
}