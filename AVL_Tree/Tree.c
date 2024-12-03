#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Tree.h"

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

struct Node* insertNode(struct Node* root, const char* key, const char* value) {
    if (!root) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        if (!newNode) {
            printf("Not enough memory!");
            return 0;
        }
        newNode->leftChild = NULL;
        newNode->rightChild = NULL;
        newNode->key = key;
        newNode->value = value;
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
            root->value = value;
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
    if (root == NULL) {
        return NULL;
    }

    if (strcmp(key, root->key) < 0) {
        root->leftChild = deleteNode(root->leftChild, key);
    }
    else if (strcmp(key, root->key) > 0) {
        root->rightChild = deleteNode(root->rightChild, key);
    }
    else {
        if (root->leftChild == NULL) {
            struct Node* rightChild = root->rightChild;
            free(root->key);
            free(root->value);
            free(root);
            return rightChild;
        }

        struct Node* minNode = getMinNode(root->rightChild);
        root->key = strdup(minNode->key);
        root->value = strdup(minNode->value);
        root->rightChild = deleteNode(root->rightChild, minNode->key);
    }

    return balance(root);
}

const char* getValue(struct Node* root, const char* key) {
    struct Node* node = findNode(root, key);
    if (node != NULL) {
        return node->value;
    }
    else {
        return NULL;
    }
}

void freeTree(struct Node* node) {
    if (!node) {
        freeTree(node->leftChild);
        freeTree(node->rightChild);
        free(node->key);
        free(node->value);
        free(node);
    }

    return;
}