#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *Lchild;
    struct node *Rchild;
    unsigned int height;
    int data;
};

typedef struct node node;
node *root = NULL;

node *creatNewNode(int);
node *insertInBinarySearchTreeRecursion(node *, int);
node *deletingInBinarySearchTreeRecursion(node *, int);
node *LLRotation(node *);
node *LRRotation(node *);
node *RRRotation(node *);
node *RLRotation(node *);
void deleteTree(node *);
int balanceFactor(node *);
int nodeHeight(node *);
int minNumberOfNodeForGivenHeight(int node);

int main() {
    root = insertInBinarySearchTreeRecursion(root, 10);
    insertInBinarySearchTreeRecursion(root, 5);
    insertInBinarySearchTreeRecursion(root, 2);
    deletingInBinarySearchTreeRecursion(root, 2);

    printf("%d", root->data);
    deleteTree(root); 
    return 0;
}

int minNumberOfNodeForGivenHeight(int node) {
    if (node < 4) {
        return node;
    }
    else {
        return minNumberOfNodeForGivenHeight(node - 1) + minNumberOfNodeForGivenHeight(node - 2) + 1;
    }
}

node *creatNewNode(int data) {
    node *newNode = (node *)malloc(sizeof(node));

    if (newNode == NULL) {
        printf("Memory Allocation Failed");
        exit(EXIT_FAILURE);
    } 
    else {
        newNode->data = data;
        newNode->Lchild = NULL;
        newNode->Rchild = NULL;
        newNode->height = 1;
    }

    return newNode;
}

int nodeHeight(node *node) {
    int hl, hr;
    hl = node && node->Lchild ? node->Lchild->height : 0;
    hr = node && node->Rchild ? node->Rchild->height : 0;

    return hl > hr ? hl + 1 : hr + 1;
} 

int balanceFactor(node *node) {
    int hl = node && node->Lchild ? node->Lchild->height : 0;
    int hr = node && node->Rchild ? node->Rchild->height : 0;

    return hl - hr;
}

node *LLRotation(node *child) {
    node *Lchild = child->Lchild;
    node *LRchild = Lchild->Rchild;

    Lchild->Rchild = child;
    child->Lchild = LRchild;
    child->height = nodeHeight(child);
    Lchild->height = nodeHeight(Lchild);

    if (child == root) {
        root = Lchild;
    }

    return Lchild;
}

node *LRRotation(node *child) {
    node *Lchild = child->Lchild;
    node *LRchild = Lchild->Rchild;

    child->Lchild = LRchild->Rchild;
    Lchild->Rchild = LRchild->Lchild;

    LRchild->Lchild = Lchild;
    LRchild->Rchild = child;

    Lchild->height = nodeHeight(Lchild);
    child->height = nodeHeight(child);
    LRchild->height = nodeHeight(LRchild);

    if (child == root) {
        root = LRchild;
    }

    return LRchild;
}

node *RRRotation(node *child) {
    node *Rchild = child->Rchild;
    node *RLchild = Rchild->Lchild;

    child->Rchild = RLchild;
    Rchild->Lchild = child;

    Rchild->height = nodeHeight(Rchild);
    child->height = nodeHeight(child);

    if (child == root) {
        root = Rchild;
    }

    return Rchild;
}

node *RLRotation(node *child) {
    child->Rchild = LLRotation(child->Rchild);
    return RRRotation(child);
}

node *insertInBinarySearchTreeRecursion(node *child, int data) {
    if (child == NULL) {
        return creatNewNode(data);
    }
    else if (child->data > data) {
        child->Lchild = insertInBinarySearchTreeRecursion(child->Lchild, data);
    }
    else {
        child->Rchild = insertInBinarySearchTreeRecursion(child->Rchild, data);
    }

    child->height = nodeHeight(child);

    if (balanceFactor(child) == 2 && balanceFactor(child->Lchild) == 1) { // LL Rotation
        return LLRotation(child);
    }
    else if (balanceFactor(child) == 2 && balanceFactor(child->Rchild) == -1) { // LR Rotation 
        return LRRotation(child);
    }
    else if (balanceFactor(child) == -2 && balanceFactor(child->Rchild) == -1) { // RR Rotation
        return RRRotation(child);
    }
    else if (balanceFactor(child) == -2 && balanceFactor(child->Rchild) == 1) { // RL Rotation
        return RLRotation(child);
    }
    return child;
}

void deleteTree(node *root) {
    if (root) {
        deleteTree(root->Lchild);
        deleteTree(root->Rchild);
        free(root);
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
        if (nodeHeight(root->Lchild) > nodeHeight(root->Rchild)) {
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

    root->height = nodeHeight(root);

    if (balanceFactor(root) == 2 && balanceFactor(root->Lchild) == 1) { // L1 Rotation
        LLRotation(root);
    }
    else if (balanceFactor(root) == 2 && balanceFactor(root->Lchild) == -1) { // L-1 Rotation
        LRRotation(root);
    }
    else if (balanceFactor(root) == -2 && balanceFactor(root->Rchild) == -1) { // R1 Rotation
        RRRotation(root);
    }
    else if (balanceFactor(root) == -1 && balanceFactor(root->Rchild) == 1) { // R-1 Rotation
        RLRotation(root);
    }
    else if (balanceFactor(root) == 2 && balanceFactor(root->Lchild) == 0) { // L0 Rotation
        LLRotation(root);
    }
    else if (balanceFactor(root) == -2 && balanceFactor(root->Rchild) == 0) { // R0 Rotation
        RRRotation(root);
    }
    return root;
}
