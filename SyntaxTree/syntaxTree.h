#pragma once
#include <stdio.h>

typedef struct Node Node;

// Get left child
Node* getLeftChild(Node* node);

// Get right child
Node* getRightChild(Node* node);

// Remove tree
void freeTree(Node* node);

// Fill a parse tree with an arithmetic expression
Node* splitArithmeticExpression(FILE *file);

// Print tree
void printTree(Node* node);

// Calculate the value of an expression by traversing a tree
int calculation(Node* node, int* errorCode);