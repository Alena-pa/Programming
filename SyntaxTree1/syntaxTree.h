#pragma once

typedef struct Node Node;

typedef struct NodeValue NodeValue;

// Creates a node value
NodeValue createValue(const char* value);

// Returns the value of the node
char* getNodeValue(Node* node);

// Returns the left child of the node
Node* getLeftChild(Node* node);

// Returns the right child of the node
Node* getRightChild(Node* node);

// Creates a new node with the given value
Node* createNode(char* value);

// Skips whitespace and brackets in the string
void skipWhitespaceAndBrackets(const char* string, int* index);

// Builds a syntax tree from the given expression
Node* buildSyntaxTree(const char* value, int* index);

// Prints the syntax tree
void printTree(Node* node);

// Calculates the result based on the syntax tree
int calculation(Node* node);

// Frees memory allocated for the syntax tree
void freeTree(Node* node);