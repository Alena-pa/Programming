#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "Tree.h"

typedef struct Node {
    NodeValue value;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

NodeValue createValue(const char* value, int key) {
    char* newValue = malloc(strlen(value) + 1);
    if (newValue == NULL) {
        NodeValue errorValue = { .key = 0, .value = NULL };
        return errorValue;
    }
    strcpy(newValue, value);
    NodeValue nodeValue = { .key = key, .value = newValue };
    return nodeValue;
}

Node *createNode(NodeValue value) {
    Node *node = calloc(1, sizeof(Node));
    if (node == NULL) {
        return NULL;
    }
    node->value = value;
    node->leftChild = NULL;
    node->rightChild = NULL;
    return node;
}

bool addElement(Node* node, NodeValue value) {
    if (node->value.key == value.key) {
        char* tmp = node->value.value;
        node->value = value;
        free(tmp);
        return true;
    }
    if (node->value.key > value.key && node->leftChild == NULL) {
        Node* element = createNode(value);
        node->leftChild = element;
    }
    else if (node->value.key < value.key && node->rightChild == NULL) {
        Node* element = createNode(value);
        node->rightChild = element;
    }
    else if (node->value.key > value.key) {
        addElement(node->leftChild, value);
    }
    else if (node->value.key < value.key) {
        addElement(node->rightChild, value);
    }
}

typedef struct FindResult {
    Node* node;
    Node* parent;
} FindResult;

FindResult findNodeAndParentByKey(Node* node, Node* parent, int key) {
    if (node->value.key == key) {
        FindResult result = { .node = node, .parent = parent };
        return result;
    }
    else if (node->value.key > key && node->leftChild != NULL) {
        return findNodeAndParentByKey(node->leftChild, node, key);
    }
    else if (node->value.key < key && node->rightChild != NULL) {
        return findNodeAndParentByKey(node->rightChild, node, key);
    }
    else {
        FindResult result = { .node = NULL, .parent = NULL };
        return result;
    }
}

Node* findNodeByKey(Node* node, int key) {
    FindResult result = findNodeAndParentByKey(node, NULL, key);
    return result.node;
}


bool existenceOfElementByKey(Node* node, int key) {
    if (findNodeByKey(node, key) != NULL) {
        return true;
    }
    return false;
}

Node *minElement(Node* node) {
    Node* minimalElement = node->rightChild;
    while (minimalElement->leftChild != NULL) {
        minimalElement = minimalElement->leftChild;
    }
    return minimalElement;
}

void deleteElementByKey(Node* node, int key) {
    FindResult result = findNodeAndParentByKey(node, NULL, key);
    Node* element = result.node;
    Node* parent = result.parent;

    if (element == NULL) {
        return;
    }

    if (element->leftChild == NULL && element->rightChild == NULL) {
        if (parent != NULL) {
            if (parent->leftChild == element) {
                parent->leftChild = NULL;
            }
            else if (parent->rightChild == element) {
                parent->rightChild = NULL;
            }
        }
        free(element->value.value);
        free(element);
        return;
    }

    if (element->leftChild != NULL && element->rightChild == NULL) {
        if (parent != NULL) {
            if (parent->leftChild == element) {
                parent->leftChild = element->leftChild;
            }
            else {
                parent->rightChild = element->leftChild;
            }
        }
        else {
            node = element->leftChild;
        }
        free(element->value.value);
        free(element);
        return;
    }

    if (element->leftChild == NULL && element->rightChild != NULL) {
        if (parent != NULL) {
            if (parent->leftChild == element) {
                parent->leftChild = element->rightChild;
            }
            else {
                parent->rightChild = element->rightChild;
            }
        }
        else {
            node = element->rightChild;
        }
        free(element->value.value);
        free(element);
        return;
    }

    Node* minimalChildFromRight = minElement(element);
    element->value = minimalChildFromRight->value;
    deleteElementByKey(element->rightChild, minimalChildFromRight->value.key);
}


void deleteTree(Node* node) {
    if (node == NULL) {
        return;
    }
    deleteTree(node->leftChild);
    deleteTree(node->rightChild);
    char* textValue = node->value.value;
    free(textValue);
    free(node);
}