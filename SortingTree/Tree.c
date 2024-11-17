#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Tree.h"

Node *createNode(int key, const char* value) {
    Node *node = calloc(1, sizeof(Node));
    node->value.key = key;
    char *newValue = malloc(strlen(value));
    strcpy(newValue, value);
    node->value.value = newValue;
    return node;
}

void addLeftChild(Node *node, Node *child) {
    node->leftChild = child;
}

void addRightChild(Node *node, Node *child) {
    node->rightChild = child;
}

void addElement(Node* node, NodeValue value) {
    if (node->value.key == value.key) {
        node->value = value;
    }
    else if (node->value.key > value.key && node->leftChild == NULL) {
        Node* element = createNode(value);
        addLeftChild(node, element);
    }
    else if (node->value.key < value.key && node->rightChild == NULL) {
        Node* element = createNode(value);
        addRightChild(node, element);
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


int existenceOfElementByKey(Node* node, int key) {
    if (findNodeByKey(node, key) != NULL){
        return 0;
    }
    return 1;
}

Node *getLeftChild(Node *node) {
    return node->leftChild;
}

Node *getRightChild(Node *node) {
    return node->rightChild;
}

NodeValue getValue(Node *node) {
    return node->value;
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

    if (element != NULL) {
        if (element->leftChild == NULL && element->rightChild == NULL) {
            if (parent->leftChild == element) {
                parent->leftChild = NULL;
            }
            else if (parent->rightChild == element) {
                parent->rightChild = NULL;
            }
            free(element->value.value);
            free(element);
        }
        else if (element->leftChild != NULL && element->rightChild == NULL) {
            Node* child = element->leftChild;
            if (parent->leftChild == element) {
                parent->leftChild = child;
            }
            else if (parent->rightChild == element) {
                parent->rightChild = child;
            }
        }
        else if (element->leftChild == NULL && element->rightChild != NULL) {
            Node* child = element->rightChild;
            if (parent->leftChild == element) {
                parent->leftChild = child;
            }
            else if (parent->rightChild == element) {
                parent->rightChild = child;
            }
        }
        else {
            Node* child = element->rightChild;
            Node* minimalChildFromRight = minElement(element);
            if (child == minimalChildFromRight) {
                parent->rightChild = minimalChildFromRight;
            }
            else {
                minimalChildFromRight->rightChild = element->rightChild;
                parent->rightChild = minimalChildFromRight;
            }
        }
        free(element->value.value);
        free(element);
    }
    return node;
}