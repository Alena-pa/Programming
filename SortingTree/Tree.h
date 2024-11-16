#pragma once

typedef struct {
    char value;
    int key;
} NodeValue;

typedef struct Node Node;

Node *createNode(NodeValue value);

void addLeftChild(Node *node, Node *child);

void addRightChild(Node *node, Node *child);

void addElement(Node* node, NodeValue value);

Node *getLeftChild(Node *node);

Node *getRightChild(Node *node);

Node *getElementByKey(Node* node, int key);

NodeValue getValue(Node *node);

int existenceOfElementByKey(Node* node, int key);

void deleteElementByKey(Node* node, int key);

Node* minValueNode(Node* node);