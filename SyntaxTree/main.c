#include "SyntaxTree.h"
#include <stdio.h>

int main(void) {
    FILE* file = fopen("FileForTree.txt", "r");
    if (!file) {
        printf("Failed to open file!");
        return 1;
    }

    Node* root = modifyString(file);
    fclose(file);

    printf("Tree: ");
    printTree(root);
    printf("\n");

    int resulOfCalculation = calculation(root);
    printf("resulOfCalculation: %d", resulOfCalculation);

    freeTree(root);
    return 0;
}