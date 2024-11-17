#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "Tests.h"
#include "Tree.h"

bool testCreateNode() {
    Node *node = createNode(1, "value");
    return node != NULL && node->value.key == 1 && strcmp(node->value.value, "test") == 0;
}

bool testAddElement() {
    NodeValue value = { "test", 1 };
    Node *node = createNode(value);

    NodeValue newValue = { "newValue", 2 };
    addElement(node, newValue);

    return node->rightChild->value.key == 2;
}

bool testFindNodeByKey() {
    NodeValue value = { "test", 1 };
    Node *node = createNode(value);

    NodeValue newValue = { "newValue", 2 };
    addElement(node, newValue);

    Node *foundNode = findNodeByKey(node, 2);
    return foundNode->value.key == 2 && strcmp(foundNode->value.value, "newValue") == 0;
}

bool testExistenceOfElement() {
    NodeValue value = { "test", 1 };
    Node *node = createNode(value);

    NodeValue newValue = { "newValue", 2 };
    addElement(node, newValue);

    return existenceOfElementByKey(node, 2) == 0 && existenceOfElementByKey(node, 4) == 1;
}

bool testDeleteElementWithoutChildrens() {
    NodeValue value = { "test", 10 };
    Node *node = createNode(value);

    NodeValue firstValue = { "newValue", 2 };
    addElement(node, firstValue);

    deleteElementByKey(node, 2);
    return node->leftChild == NULL;
}

bool testDeleteElementWithOneChildren() {
    NodeValue value = { "test", 10 };
    Node *node = createNode(value);

    NodeValue newValue = { "newValue", 2 };
    addElement(node, newValue);

    NodeValue childOfNewValue = { "childOfNewValue", 1};
    addElement(node, childOfNewValue);

    deleteElementByKey(node, 2);
    return node->leftChild->value.key == 1;
}

bool testDeleteElementWithManyChildrens(){
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
    return node->rightChild->value.key == 12;
}

bool allTests() {
    return testCreateNode && testAddElement && testDeleteElementWithManyChildrens && testDeleteElementWithOneChildren && testDeleteElementWithoutChildrens && testExistenceOfElement && testFindNodeByKey;
}