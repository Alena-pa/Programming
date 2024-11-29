#pragma once

typedef struct NodeValue {
    const char* value;
} NodeValue;

typedef struct Node {
    NodeValue value;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

NodeValue createValue(const char* value);

Node* createNode(NodeValue value);

void skipWhitespaceAndBrackets(const char* string, int* index);

Node* modifyString(const char* value, int* index);

void printTree(Node* node);

int calculation(Node* node);

void freeTree(Node* node);