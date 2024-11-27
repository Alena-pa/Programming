#include <stdio.h>
#include <stdlib.h>
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

struct Node* createNode(const char* key, const char* value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->height = 1;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

struct Node* rightRotate(struct Node* node) {
    Node* leftChild = node->leftChild;
    Node* subTree = leftChild->rightChild;

    leftChild->rightChild = node;
    node->leftChild = subTree;

    if (getHeight(node->leftChild) > getHeight(node->rightChild)) {
        node->height = 1 + getHeight(node->leftChild);
    }
    else {
        node->height = 1 + getHeight(node->rightChild);
    }
}

struct Node* leftRotate(struct Node* node);

struct Node* addNode(struct Node* root, const char* key, const char* value);

struct Node* findNode(struct Node* root, const char* key);

struct Node* getMinNode(struct Node* node);

struct Node* deleteNode(struct Node* root, const char* key);