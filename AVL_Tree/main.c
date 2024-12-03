#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Tests.h"
#include "Tree.h"


int main(void) {
    if (!allTests) {
        return -1;
    }
    Node* root = NULL;

    printf("Instruction to programm:\n");
    printf("0 - exit\n");
    printf("1 - add value by key\n");
    printf("2 - get value by key\n");
    printf("3 - check the presence of the given key\n");
    printf("4 - delete value and key\n");

    int numberOfOperation = -1;
    char key[100];
    char value[100];

    while (numberOfOperation != 0) {
        printf("Enter the operation number: ");
        scanf("%d", &numberOfOperation);

        switch (numberOfOperation) {
            case 0:
                freeTree(root);
                printf("Exit the programm\n");
                return 0;
            case 1:
                printf("Enter key to add: ");
                scanf("%s", key);

                printf("Enter value to add: ");
                scanf("%s", value);

                root = insertNode(root, key, value);
                printf("Added successfully\n");
                break;
            case 2:
                printf("Enter key to found: ");
                scanf("%s", key);
                const char* foundValue = getValue(root, key);

                if (foundValue != NULL) {
                    printf("Value found: %s\n", foundValue);
                }
                else {
                    printf("Value not found =(\n");
                }
                break;
            case 3:
                printf("Enter key to found: ");
                scanf("%s", key);

                if (findNode(root, key) != NULL) {
                    printf("Value exists\n");
                }
                else {
                    printf("Value not found =(\n");
                }
                break;
            case 4:
                printf("Enter key to delete: ");
                scanf("%s", key);

                if (findNode(root, key) != NULL) {
                    root = deleteNode(root, key);
                    printf("Key and Value deleted\n");
                }
                else {
                    printf("Nothing to delete\n");
                }
                break;
            default:
                printf("Invalid operation! Enter a number 0-4\n");
                break;
        }
    }
}