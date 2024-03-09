#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node {
    struct Node *Lchild;
    int data;
    struct Node *Rchild;
};

struct ElementOfQueue {
    struct Node *data;
    struct ElementOfQueue *next;
};

struct Queue {
    struct ElementOfQueue *front;
    struct ElementOfQueue *rear;
};

struct ElementOfStack {
    struct Node *data;
    struct ElementOfStack *prev;
};

struct Stack {
    struct ElementOfStack *rear;
};

typedef struct Node * NodePtr;
typedef struct ElementOfQueue * EQPtr;
typedef struct Queue * QueuePtr;
typedef struct ElementOfStack * ESPtr;
typedef struct Stack * StackPtr;

// Queue Functions 
void createQueue(QueuePtr *que);
void enqueue(QueuePtr *que, NodePtr prt);
void deleteQueue(QueuePtr que);
NodePtr dequeue(QueuePtr que);
bool isEmptyQueue(QueuePtr que);

// Tree Functions
void createTree(NodePtr *root);
void perOrder(NodePtr node);
void postOrder(NodePtr node);
void inOrder(NodePtr node);
void deleteTree(NodePtr root);

void perOrderIterative(NodePtr root);
// *void postOrderIterative(NodePtr root);
void inOrderIterative(NodePtr root);
void levelOrder(NodePtr root);

int countNumberOfNodes(NodePtr root);
int countNumberOf2DegNode(NodePtr root);
int sumOfAllTheElementOfTree(NodePtr root);
int heightOFTree(NodePtr root);
int countNumberOfLeafNode(NodePtr root);
int countNumberOf1DegNode(NodePtr root);
int numberOfNonLeafNode(NodePtr root);

int getInOrderIndex(int arr[], int start, int end, int key);
NodePtr createBtree(int perOrder[], int inOrder[], int start, int end, int *preIndex);
void printBtree(NodePtr root);

// Stack Functions
void createStack(StackPtr *st);
void push(StackPtr *st, NodePtr data);
NodePtr pop(StackPtr st);
NodePtr peek(StackPtr st);
bool isEmptyStack(StackPtr st);

int main() {
    NodePtr root = NULL;

    createTree(&root);

    printf("\nPre-Order : \n");
    perOrder(root);
    printf("\n");
    perOrderIterative(root);
    printf("\n");

    printf("\nIn-Order : \n");
    inOrder(root);
    printf("\n");
    inOrderIterative(root);
    printf("\n");

    printf("\nPost-Order : \n");
    postOrder(root);
    printf("\n");
    // postOrderIterative(root);
    printf("\n");

    printf("\nLevel-Order : \n");
    levelOrder(root);
    printf("\n");

    printf("\nNumber of nodes are: %d\n", countNumberOfNodes(root));
    printf("Number of 2 Deg nodes are: %d\n", countNumberOf2DegNode(root));
    printf("Sum of All the Elements is: %d\n", sumOfAllTheElementOfTree(root));
    printf("Height of the Tree is: %d\n", heightOFTree(root));
    printf("Number of Leaf Nodes are: %d\n", countNumberOfLeafNode(root));
    printf("Number of 1 Deg Nodes are: %d\n", countNumberOf1DegNode(root));
    printf("Number of Non-Leaf Nodes are: %d\n", numberOfNonLeafNode(root));

    deleteTree(root);
    root = NULL; // Set root to NULL after deleting the tree

    int preOrder[] = {1, 2, 4, 5, 3};
    int inOrder[] = {4, 2, 5, 1, 3};
    int preIndex = 0;

    NodePtr newRoot = createBtree(preOrder, inOrder, 0, sizeof(preOrder) / sizeof(preOrder[0]) - 1, &preIndex);
    printf("\nPre-Order : \n");
    perOrder(newRoot);
    printf("\n");
    perOrderIterative(newRoot);
    printf("\n");

    return 0;
}

//! QUEUE Functions

void createQueue(QueuePtr *que) {
    *que = (QueuePtr)malloc(sizeof(struct Queue));
    
    if (*que == NULL) {
        printf("Memory Allocation FAILED // Queue if FULL");
        exit(EXIT_FAILURE);
    }

    (*que)->front = NULL;
    (*que)->rear = NULL;
}

void enqueue(QueuePtr *que, NodePtr prt) {
    EQPtr newQue = (EQPtr)malloc(sizeof(struct ElementOfQueue));

    if (newQue == NULL) {
        printf("Queue if FULL\n");
        exit(EXIT_FAILURE);
    } else {
        newQue->data = prt;
        newQue->next = NULL;

        if ((*que)->front == NULL) {
            (*que)->front = newQue;
            (*que)->rear = newQue;
        } else {
            (*que)->rear->next = newQue;
            (*que)->rear = newQue;
        }
    }
}

