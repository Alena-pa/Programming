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

char* getNodeValue(Node* node) {
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

void skipWhitespaceAndBrackets(const char* string, int* index) {
    while (string[*index] == '(' || string[*index] == ')' || string[*index] == ' ') {
        (*index)++;
    }
}

char* readNumber(const char* string, int* indexOfString) {
    char* number = calloc(30, sizeof(char));
    if (number == NULL) {
        return NULL;
    }
    int indexOfNumber = 0;

    if (string[*indexOfString - 1] == '-') {
        number[indexOfNumber] = string[*indexOfString];
        (*indexOfString)++;
    }

    while (isdigit(string[*indexOfString])) {
        number[indexOfNumber] = string[*indexOfString];
        (*indexOfString)++;
    } 
    number[indexOfNumber] = '\0';
    return number;
}

Node* buildSyntaxTree(const char* string, int* indexOfString) {
    if (string[*indexOfString] == '\0') {
        return NULL;
    }

    skipWhitespaceAndBrackets(string, indexOfString);

    if (isdigit(string[*indexOfString])) {
        char* number = readNumber(string, indexOfString);
        if (number == NULL) {
            return NULL;
        }
        return createNode(number);
    }

    if (string[*indexOfString] == '+' || string[*indexOfString] == '-' || string[*indexOfString] == '*' || string[*indexOfString] == '/') {
        char operationToCount = string[*indexOfString];
        Node* node = createNode(operationToCount);
        (*indexOfString)++;
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