#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "syntaxTree.h"
#include "test.h"

bool correctTest(void) {
    int correctAnswer = 4;
    int errorCode = 0;
    
    FILE* file = fopen("fileForFirstTest.txt", "r");
    if (!file) {
        printf("Unable to open test file");
        return false;
    }
    Node* root = parseFile(file);
    
    if (root == NULL) {
        printf("root is empty\n");
        fclose(file);
        return false;
    }

    printf("test tree: ");
    printTree(root);
    printf("\n");

    int resulOfCalculation = calculate(root, &errorCode);
    if (errorCode == -1) {
        printf("node is empty!");
        freeTree(root);
        fclose(file);
        return false;
    }
    if (resulOfCalculation != correctAnswer) {
        printf("incorrect resul of calculation: %d", resulOfCalculation);
        freeTree(root);
        fclose(file);
        return false;
    }
    
    freeTree(root);
    fclose(file);
    return true;
}

bool incorrectTest(void) {
    FILE* file = fopen("fileForSecondTest.txt", "r");
    if (!file) {
        printf("Unable to open test file");
        return false;
    }
    Node* root = parseFile(file);

    if (root != NULL) {
        fclose(file);
        return false;
    }

    fclose(file);
    return true;
}