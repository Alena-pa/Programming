#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tree.h"

typedef struct Node {
    const char* key;
    const char* value;
    int height;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

int getHeight(struct Node* node) {
    if (!node) {
        return 0;
    }
    return node->height;
}

int getBalance(struct Node* node) {
    if (!node) {
        return 0;
    }
    return getHeight(node->rightChild) - getHeight(node->rightChild);
}

void updateHeight(struct Node* node) {
    char leftHeight = getHeight(node->leftChild);
    char rightHeight = getHeight(node->rightChild);
    if (rightHeight > leftHeight) {
        node->height = rightHeight + 1;
    }
    else {
        node->height = leftHeight + 1;
    }
}

struct Node* rightRotate(struct Node* node) {
    Node* newRoot = node->leftChild;

    node->leftChild = newRoot->rightChild;
    newRoot->rightChild = node;

    updateHeight(node);
    updateHeight(newRoot);

    return newRoot;
}

struct Node* leftRotate(struct Node* node) {
    Node* newRoot = node->rightChild;

    node->rightChild = newRoot->leftChild;
    newRoot->leftChild = node;

    updateHeight(node);
    updateHeight(newRoot);

    return newRoot;
}

int maxValue(int first, int second) {
    if (first > second) {
        return first;
    }
    return second;
}

struct Node* balance(struct Node* node) {
    updateHeight(node);
    int balanceFactor = getBalance(node);
    if (balanceFactor == 2) {
        if (getBalance(node->rightChild) < 0) {
            node->rightChild = rightRotate(node->rightChild);
        }
        return leftRotate(node);
    }

    if (balanceFactor == -2) {
        if (getBalance(node->leftChild) > 0) {
            node->leftChild = leftRotate(node->leftChild);
        }
        return rightRotate(node);
    }

    return node;
}
struct Node* insert(struct Node* node, const char* key, const char* value) {
    if (node == NULL) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL) {
            return NULL;
        }

        newNode->leftChild = NULL;
        newNode->rightChild = NULL;
        newNode->key = strdup(key);
        newNode->value = strdup(value);
        newNode->height = 1;
        return newNode;
    }
    if (strcmp(key, node->key) < 0) {
        node->leftChild = insert(node->leftChild, key, value);
    }
    else if (strcmp(key, node->key) > 0) {
        node->rightChild = insert(node->rightChild, key, value);
    }
    else {
        return node;
    }
    node->height = 1 + maxValue(getHeight(node->leftChild), getHeight(node->leftChild));

    int balance = getBalance(node);

    if (balance > 1 && strcmp(key, node->leftChild->key) < 0) {
        return rightRotate(node);
    }

    if (balance < -1 && strcmp(key, node->rightChild->key) > 0) {
        return leftRotate(node);
    }

    if (balance > 1 && strcmp(key, node->leftChild->key) > 0) {
        node->leftChild = leftRotate(node->leftChild);
        return rightRotate(node);
    }

    if (balance < -1 && strcmp(key, node->rightChild->key) < 0) {
        node->rightChild = rightRotate(node->rightChild);
        return leftRotate(node);
    }

    return node;
}

struct Node* insertNode(struct Node* root, const char* key, const char* value) {
    if (root == NULL) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        if (newNode == NULL) {
            return NULL;
        }

        newNode->leftChild = NULL;
        newNode->rightChild = NULL;
        newNode->key = strdup(key);
        newNode->value = strdup(value);
        newNode->height = 1;
        return newNode;
    }

    if (strcmp(key, root->key) < 0) {
        root->leftChild = insertNode(root->leftChild, key, value);
    }
    else {
        if (strcmp(key, root->key) > 0) {
            root->rightChild = insertNode(root->rightChild, key, value);
        }
        else {
            root->value = strdup(value);
            return root;
        }
    }

    return balance(root);
}

struct Node* findNode(struct Node* root, const char* key) {
    if (root == NULL || strcmp(root->key, key) == 0) {
        return root;
    }

    if (strcmp(key, root->key) < 0) {
        return findNode(root->leftChild, key);
    }
    else {
        return findNode(root->rightChild, key);
    }
}

struct Node* getMinNode(struct Node* node) {
    while (node->leftChild != NULL) {
        node = node->leftChild;
    }
    return node;
}

struct Node* deleteNode(struct Node* root, const char* key) {
    if (root == NULL)
        return root;

    if (strcmp(key, root->key) < 0) {
        root->leftChild = deleteNode(root->leftChild, key);
    }

    else if (strcmp(key, root->key) > 0) {
        root->rightChild = deleteNode(root->rightChild, key);
    }

    else {
        if ((root->leftChild == NULL) || (root->rightChild == NULL)) {
            Node* temp = NULL;
            if (root->rightChild) {
                Node* temp = root->leftChild;
            }
            else {
                Node* temp = root->rightChild;
            }
            
            if (temp == NULL) {
                temp = root;
                root = NULL;
            }
            else {
                *root = *temp;
            }
            free(temp);
        }
        else {
            struct Node* temp = getMinNode(root->rightChild);
            root->key = temp->key;
            root->rightChild = deleteNode(root->rightChild, temp->key);
        }
    }

    if (root == NULL) {
        return root;
    }
    root->height = 1 + maxValue(getHeight(root->leftChild), getHeight(root->rightChild));
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->leftChild) >= 0) {
        return rightRotate(root);
    }
    if (balance > 1 && getBalance(root->leftChild) < 0) {
        root->leftChild = leftRotate(root->leftChild);
        return rightRotate(root);
    }
    if (balance < -1 && getBalance(root->rightChild) <= 0) {
        return leftRotate(root);
    }
    if (balance < -1 && getBalance(root->rightChild) > 0) {
        root->rightChild = rightRotate(root->rightChild);
        return leftRotate(root);
    }

    return root;
}

const char* getValue(struct Node* root, const char* key) {
    struct Node* node = findNode(root, key);
    return node != NULL ? node->value : NULL;
}

void freeTree(struct Node* node) {
    if (node != NULL) {
        freeTree(node->leftChild);
        freeTree(node->rightChild);
        free(node->key);
        free(node->value);
        free(node);
    }
}