#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "syntaxTree.h"

typedef struct Node {
    char operation;
    int number;
    Node* leftChild;
    Node* rightChild;
} Node;

Node* createNode(char operation, int number) {
    Node* node = calloc(1, sizeof(Node));
    if (node == NULL) {
        return NULL;
    }
    node->operation = operation;
    node->number = number;
    return node;
}

Node* getLeftChild(Node* node) {
    if (node == NULL) {
        return NULL;
    }
    return node->leftChild;
}

Node* getRightChild(Node* node) {
    if (node == NULL) {
        return NULL;
    }
    return node->rightChild;
}


bool isOperation(char value) {
    return value == '+' || value == '*' || value == '/' || value == '-';
}

Node* parseOperand(FILE* file) {
    int ch = getc(file);
    while (ch == ' ') { 
        ch = getc(file);
    }

    int number = 0;
    ungetc(ch, file);
    if (ch == '(') {
        return splitArithmeticExpression(file);
    }
    else {
        fscanf(file, "%d", &number);
        return createNode('\0', number);
    }
}

Node* splitArithmeticExpression(FILE* file) {
    int ch = getc(file);
    if (ch != '(') {
        return NULL;
    }
    ch = getc(file);
    if (!isOperation(ch)) {
        return NULL;
    }
    Node* root = createNode(ch, 0);
    root->leftChild = parseOperand(file);
    root->rightChild = parseOperand(file);

    ch = getc(file);
    if (ch != ')') {
        return NULL;
    }
    return root;
}

void printTree(Node* node) {
    if (node == NULL) {
        return;
    }
    if (node->operation == '\0') {
        printf("%d ", node->number);
    }
    else {
        printf("%c ", node->operation);
    }
    printTree(node->leftChild);
    printTree(node->rightChild);
}

int calculation(Node* node, int* errorCode) {
    if (node == NULL) {
        *errorCode = -1;
        return -1;
    }
    if (node->leftChild == NULL && node->rightChild == NULL) {
        return node->number;
    }

    int leftValue = calculation(node->leftChild, errorCode);
    if (errorCode == -1) {
        return -1;
    }
    int rightValue = calculation(node->rightChild, errorCode);
    if (errorCode == -1) {
        return -1;
    }

    switch (node->operation) {
    case '+':
        return leftValue + rightValue;
    case '-':
        return leftValue - rightValue;
    case '*':
        return leftValue * rightValue;
    case '/':
        return leftValue / rightValue;
    default:
        printf("Unknown operation: %s\n", node->operation);
    }
}

void freeTree(Node* node) {
    if (node == NULL) {
        return;
    }
    freeTree(node->leftChild);
    freeTree(node->rightChild);
    free(node);
}