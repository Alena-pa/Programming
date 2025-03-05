#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "syntaxTree.h"
#include "test.h"

bool correctTest(void) {
    int correctAnswer = 4;
    int errorCode = 0;
    
    Node* root = parseFileName("fileCorrectTest.txt", &errorCode);
    if (errorCode == -2) {
        printf("unable to open main file\n");
    }

    if (root == NULL) {
        printf("root is empty\n");
        return false;
    }

    printf("test tree: ");
    printTree(root);
    printf("\n");

    int resulOfCalculation = calculate(root, &errorCode);
    if (errorCode == -1) {
        printf("node is empty!");
        freeTree(root);
        return false;
    }
    if (errorCode == -3) {
        printf("Unknown operation in file");
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
    int* errorCode = 0;
    Node* root = parseFileName("fileIncorrectTest.txt", &errorCode);

    if (errorCode == -2) {
        printf("unable to open main file\n");
    }

    if (root != NULL) {
        return false;
    }

    return true;
}