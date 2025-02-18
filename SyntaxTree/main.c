#include "syntaxTree.h"
#include <stdio.h>
#include "test.h"

int main(void) {
    if (!(incorrectTest() && correctTest())) {
        printf("tests failed!");
        return -1;
    }
    FILE* file = fopen("FileForTree.txt", "r");
    if (!file) {
        printf("Failed to open file!");
        return 1;
    }

    Node* root = splitArithmeticExpression(file);
    fclose(file);

    printf("Tree: ");
    printTree(root);
    printf("\n");

    int errorCode = 0;
    int resulOfCalculation = calculation(root, errorCode);
    if (errorCode == -1) {
        printf("node is empty!");
        return -1;
    }
    printf("resulOfCalculation: %d", resulOfCalculation);

    freeTree(root);
    return 0;
}