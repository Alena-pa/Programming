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

void addLeftChild(Node* node, Node* child);

void addRightChild(Node* node, Node* child);

void skipWhitespaceAndBrackets(const char* string, int* index);

Node* modifyString(const char* value);

void printTree(Node* node);

int calculation(Node* node);

void freeTree(Node* node);