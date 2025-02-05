#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "syntaxTree.h"
#include "test.h"

bool testBuildSyntaxTree(void) {
    const char* expression = "(1 + 2) * (3 - 4)";
    int index = 0;
    Node* tree = buildSyntaxTree(expression, &index);

    if (tree == NULL) {
        printf("Test 1 failed: tree is empty\n");
        return false;
    }

    char* value = getNodeValue(tree);
    Node* leftChild = getLeftChild(tree);
    Node* rightChild = getRightChild(tree);

    char* leftValue = getNodeValue(leftChild);
    char* rightValue = getNodeValue(rightChild);

    if (strcmp(value, "*") != 0 || strcmp(leftValue, "+") != 0 || strcmp(rightValue, "-") != 0) {
        printf("Test 1 failed: incorrect result\n");
        freeTree(tree);
        return false;
    }

    freeTree(tree);
    return true;
}

bool testCalculation(void) {
    const char* expression = "(1 + 2) * (3 - 4)";
    int index = 0;
    Node* tree = buildSyntaxTree(expression, &index);

    int result = calculation(tree);
    if (result != -3) {
        printf("Test 2 failed\n");
        freeTree(tree);
        return false;
    }

    freeTree(tree);
    return true;
}

bool testNegativeNumbers(void) {
    const char* expression = "(-1 + 2)*(- 3 - 4)";
    int index = 0;
    Node* tree = buildSyntaxTree(expression, &index);

    int result = calculation(tree);
    if (result != 35) {
        printf("Test 3 failed\n");
        freeTree(tree);
        return false;
    }

    freeTree(tree);
    return true;
}

bool testInvalidExpression(void) {
    const char* expression = "1 + * 2";
    int index = 0;
    Node* tree = buildSyntaxTree(expression, &index);

    if (tree != NULL) {
        printf("Test 4 failed\n");
        freeTree(tree);
        return false;
    }

    return true;
}

bool allTests(void) {
    return (testBuildSyntaxTree() && testCalculation() && testNegativeNumbers() && testInvalidExpression());
}