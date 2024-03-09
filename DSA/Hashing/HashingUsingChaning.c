#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    struct node *next;
    int data;
};

typedef struct node node;

node *createNode(int);
void insertInList(node **, int);
bool isThere(node *, int);
void deleteByValue(node **, int);
void displayList(node *);
void displayAllLists(node **, int);
void freeAllLists(node **, int);

int main() {
    int ch;
    node **headArray = (node **)malloc(10 * sizeof(node *));
    for (int i = 0; i < 10; i++) {
        headArray[i] = NULL;
    }

    do {
        printf("----------------------------------------\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                {
                    int data;
                    printf("Enter data to insert: ");
                    scanf("%d", &data);
                    insertInList(&headArray[data%10], data);
                    displayAllLists(headArray, 10);
                    break;
                }

            case 2:
                {
                    int key;
                    printf("Enter data to delete: ");
                    scanf("%d", &key);
                    deleteByValue(&headArray[key%10], key);
                    displayAllLists(headArray, 10);
                    break;
                }

            case 3:
                {
                    int key;
                    printf("Enter data to search: ");
                    scanf("%d", &key);
                    if (isThere(headArray[key%10], key)) {
                        printf("\nElement found in the list.\n");
                    } 
                    else {
                        printf("\nElement not found in the list.\n");
                    }
                    displayAllLists(headArray, 10);
                    break;
                }

            case 0:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    } while (ch != 0);

    freeAllLists(headArray, 10);

    return 0;
}

node *createNode(int data) {
    node *newNode = (node *)malloc(sizeof(node));

    if (newNode == NULL) {
        printf("\nMemory Allocation Failed\n");
        exit(EXIT_FAILURE);
    }
    else {
        newNode->data = data;
        newNode->next = NULL;
    }

    return newNode;
}

void insertInList(node **head, int data) {
    node *newNode = createNode(data);

    if ((*head) == NULL || data <= (*head)->data) {
        newNode->next = (*head);
        (*head) = newNode;
    }
    else {
        node *temp = *head;
        node *prev = NULL;

        while (temp != NULL && data > temp->data) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = newNode;
        newNode->next = temp;
    }
}

bool isThere(node *head, int key) {
    node *temp = head;
    while (temp != NULL) {
        if (temp->data == key) {
            return true;
        }
        
        temp = temp->next;
    }

    return false;
}

void deleteByValue(node **head, int key) {
    node *prev = NULL;
    node *temp = (*head);

    while (temp != NULL) {
        if (temp->data == key) {
            if (prev == NULL) {
                (*head) = (*head)->next;
                free(temp);
            }
            else {
                prev->next = temp->next;
                free(temp);
            }

            break;
        }
        prev = temp;
        temp = temp->next;
    }
}

void displayList(node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void displayAllLists(node **headArray, int size) {
    printf("Current state of all lists:\n");
    for (int i = 0; i < size; i++) {
        printf("List %d: ", i);
        displayList(headArray[i]);
    }
}

void freeAllLists(node **headArray, int size) {
    for (int i = 0; i < size; i++) {
        node *current = headArray[i];
        while (current != NULL) {
            node *temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(headArray);
}
