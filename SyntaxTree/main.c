#include "SyntaxTree.h"
#include <stdio.h>
#include "Tests.h"

int main(void) {
    if (!allTests) {
        printf("Tests Failed!");
        return 1;
    }
    FILE* file = fopen("FileForTree.txt", "r");
    if (!file) {
        printf("Failed to open file!");
        return 1;
    }

    int index = 0;
    Node* root = modifyString(file, index);
    fclose(file);

    printf("Tree: ");
    printTree(root);
    printf("\n");

    int resulOfCalculation = calculation(root);
    printf("resulOfCalculation: %d", resulOfCalculation);

    freeTree(root);
    return 0;
}