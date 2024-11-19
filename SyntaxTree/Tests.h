#pragma once

#include <stdio.h>

typedef struct NodeValue {
    char* value;
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

Node *buildTreeFromFile(FILE* file);

void printTree(Node* node);

int calculation(Node* node);

void freeTree(Node* node);
