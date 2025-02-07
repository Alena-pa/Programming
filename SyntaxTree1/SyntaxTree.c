#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "syntaxTree.h"

typedef struct Node {
    const char* value;
    Node* leftChild;
    Node* rightChild;
} Node;

Node* createNode(char* value) {
    Node* node = calloc(1, sizeof(Node));
    if (node == NULL) {
        return NULL;
    }
    node->value = strdup(value);
    if (node->value == NULL) {
        return NULL;
    }
    return node;
}

const char* getNodeValue(Node* node) {
    if (node == NULL) {
        return NULL;
    }
    return node->value;
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

Node* buildSyntaxTree(const char* string, int* indexOfString) {
    if (string[*indexOfString] == '\0') {
        return NULL;
    }

    while (string[*indexOfString] == '(' || string[*indexOfString] == ')' || string[*indexOfString] == ' ') {
        (*indexOfString)++;
    }

    char* value = calloc(30, sizeof(char));
    if (value == NULL) {
        return NULL;
    }

    int i = 0;
    while (48 <= string[*indexOfString] && string[*indexOfString] <= 57) {
        value[i] = string[*indexOfString];
        i++;
        (*indexOfString)++;
    }

    if (i > 0) {
        return createNode(value);
    }

    else if (string[*indexOfString] == '+' || string[*indexOfString] == '-' || string[*indexOfString] == '*' || string[*indexOfString] == '/') {
        char operator[2] = {string[*indexOfString], '\0'};
        Node* node = createNode(operator);
        (*indexOfString)++;

        printf("Operator: %s\n", operator);
        node->leftChild = buildSyntaxTree(string, indexOfString);
        node->rightChild = buildSyntaxTree(string, indexOfString);
        return node;
    }
    
    return NULL;
}

void printTree(Node* node) {
    if (node == NULL) {
        return;
    }
    printf("%s ", node->value);
    printTree(node->leftChild);
    printTree(node->rightChild);
}

int calculation(Node* node) {
    if (node->leftChild == NULL && node->rightChild == NULL) {
        return atoi(node->value);
    }

    int leftValue = calculation(node->leftChild);
    int rightValue = calculation(node->rightChild);

    switch (node->value[0]) {
    case '+':
        return leftValue + rightValue;
    case '-':
        return leftValue - rightValue;
    case '*':
        return leftValue * rightValue;
    case '/':
        return leftValue / rightValue;
    default:
        printf("Unknown operation: %s\n", node->value);
    }
}

void freeTree(Node* node) {
    if (node == NULL) {
        return;
    }
    freeTree(node->leftChild);
    freeTree(node->rightChild);
    free(node->value);
    free(node);
}