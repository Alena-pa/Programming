#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "syntaxTree.h"
#include "test.h"

typedef struct Node {
    const char* value;
    Node* leftChild;
    Node* rightChild;
} Node;


bool testBuildSyntaxTree() {
    const char* expression = "(1+2)*(3-4)";
    int index = 0;
    Node* tree = buildSyntaxTree(expression, &index);

    if (tree == NULL) {
        printf("Test 1 failed\n");
        return false;
    }

    if (strcmp(tree->value, "*") != 0 || strcmp(tree->leftChild->value, "+") != 0 || strcmp(tree->rightChild->value, "-") != 0) {
        printf("Test 1 failed\n");
        freeTree(tree);
        return false;
    }

    freeTree(tree);
    return true;
}

bool testCalculation() {
    const char* expression = "(1+2)*(3-4)";
    int index = 0;
    Node* tree = buildSyntaxTree(expression, &index);

    int result = calculation(tree);
    if (result != -3) {
        printf("Test 2 failed");
        freeTree(tree);
        return false;
    }

    freeTree(tree);
    return true;
}

bool testNegativeNumbers() {
    const char* expression = "(-1+2)*(-3-4)";
    int index = 0;
    Node* tree = buildSyntaxTree(expression, &index);

    int result = calculation(tree);
    if (result != 35) {
        printf("Test 3 failed");
        freeTree(tree);
        return false;
    }

    freeTree(tree);
    return true;
}

bool testInvalidExpression() {
    const char* expression = "1+*2";
    int index = 0;
    Node* tree = buildSyntaxTree(expression, &index);

    if (tree != NULL) {
        printf("Test 4 failed");
        freeTree(tree);
        return false;
    }

    return true;
}

bool allTests() {
    return (testBuildSyntaxTree() && testCalculation() && testNegativeNumbers() && testInvalidExpression());
}