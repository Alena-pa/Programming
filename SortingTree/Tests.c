#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "Tests.h"
#include "Tree.h"

typedef struct Node {
    NodeValue value;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

bool testAddElement(void) {
    NodeValue value = createValue("test", 1);
    Node *node = createNode(value);

    NodeValue newValue = { "newValue", 2 };
    addElement(node, newValue);
    bool result = node->rightChild->value.key == 2;
    deleteTree(node);

    return result;
}

bool testFindNodeByKey(void) {
    NodeValue value = { "test", 1 };
    Node *node = createNode(value);

    NodeValue newValue = { "newValue", 2 };
    addElement(node, newValue);

    Node *foundNode = findNodeByKey(node, 2);
    bool result = foundNode->value.key == 2 && strcmp(foundNode->value.value, "newValue") == 0;
    deleteTree(node);

    return result;
}

bool testExistenceOfElement(void) {
    NodeValue value = { "test", 1 };
    Node *node = createNode(value);

    NodeValue newValue = { "newValue", 2 };
    addElement(node, newValue);
    bool result = existenceOfElementByKey(node, 2) == 0 && existenceOfElementByKey(node, 4) == 1;
    deleteTree(node);

    return result;
}

bool testDeleteElementWithoutChildrens(void) {
    NodeValue value = { "test", 10 };
    Node *node = createNode(value);

    NodeValue firstValue = { "newValue", 2 };
    addElement(node, firstValue);

    deleteElementByKey(node, 2);
    bool result = node->leftChild == NULL;
    deleteTree(node);

    return result;
}

bool testDeleteElementWithOneChildren(void) {
    NodeValue value = { "test", 10 };
    Node *node = createNode(value);

    NodeValue newValue = { "newValue", 2 };
    addElement(node, newValue);

    NodeValue childOfNewValue = { "childOfNewValue", 1};
    addElement(node, childOfNewValue);

    deleteElementByKey(node, 2);
    bool result = node->rightChild->value.key == 1;
    deleteTree(node);

    return result;
}

bool testDeleteElementWithManyChildrens(void){
    NodeValue value = { "test", 10 };
    Node *node = createNode(value);

    NodeValue leftChildOfValue = { "leftChildOfValue", 2 };
    addElement(node, leftChildOfValue);

    NodeValue grandLeftChildOfValue = { "grandLeftChildOfValue", 1};
    addElement(node, grandLeftChildOfValue);

    NodeValue rightChildOfValue = { "rightChildOfValue", 15};
    addElement(node, rightChildOfValue);

    NodeValue grandRightChildOfValue = { "grandRightChildOfValue", 12};
    addElement(node, grandRightChildOfValue);

    deleteElementByKey(node, 15);
    bool result = node->rightChild->value.key;
    deleteTree(node);

    return result;
}

bool allTests(void) {
    /*if (!testAddElement()) {
        printf("Error at adding element");
        return false; 
    }*/
    if (!testDeleteElementWithManyChildrens()) {
        printf("error at deleting element with MANY childrens");
        return false;
    }
    if (!testDeleteElementWithOneChildren()) {
        printf("error at deleting element with ONE children");
        return false;
    }
    if (!testDeleteElementWithoutChildrens()) {
        printf("error at deleting element WITHOUT childrens");
        return false;
    }
    if (!testExistenceOfElement()) {
        printf("error at checking existence of element");
        return false;
    }
    if (!testFindNodeByKey()) {
        printf("error at finding node by key");
        return false;
    }
    return true;
}