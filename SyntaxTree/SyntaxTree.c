#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "SyntaxTree.h"

NodeValue createValue(const char* value) {
    char* newValue = malloc(strlen(value) + 1);
    if (newValue != NULL) {
        strcpy(newValue, value);
    }
    NodeValue nodeValue = { .value = newValue };
    return nodeValue;
}

Node* createNode(NodeValue value) {
    Node* node = calloc(1, sizeof(Node));
    node->value = value;
    return node;
}

void addLeftChild(Node* node, Node* child) {
    node->leftChild = child;
}

void addRightChild(Node* node, Node* child) {
    node->rightChild = child;
}

void printTree(Node* node) {
    if (node == NULL) {
        return;
    }
    printf("%s ", node->value);
    printTree(node->leftChild);
    printTree(node->rightChild);
}
