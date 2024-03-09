#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

struct node {
    int data;
    struct node *Lchild;
    struct node *Rchild;
};

struct Stack {
    struct node *data;
    struct Stack *prev;
};

typedef struct node node;
typedef struct Stack Stack;

// Tree Functions
node *searchInBinaryTree(node *, int);
node *searchInBinaryTreeRecursion(node *, int);
node *insertInBinarySearchTreeRecursion(node *, int);
node *creatNewNode(int);
node *deletingInBinarySearchTreeRecursion(node *, int);
void insertInBinarySearchTree(node **, int);
void inOrderRecursion(node *);
void deleteTree(node *);
node *creatFromPreOrder(int *, int);
int heightOfTree(node *);

// Stack Functions
void push(Stack **, node *);
node *pop(Stack **);
bool isEmpty(Stack *);
int peek(Stack *);

int main() {
    node *root = NULL;
    node *temp = NULL;
    insertInBinarySearchTree(&root, 3);
    root = insertInBinarySearchTreeRecursion(root, 2);
    insertInBinarySearchTree(&root, 1);

    printf("%d, ", root->data);
    printf("%d, ", (root->Lchild)->data);
    printf("%d, \n", (root->Lchild)->Lchild->data);

    searchInBinaryTree(root, 2) ? printf("Found\n") : printf("Not Found\n");
    searchInBinaryTreeRecursion(root, 1) ? printf("Found\n") : printf("Not Found\n");

    inOrderRecursion(root);

    printf("\nHeight of The Tree: %d\n", heightOfTree(root));
    temp = deletingInBinarySearchTreeRecursion(root, 3);

    inOrderRecursion(root);
    printf("\nHeight of The Tree: %d\n", heightOfTree(root));

    deleteTree(root);
    root = NULL;

    int preOrder[] = {30, 20, 10, 15, 25, 40, 50, 45};
    root = creatFromPreOrder(preOrder, sizeof(preOrder)/sizeof(preOrder[0]));

    inOrderRecursion(root);
    printf("\nHeight of The Tree: %d\n", heightOfTree(root));

    deleteTree(root);

    return 0;
}

void inOrderRecursion(node *root) {
    if (root) {
        inOrderRecursion(root->Lchild);
        printf("%d, ", root->data);
        inOrderRecursion(root->Rchild);
    }
}

void deleteTree(node *root) {
    if (root) {
        deleteTree(root->Lchild);
        deleteTree(root->Rchild);
        free(root);
    }
}

node *creatNewNode(int data) {
    node *newNode = (node *)malloc(sizeof(node));

    if (newNode == NULL) {
        printf("Memory Allocation Failed\n");
        exit(EXIT_FAILURE);
        return NULL;
    }
    else {
        newNode->data = data;
        newNode->Lchild = NULL;
        newNode->Rchild = NULL;

        return newNode;
    }
}

node *searchInBinaryTreeRecursion(node *root, int key) {
    if (root == NULL) {
        return NULL;
    }
    else if (root->data == key) {
        return root;
    }
    else if (root->data > key) {
        return searchInBinaryTreeRecursion(root->Lchild, key);
    }
    else {
        return searchInBinaryTreeRecursion(root->Rchild, key);
    }
}

node *searchInBinaryTree(node *root, int key) {
    while (root != NULL) {
        if (root->data == key) {
            return root;
        }
        else if (root->data > key) {
            root = root->Lchild;
        }
        else {
            root = root->Rchild;
        }
    }

    return NULL;
}

void insertInBinarySearchTree(node **root, int data) {
    node *newNode = creatNewNode(data);
    if (*root == NULL) {
        *root = newNode;
        return;
    }
    node *prevNode = NULL;
    node *current = *root;

    while (current != NULL) {
        if (current->data == data) {
            printf("The Element All-Ready Exist in The Tree\n");
            return;
        }
        else if (current->data > data) {
            prevNode = current;
            current = current->Lchild;
        }
        else {
            prevNode = current;
            current = current->Rchild;
        }
    }

    if (prevNode->data > data) {
        prevNode->Lchild = newNode;
    }
    else {
        prevNode->Rchild = newNode;
    }

    return;
}

node *insertInBinarySearchTreeRecursion(node *root, int data) {
    if (root == NULL) {
        return creatNewNode(data);
    }
    else if (root->data > data) {
        root->Lchild = insertInBinarySearchTreeRecursion(root->Lchild, data);
    }
    else {
        root->Rchild = insertInBinarySearchTreeRecursion(root->Rchild, data);
    }
}

int heightOfTree(node *root) {
    if (root) {
        int x = heightOfTree(root->Lchild);
        int y = heightOfTree(root->Rchild);

        return x > y ? x + 1 : y + 1;
    }
    else {
        return 0;
    }
}

node *deletingInBinarySearchTreeRecursion(node *root, int key) {
    if (root == NULL) {
        return NULL;
    }
    if (root->Lchild == NULL && root->Rchild == NULL) {
        if (root->data == key) {
            free(root);
            return NULL;
        }
        return root;
    }

    if (root->data == key) {
        if (heightOfTree(root->Lchild) > heightOfTree(root->Rchild)) {
            node *temp = root->Lchild; // in-order Predecessor
            while (temp->Rchild != NULL) { // Finding the in-order Predecessor
                temp = temp->Rchild;
            }

            root->data = temp->data;
            root->Lchild = deletingInBinarySearchTreeRecursion(root->Lchild, temp->data);
        }
        else {
            node *temp = root->Rchild; // in-order Successor
            while (temp->Lchild != NULL) { // Finding the in-order Successor
                temp = temp->Lchild;
            }

            root->data = temp->data;
            root->Rchild = deletingInBinarySearchTreeRecursion(root->Rchild, temp->data);
        }
    }
    else if (root->data > key) {
        root->Lchild = deletingInBinarySearchTreeRecursion(root->Lchild, key);
    }
    else {
        root->Rchild = deletingInBinarySearchTreeRecursion(root->Rchild, key);
    }

    return root;
}

node *creatFromPreOrder(int *preOrder, int size) {
    Stack *st = NULL;
    int i = 0;
    node *root = creatNewNode(preOrder[i++]);
    node *tempNode = root;
    node *temp = NULL;

    while (i < size) {
        if (preOrder[i] < tempNode->data) {
            temp = creatNewNode(preOrder[i++]);
            tempNode->Lchild = temp;
            push(&st, tempNode);
            tempNode = temp;
        }
        else {
            if (preOrder[i] > tempNode->data && preOrder[i] < peek(st)) {
                temp = creatNewNode(preOrder[i++]);
                tempNode->Rchild = temp;
                tempNode = temp;
            }
            else {
                tempNode = pop(&st);
            }
        }
    }

    return root;
}

/* Stack Functions */

void push(Stack **st, node *data) {
    Stack *newNode = (Stack *)malloc(sizeof(Stack));
    if (newNode == NULL) {
        printf("Memory Allocation Failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->prev = *st;
    *st = newNode;
}

node *pop(Stack **st) {
    if (*st == NULL) {
        printf("Stack is Empty\n");
        return NULL;
    }
    else {
        node *temp = (*st)->data;
        Stack *tempNode = *st;
        *st = (*st)->prev;
        free(tempNode);
        return temp;
    }
}

bool isEmpty(Stack *st) {
    return st == NULL;
}

int peek(Stack *st) {
    if (st == NULL) {
        return (int)INT64_MAX;
    }
    else {
        return (int)(st->data);
    }
}