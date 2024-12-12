#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "Tree.h"
#include "Tests.h"

bool testInsertNode() {
    Node* root = NULL;
    root = insertNode(root, "key1", "value1");
    root = insertNode(root, "key2", "value2");
    root = insertNode(root, "key3", "value3");
    root = insertNode(root, "key", "value");

    bool result = (strcmp(root->key, "key2") == 0 && strcmp(root->rightChild->key, "key3") == 0 && strcmp(root->leftChild->key, "key") == 0 && strcmp(root->leftChild->leftChild->key, "key1") == 0);
    freeTree(root);
    
    if (!result) {
        printf("Error ar InsertNode\n");
    }
    return result;
}

bool testFindNode() {
    Node* root = NULL;
    root = insertNode(root, "key1", "value1");
    root = insertNode(root, "key2", "value2");
    root = insertNode(root, "key3", "value3");
    root = insertNode(root, "key", "value");

    Node* found0 = findNode(root, "key");
    Node* found1 = findNode(root, "key1");
    Node* found2 = findNode(root, "key2");
    Node* found3 = findNode(root, "key3");

    bool result = (strcmp(found0, "value") == 0 && strcmp(found1, "value1") == 0 && strcmp(found2, "value2") && strcmp(found3, "value3"));
    freeTree(root);

    if (!result) {
        printf("Error at FindNode\n");
    }
    return result;
}

bool testDeleteNodeWithRightRotation() {
    Node* root = NULL;
    root = insertNode(root, "key4", "value4");
    root = insertNode(root, "key3", "value3");
    root = insertNode(root, "key2", "value2");
    root = insertNode(root, "key1", "value1");

    root = deleteNode(root, "key1");

    if (abs(getBalance(root) <= 1)) {
        freeTree(root);
        return true;
    }
    freeTree(root);

    printf("Error at RightRotation\n");
    return false;
}

bool testDeleteNodeWithLeftRotation() {
    Node* root = NULL;
    root = insertNode(root, "key4", "value4");
    root = insertNode(root, "key3", "value3");
    root = insertNode(root, "key2", "value2");
    root = insertNode(root, "key1", "value1");

    root = deleteNode(root, "key1");

    if (abs(getBalance(root) <= 1)) {
        freeTree(root);
        return true;
    }
    freeTree(root);
    printf("Error at leftRotation\n");
    return false;
}

bool allTests() {
    return (testInsertNode() && testFindNode() && testDeleteNodeWithRightRotation() && testDeleteNodeWithLeftRotation());
}