#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "SyntaxTree.h"
#include "Tests.h"

bool testCreateNode() {
    NodeValue value = createValue("1");
    Node* node = createNode(value);
    return (strcmp(node->value.value, "1") == 0 && node->leftChild == NULL && node->rightChild == NULL);
}

bool testTreeBuilding() {
    const char* testString = "(* (+ 1 1) 2)";
    int index = 0;
    Node* node = modifyString(testString, &index);

    return (node->value.value == "*") && (node->leftChild->value.value == "+") && (node->leftChild->leftChild->value.value == "1") &&
        (node->leftChild->rightChild->value.value == "1") && (node->rightChild->value.value == "2");
}

bool testCalculation() {
    const char* testString = "(* (+ 1 1) 2)";
    int index = 0;
    Node* node = modifyString(testString, &index);

    int resultOfCalculation = calculation(node);
    return resultOfCalculation == 4;
}

bool allTests() {
    return (testCreateNode && testCalculation && testTreeBuilding);
}