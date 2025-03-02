#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "syntaxTree.h"
#include "test.h"

bool correctTest(void) {
    int correctAnswer = 4;

    Node* root = parseFile("fileForFirstTest.txt");

    printf("test tree: ");
    printTree(root);
    printf("\n");

    int errorCode = 0;
    int resulOfCalculation = calculate(root, errorCode);
    if (errorCode == -1) {
        printf("node is empty!");
        freeTree(root);
        return false;
    }
    if (resulOfCalculation != correctAnswer) {
        printf("incorrect resul of calculation: %d", resulOfCalculation);
        freeTree(root);
        return false;
    }
    
    freeTree(root);
    return true;
}

bool incorrectTest(void) {
    Node* root = parseFile("fileForSecondTest.txt");

    if (root != NULL) {
        return false;
    }
    return true;
}