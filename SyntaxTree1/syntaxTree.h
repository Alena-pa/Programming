#pragma once

typedef struct Node Node;

typedef struct NodeValue NodeValue;

NodeValue createValue(const char* value);

Node* createNode(NodeValue* value);

void skipWhitespaceAndBrackets(const char* string, int* index);

Node* buildSyntaxTree(const char* value, int* index);

void printTree(Node* node);

int calculation(Node* node);

void freeTree(Node* node);