NodePtr dequeue(QueuePtr que) {
    if (isEmptyQueue(que)) {

        printf("The Queue id EMPTY\n");
        return NULL;
    } else {
        EQPtr toDelete = que->front;
        NodePtr temp = toDelete->data;

        que->front = que->front->next;

        // printf("%d Dequeued\n", temp->data);
        free(toDelete);

        return temp;
    }
}

bool isEmptyQueue(QueuePtr que) {
    return que->front == NULL;
}

void deleteQueue(QueuePtr que) {
    EQPtr current = que->front;
    EQPtr temp = NULL;

    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
}

//! TREE Functions

void createTree(NodePtr *root) {
    *root = (NodePtr)malloc(sizeof(struct Node));
    QueuePtr que;
    createQueue(&que);

    NodePtr current = NULL, temp = NULL;
    int element;

    printf("Entre The value to store in ROOT : ");
    scanf("%d", &(*root)->data);

    enqueue(&que, *root);

    while(!isEmptyQueue(que)) {
        NodePtr current = dequeue(que);
        printf("(-1 means no child)\n");
        printf("Data for %d'es Chiles ->\n", current->data);

        printf("Enter The Left Child : ");
        scanf("%d", &element);

        if (element != -1) {
            temp = (NodePtr)malloc(sizeof(struct Node));
            temp->data = element;
            temp->Lchild = NULL;
            temp->Rchild = NULL;

            current->Lchild = temp;
            enqueue(&que, temp);
        }

        printf("Enter The Right Child : ");
        scanf("%d", &element);

        if (element != -1) {
            temp = (NodePtr)malloc(sizeof(struct Node));
            temp->data = element;
            temp->Lchild = NULL;
            temp->Rchild = NULL;

            current->Rchild = temp;
            enqueue(&que, temp);
        }
    }
    deleteQueue(que);
}

void perOrder(NodePtr node) {
    if (node != NULL) {
        printf("%d, ", node->data);
        perOrder(node->Lchild);
        perOrder(node->Rchild);
    }
}

void inOrder(NodePtr node) {
    if (node != NULL) {
        inOrder(node->Lchild);
        printf("%d, ", node->data);
        inOrder(node->Rchild);
    }
}

void postOrder(NodePtr node) {
    if (node != NULL) {
        perOrder(node->Lchild);
        perOrder(node->Rchild);
        printf("%d, ", node->data);
    }
}

void deleteTree(NodePtr root) {
    if (root != NULL) {
        deleteTree(root->Lchild);
        deleteTree(root->Rchild);
        free(root);
    }
}

void perOrderIterative(NodePtr root) {
    StackPtr st;
    createStack(&st);

    NodePtr temp = root;

    while (temp != NULL || !isEmptyStack(st)) {
        if (temp != NULL) {
            printf("%d, ", temp->data);
            push(&st, temp);
            temp = temp->Lchild;
        }
        else {
            temp = pop(st);
            if (temp != NULL) {
                temp = temp->Rchild;
            }
        }
    }
}

void inOrderIterative(NodePtr root) {
    StackPtr st;
    createStack(&st);

    NodePtr temp = root;

    while (temp != NULL || !isEmptyStack(st)) {
        if (temp != NULL) {
            push(&st, temp);
            temp = temp->Lchild;
        }
        else {
            temp = pop(st);
            if (temp != NULL) {
                printf("%d, ", temp->data);
                temp = temp->Rchild;
            }
        }
    }
}

// void postOrderIterative(NodePtr root) {
//         StackPtr st;
//     createStack(&st);
//
//     NodePtr temp = root;
//     NodePtr lastVisited = NULL;
//
//     while (temp != NULL || !isEmptyStack(st)) {
//         if (temp != NULL) {
//             push(&st, temp);
//             temp = temp->Lchild;
//         }
//         else {
//             NodePtr peekNode = peek(st);
//
//             if (peekNode->Rchild != NULL && lastVisited != peekNode->Rchild) {
//                 temp = peekNode->Rchild;
//             } else {
//                 temp = pop(&st);
//                 printf("%d, ", temp->data);
//                 temp = temp->Rchild;
//             }
//         }
//     }
// }

void levelOrder(NodePtr root) {
    QueuePtr que;
    createQueue(&que);

    printf("%d, ", root->data);
    enqueue(&que, root);

    NodePtr temp = NULL;

    while(!isEmptyQueue(que)) {
        temp = dequeue(que);

        if (temp->Lchild != NULL) {
            printf("%d, ", temp->Lchild->data);
            enqueue(&que, temp->Lchild);
        }

        if (temp->Rchild != NULL) {
            printf("%d, ", temp->Rchild->data);
            enqueue(&que, temp->Rchild);
        }

    }
}

