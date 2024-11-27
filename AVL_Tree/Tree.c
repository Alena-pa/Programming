#include <stdio.h>
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

}

struct Node* rightRotate(struct Node* node);

struct Node* leftRotate(struct Node* node);

struct Node* addNode(struct Node* root, const char* key, const char* value);

struct Node* findNode(struct Node* root, const char* key);

struct Node* getMinNode(struct Node* node);

struct Node* deleteNode(struct Node* root, const char* key);