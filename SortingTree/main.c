#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "Tree.h"
#include "Tests.h"

typedef struct Node {
    NodeValue value;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

int main(void) {
    if (!allTests()) {
        printf("Tests failed!");
        return 1;
    }

    Node *root = NULL;

    printf("Instruction to  the programm:\n");
    printf("End the programm: 0\n");
    printf("Add a value for a given key to a dictionary: 1\n");
    printf("Get a value for a given key from a dictionary: 2\n");
    printf("Check the presence of a given key in the dictionary: 3\n");
    printf("Remove a given key and its associated value from a dictionary: 4\n");

    int operationNumber = 5;
    int key = 0;
    char value[100];
    while (operationNumber != 0) {
        printf("Enter operation number: ");
        scanf("%d", &operationNumber);

        switch (operationNumber)
        {
        case 0:
            deleteTree(root);
            return 0;
        case 1: {
            printf("Enter key: ");
            scanf("%d", &key);
            printf("Enter value: ");
            scanf("%s", &value, sizeof(value));
            NodeValue newValue = createValue(key, value);
            if (newValue.value == NULL) {
                printf("Error, can`t create value\n");
                return -1;
            }
            if (!root) {
                root = createNode(newValue);
            }
            else {
                bool result = addElement(root, newValue);
                if (!result) {
                    printf("Error, can`t add element, try again");
                    break;
                }
            }
            printf("Value added\n");
            break;
        }
        case 2: {
            printf("Enter search key: ");
            scanf("%d", &key);
            if (root) {
                Node* resultOfSearching = findNodeByKey(root, key);
                if (resultOfSearching) {
                    printf("Value: %s\n", resultOfSearching->value.value);
                }
                else {
                    printf("Value not found");
                }
            }
            else {
                printf("Tree is empty, press 1 to add smth\n");
            }
            break;
        }
        case 3:
            printf("Enter your verification key: ");
            scanf("%d", &key);
            if (root) {
                if (existenceOfElementByKey(root, key)) {
                    printf("Value exists\n");
                }
                else {
                    printf("Value doesn`t exists");
                }
            }
            else {
                printf("Tree is empty, press 2 to add smth\n");
            }
            break;
        case 4:
            printf("Enter the key to delete: ");
            scanf("%d", &key);
            if (root) {
                deleteElementByKey(root, key);
                printf("Value deleted\n");
            }
            else {
                printf("Tree is empty, press 1 to add smth\n");
            }
            break;
        default:
            printf("Incorrect operation number. Try again\n");
        }
    }   
}