int countNumberOfNodes(NodePtr root) {
    if (root) {
        return countNumberOfNodes(root->Lchild) + countNumberOfNodes(root->Rchild) + 1;
    }
    else {
        return 0;
    }
}

int countNumberOf2DegNode(NodePtr root) {
    if (root) {
        int x = countNumberOf2DegNode(root->Lchild);
        int y = countNumberOf2DegNode(root->Rchild);

        if (root->Lchild && root->Rchild) {
            return x + y + 1;
        }
        else {
            return x + y;
        }
    }
    else {
        return 0;
    }
}

int sumOfAllTheElementOfTree(NodePtr root) {
    if (root) {
        int x = sumOfAllTheElementOfTree(root->Lchild);
        int y = sumOfAllTheElementOfTree(root->Rchild);

        return x + y + root->data;
    }
    else {
        return 0;
    }
}

int heightOFTree(NodePtr root) {
    if (root) {
        int x = heightOFTree(root->Lchild);
        int y = heightOFTree(root->Rchild);

        return x > y ? x + 1 : y + 1;
    }
    else {
        return 0;
    } 
}

int countNumberOfLeafNode(NodePtr root) {
    if (root) {
        int x = countNumberOfLeafNode(root->Lchild);
        int y = countNumberOfLeafNode(root->Rchild);

        if(root->Lchild == NULL && root->Rchild == NULL) {
            return x + y + 1;
        }
        else {
            return x + y;
        }
    }
    else {
        return 0;
    }
}

int countNumberOf1DegNode(NodePtr root) {
    if (root) {
        int x = countNumberOf2DegNode(root->Lchild);
        int y = countNumberOf2DegNode(root->Rchild);

        if ((root->Lchild == NULL) ^ (root->Rchild != NULL)) {
            return x + y + 1;
        }
        else {
            return x + y;
        }
    }
    else {
        return 0;
    }
}

int numberOfNonLeafNode(NodePtr root) {
    if (root) {
        int x = countNumberOf2DegNode(root->Lchild);
        int y = countNumberOf2DegNode(root->Rchild);

        if (root->Lchild || root->Rchild){
            return x + y + 1;
        }
        else {
            return x + y;
        }
    }
    else {
        return 0;
    }
}

void printBtree(NodePtr root) {
    if (root) {
        printBtree(root->Lchild);
        printf("%d ", root->data);
        printBtree(root->Rchild);
    }
}

int getInOrderIndex(int arr[], int start, int end, int key) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == key) {
            return i;
        }
    }

    return -1;
}

NodePtr createBtree(int preOrder[], int inOrder[], int start, int end, int *preIndex) {
    if (start > end) {
        return NULL;
    }

    NodePtr newNode = (NodePtr)malloc(sizeof(struct Node));

    if(newNode == NULL) {
        printf("Memory Allocation Failed");
        exit(EXIT_FAILURE);
    }

    newNode->data = preOrder[*preIndex];
    (*preIndex)++;
    newNode->Lchild = NULL;
    newNode->Rchild = NULL;

    if (start == end) {
        return newNode;
    }

    int index = getInOrderIndex(inOrder, start, end, newNode->data);
    if (index == -1) {
        printf("Key not found in the array");
        exit(EXIT_FAILURE);
    }
    newNode->Lchild = createBtree(preOrder, inOrder, start, index - 1, preIndex);
    newNode->Rchild = createBtree(preOrder, inOrder, index + 1, end, preIndex);

    return newNode;
}

//! Stack Functions

void createStack(StackPtr *st) {
    *st = (StackPtr)malloc(sizeof(struct Stack));

    if (*st == NULL) {
        printf("Memory Allocation failed \n");
        exit(EXIT_FAILURE);
    }
    
    (*st)->rear = NULL;
}

void push(StackPtr *st, NodePtr data) {
    ESPtr newS = (ESPtr)malloc(sizeof(struct ElementOfStack));

    if (newS == NULL) {
        printf("Stack is FULL");
        exit(EXIT_FAILURE);
    }

    newS->data = data;
    newS->prev = NULL;

    newS->prev = (*st)->rear;
    (*st)->rear = newS;
}

NodePtr pop(StackPtr st) {
    if(isEmptyStack(st)) {

        printf("Stack is EMPTY");
        return NULL;

    } else {
        NodePtr data = st->rear->data;
        ESPtr toDelete = st->rear;
        st->rear = st->rear->prev;

        free(toDelete);
        return data;
    }
}

bool isEmptyStack(StackPtr st) {
    return  st->rear == NULL;
}

NodePtr peek(StackPtr st) {
    if (isEmptyStack) {
        printf("Stack is EMPTY\n");
        return NULL;
    }
    return st->rear->data;
}
