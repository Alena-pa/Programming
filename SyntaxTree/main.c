#include "syntaxTree.h"
#include <stdio.h>
#include "test.h"

int main(int argc, char** argv) {
    printf("%d\n", argc);
    for (size_t i = 0; i < argc; i++)
    {
        printf("%s\n", argv[i]);
    }

    if (argc == 2 && !strcmp(argv[1], "--test")) {
        if (!incorrectTest()) {
            printf("Incorrect test failed!");
            return -1;
        }
        if (!correctTest()) {
            printf("Correct test failed!");
            return -1;
        }
        printf("tests succeded");
        return 0;
    }
    int errorCode = 0;
    Node* root = parseFileName("file.txt", errorCode);
    if (errorCode == -2) {
        printf("unable to open main file\n");
    }
    if (root == NULL) {
        return -1;
    }

    printf("Tree: ");
    printTree(root);
    printf("\n");

    int resulOfCalculation = calculate(root, &errorCode);
    if (errorCode == -1) {
        freeTree(root);
        printf("node is empty!");
        return -1;
    }
    if (errorCode == -3) {
        freeTree(root);
        printf("Unknown operation in file");
        return -1;
    }
    printf("resulOfCalculation: %d", resulOfCalculation);

    freeTree(root);
    return 0;
}