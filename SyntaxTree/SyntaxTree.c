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
    int ch;
    while (isspace(ch = getc(file))) {}

    int number = 0;
    ungetc(ch, file);
    if (ch == '(') {
        return splitArithmeticExpression(file);
    }
    else {
        fscanf(file, "%d", &number);
        return createNode(NULL, number);
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
    Node* root = createNode(ch, NULL);
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
    printf("%s ", node->operation);
    printTree(node->leftChild);
    printTree(node->rightChild);
}

int calculation(Node* node) {
    if (node == NULL) {
        return NULL;
    }
    if (node->leftChild == NULL && node->rightChild == NULL) {
        return node->number;
    }

    int leftValue = calculation(node->leftChild);
    int rightValue = calculation(node->rightChild);

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
    free(node->operation);
    free(node->number);
    free(node);
}