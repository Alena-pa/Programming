#pragma once

typedef struct NodeValue {
    char *value;
    int key;
} NodeValue;

typedef struct Node {
    NodeValue value;
    struct Node *leftChild;
    struct Node *rightChild;
} Node;

NodeValue createValue(int key, const char* value);

Node *createNode(NodeValue value);

void addLeftChild(Node *node, Node *child);

void addRightChild(Node *node, Node *child);

void addElement(Node* node, NodeValue value);

Node *getLeftChild(Node *node);

Node *getRightChild(Node *node);

Node * findNodeByKey(Node* node, int key);

NodeValue getValue(Node *node);

int existenceOfElementByKey(Node* node, int key);

void deleteElementByKey(Node* node, int key);

Node* minElement(Node* node);