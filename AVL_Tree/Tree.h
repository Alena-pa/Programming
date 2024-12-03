#pragma once

#pragma once

typedef struct Node {
    const char* key;
    const char* value;
    int height;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

int getHeight(struct Node* node);

int getBalance(struct Node* node);

void updateHeight(struct Node* node);

struct Node* rightRotate(struct Node* node);

struct Node* leftRotate(struct Node* node);

struct Node* insertNode(struct Node* root, const char* key, const char* value);

struct Node* findNode(struct Node* root, const char* key);

struct Node* getMinNode(struct Node* node);

struct Node* deleteNode(struct Node* root, const char* key);

const char* getValue(struct Node* root, const char* key);

void freeTree(struct Node* node);
