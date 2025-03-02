#include "syntaxTree.h"
#include <stdio.h>
#include "test.h"

int main(void) {
    if (!(incorrectTest() && correctTest())) {
        printf("tests failed!");
        return -1;
    }
    Node* root = parseFile("file.txt");
    if (root == NULL) {
        return -1;
    }

    printf("Tree: ");
    printTree(root);
    printf("\n");

    int errorCode = 0;
    int resulOfCalculation = calculate(root, errorCode);
    if (errorCode == -1) {
        freeTree(root);
        printf("node is empty!");
        return -1;
    }
    printf("resulOfCalculation: %d", resulOfCalculation);

    freeTree(root);
    return 0;
}