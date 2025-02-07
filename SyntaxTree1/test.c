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
        printf("Test failed: tree is empty\n");
        return false;
    }

    int result = calculation(tree);
    if (result != -3) {
        printf("Test failed: incorrect calculation result, expected -3 but got %d\n", result);
        freeTree(tree);
        return false;
    }

    freeTree(tree);
    printf("Test passed successfully!\n");
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