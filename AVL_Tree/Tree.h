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

struct Node* createNode(const char* key, const char* value);

struct Node* rightRotate(struct Node* node);

struct Node* leftRotate(struct Node* node);

struct Node* addNode(struct Node* root, const char* key, const char* value);

struct Node* findNode(struct Node* root, const char* key);

struct Node* getMinNode(struct Node* node);

struct Node* deleteNode(struct Node* root, const char* key);