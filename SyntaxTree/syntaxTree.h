#pragma once
#include <stdio.h>

typedef struct Node Node;
// Remove tree
void freeTree(Node* node);

// open file and parse it
Node* parseFileName(const char* fileName, int* errorCode);

// Print tree
void printTree(Node* node);

// Calculate the value of an expression by traversing a tree
int calculate(Node* node, int* errorCode);