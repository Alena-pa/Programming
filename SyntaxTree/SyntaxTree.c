#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>
#include "SyntaxTree.h"

NodeValue createValue(const char* value) {
    char* newValue = malloc(strlen(value) + 1);
    if (newValue != NULL) {
        strcpy(newValue, value);
    }
    NodeValue nodeValue = { .value = newValue };
    return nodeValue;
}

Node* createNode(NodeValue *value) {
    Node* node = calloc(1, sizeof(Node));
    node->value = *value;
    return node;
}

void addLeftChild(Node* node, Node* child) {
    node->leftChild = child;
}

void addRightChild(Node* node, Node* child) {
    node->rightChild = child;
}

void skipWhitespaceAndBrackets(const char* string, int* index) {
    while (string[*index] == '(' || string[*index] == ')' || string[*index] == ' ') {
        (*index)++;
    }
}

char* readNumber(const char* string, int* indexOfString) {
    char number[20];
    int indexOfNumber = 0;
    while (isdigit(string[*indexOfString])) {
        number[indexOfNumber] = string[*indexOfString];
        (*indexOfString)++;
    }
    number[indexOfNumber] = '\0';
    return number;
}

Node* modifyString(const char* string, int* indexOfString) {
    if (string[*indexOfString] == '\0') {
        return NULL;
    }

    if (isdigit(string[*indexOfString])) {
        char* number = readNumber(string, indexOfString);
        return createNode(number);
    }

    if (string[*indexOfString] == '+' || string[*indexOfString] == '-' || string[*indexOfString] == '*' || string[*indexOfString] == '/') {
        char operationToCount = string[*indexOfString];
        Node* node = createNode(operationToCount);
        indexOfString++;
        node->leftChild = modifyString(string, indexOfString);
        node->rightChild = modifyString(string, indexOfString);
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
        return atoi(node->value.value);
    }

    int indexOfString = 0;
    int leftValue = modifyString(node->leftChild, indexOfString);
    int rightValue = modifyString(node->rightChild, indexOfString);

    switch (node->value.value[0]) {
        case '+':
            return leftValue + rightValue;
        case '-':
            return leftValue - rightValue;
        case '*':
            return leftValue * rightValue;
        case '/':
            return leftValue / rightValue;
        default:
            printf("Unknown operation: %s\n", node->value.value);
    }
}

void freeTree(Node* node) {
    if (node == NULL) {
        return;
    }
    freeTree(node->leftChild);
    freeTree(node->rightChild);
    free(node->value.value);
    free(node);
}