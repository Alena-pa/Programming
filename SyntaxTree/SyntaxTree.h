#pragma once
#include <stdio.h>

typedef struct Node Node;
// Remove tree
void freeTree(Node* node);

// Fill a parse tree with an arithmetic expression
Node* parseFile(char* nameOfFile, int* errorCode);

// Print tree
void printTree(Node* node);

// Calculate the value of an expression by traversing a tree
int calculate(Node* node, int* errorCode);