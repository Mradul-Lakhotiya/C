#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    int data;
    struct Node *next;
};

void insertBeforeNode (struct Node **Head_ptr, int postion, int value);
void createList(struct Node **Head_ptr, int value);
void insertInSortedManner(struct Node **Head_prt, int value);
void displayList (struct Node *Head);
void deleteLinkedList (struct Node *Head);

void createList(struct Node **Head_ptr, int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;
    newNode->next = NULL;
    *Head_ptr = newNode;
}

void insertBeforeNode (struct Node **Head_ptr, int postion, int value) {
    if (*Head_ptr == NULL) {
        printf("\nPlease \"CREATE A LIST\" first\n");
        return;
    }

    struct Node *temp = NULL;
    struct Node *current = *Head_ptr;
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL) {
        printf("\nMEMORY ALLOCATION FAILED\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    while (current != NULL && postion > 0) {
        temp = current;
        current = current->next;
        postion--;
    }

    if (postion > 0) {
        printf("\nEnter a VALID POSITION\n");
        free(newNode);
        return;
    }

    temp->next = newNode;
    newNode->next = current;

    return;
}

void insertInSortedManner(struct Node **Head_prt, int value) {
    struct Node *current = *Head_prt;
    int position = 0;
    bool inserted = false;

    while (current != NULL) {
        if (current->data > value) {
            insertBeforeNode(Head_prt, position, value);
            inserted = true;
            break;
        }
        position++;
        current = current->next;
    }

    if (!inserted) {
        insertBeforeNode(Head_prt, position, value);
    }
}

void displayList (struct Node *Head) {
    struct Node *currentNode = Head;
    if (Head == NULL) {
        printf("[ ]");
        return;
    }
    
    printf("[ ");
    while (currentNode != NULL) {
        printf("%d, ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\b\b ]");

    return;
}

void deleteLinkedList (struct Node *Head) {
    if (Head == NULL) {
        printf("\nPlease \"CREATE A LIST\" first\n");
        return;
    }

    struct Node *current = Head;
    struct Node *temp = NULL;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }

    Head = NULL;
    return;
}

int main () {
    struct Node *Head;
    struct Node **Head_ptr = &Head;
    *Head_ptr = NULL;
    
    int choice;
    int value;

    do {
        printf("\n 1. Create Link List\n");
        printf(" 2. Add Element\n");
        printf(" 3. Display List\n");
        printf(" 0. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Entre the value to add : ");
            scanf("%d", &value);

            createList(Head_ptr, value);
            break;

        case 2:
            printf("Entre the value to add : ");
            scanf("%d", &value);

            insertInSortedManner(Head_ptr, value);
            break;
            
        case 3:
            displayList(Head);
            break;
        
        case 0:
            deleteLinkedList(Head);
            exit(0);

        default:
            break;
        }
    }
    while (choice != 0);

    return 0;
}
