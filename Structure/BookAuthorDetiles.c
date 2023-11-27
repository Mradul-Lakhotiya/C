/*
 Create a structure Author with fields for the author's name and birth year.
 Then further create a structure Book with fields for title and price. 
 Enhance the Book structure by adding a nested Author structure along with 
 fields for title and price. Write a program to input details for N number of 
 books, display the information, sort the books based on their prices and find 
 the book with the highest price. 

Use binary search for finding the book with the highest price.
*/

#include <stdio.h> 

struct Author {
    char name[25];
    int BirthYear;
};

struct Book {
    char title[50];
    int price;
    struct Author AuthorDetiles;
};

int main () {
    int n;

    printf ("Entre the value of n : ");
    scanf ("%d", &n);
    struct Book BookDetiles[n];

    for (int i = 0; i < n; i++) {
        printf ("-----------------------------------------------\n");
        printf ("Enter the title of Book-%d : ", i+1);
        scanf("%s", BookDetiles[i].title);

        printf ("Enter the Prize of Book-%d : ", i+1);
        scanf ("%d", &BookDetiles[i].price);

        printf ("Enter the name of the author : ");
        scanf("%s", BookDetiles[i].AuthorDetiles.name);

        printf ("Enter the birth year of author : ");
        scanf ("%d", &BookDetiles[i].AuthorDetiles.BirthYear);
    }
    for (int i = 0; i < n; i++) { // bubble sort
        for (int j = i+1; j < n-1; j++) {
            if (BookDetiles[i].price > BookDetiles[j].price) {
                int temp = BookDetiles[i].price;
                BookDetiles[i].price = BookDetiles[j].price;
                BookDetiles[j].price = temp;
            }
        }
    }
    printf ("-------------------------------------------------\n");
    printf ("The book with thw max prize is : \n");
    printf ("Tital : %S\n", BookDetiles[n-1].title);
    printf ("Prize : %d\n", BookDetiles[n-1].price);
    printf ("Author : %s\n", BookDetiles[n-1].AuthorDetiles.name);
    printf ("Birth year : %d\n", BookDetiles[n-1].AuthorDetiles.BirthYear);

    return 0;
}