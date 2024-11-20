#include <stdio.h>
#include <string.h>
#include "tree.h"

NodeValue createValue(char value, int frequency) {
    NodeValue nodeValue = { .value = value, .frequency = frequency };
    return nodeValue;
}

void printNode(Node* node) {
    NodeValue value = getValue(node);
    printf("'%c': %d\n", value.value, value.frequency);
}

int main(void) {
    const char* string = "abcccccdeeeeeee";
    int arrayOfFrequencies[256] = { 0 };
    for (int i = 0; i < strlen(string); i++) {
        unsigned char index = string[i];
        arrayOfFrequencies[index]++;
    }
    Node* arrayOfNodes[256] = { NULL };
    
    int notNullElements = 0;
    for (int i = 0; i < 256; i++) {
        if (arrayOfNodes[i] == 0) {
            continue;
        }
        notNullElements++;
        NodeValue value = createValue(i, arrayOfFrequencies[i]);
        arrayOfNodes[i] = createNode(value);
    }

    while (notNullElements > 1) {
        int firstIndexOfSmallestElement = 0;
        int secondIndexOfSmallestElement = 0;
    }
}