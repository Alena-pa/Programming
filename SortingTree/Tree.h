#pragma once
#include <stdbool.h>

typedef struct {
    char* value;
    int key;
} NodeValue;

typedef struct Node Node;

//create a value
NodeValue createValue(const char* value, int key);

// Create a node
Node* createNode(NodeValue value);

//add element to tree
bool addElement(Node* node, NodeValue value);

//find element by key
Node * findNodeByKey(Node* node, int key);

//Check if an element is present in a tree
bool existenceOfElementByKey(Node* node, int key);

//delete element by key
void deleteElementByKey(Node* node, int key);

//find minimal element in a tree
Node* minElement(Node* node);

//delete tree
void deleteTree(Node* node);