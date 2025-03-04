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

Node* parseFile(FILE* file);

Node* parseOperand(FILE* file) {
    int ch = getc(file);
    while (ch == ' ') { 
        ch = getc(file);
    }

    int number = 0;
    ungetc(ch, file);
    if (ch == '(') {
        return parseFile(file);
    }
    else {
        fscanf(file, "%d", &number);
        return createNode('\0', number);
    }
}

Node* parseFile(FILE* file) {
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

    if (root->leftChild == NULL) {
        return NULL;
    }

    root->rightChild = parseOperand(file);

    if (root->rightChild == NULL) {
        return NULL;
    }

    ch = getc(file);

    if (ch != ')') {
        return NULL;
    }

    return root;
}

Node* parseFileName(const char* fileName, int* errorCode) {
    FILE* file = fopen(fileName, "r");
    if (file == NULL) {
        *errorCode = -2;
        return NULL;
    }
    Node* root = parseFile(file);
    fclose(file);
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

int calculate(Node* node, int* errorCode) {
    if (node == NULL) {
        *errorCode = -1;
        return -1;
    }
    if (node->leftChild == NULL && node->rightChild == NULL) {
        return node->number;
    }

    int leftValue = calculate(node->leftChild, errorCode);
    if (*errorCode == -1) {
        return -1;
    }
    int rightValue = calculate(node->rightChild, errorCode);
    if (*errorCode == -1) {
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
        *errorCode = -3;
        return -1;
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