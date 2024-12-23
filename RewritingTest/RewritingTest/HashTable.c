#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "HashTable.h"

#define TABLESIZE 100

typedef struct HashNode {
    char* value;
    bool isUsed;
} HashNode;

typedef HashNode table[TABLESIZE];

void initHashTable(HashTable* table) {
    for (int i = 0; i < TABLESIZE; i++) {
        table[i] = NULL;
    }
}
int hashFunction(char* value) {
    int hash = 0;
    for (int i = 0; value[i] != '\0'; i++) {
        hash = (hash + value[i]) % TABLESIZE;
    }
    return hash;
}

void insertNode(HashTable* table, char* value) {
    int indexOfValue = hashFunction(value);
    while (table[indexOfValue] != NULL) {
        if (!(table[indexOfValue]->isUsed)) {
            table[indexOfValue] = value;
        }
    }
}

bool searchNode(HashTable* table, char* value) {
    int indexOfValue = hashFunction(value);
    if (table[indexOfValue] != NULL) {
        return true;
    }
    return false;
}

void deleteTable(HashTable* table) {
    for (int i = 0; i < TABLESIZE; i++) {
        if (table[i] != NULL) {
            table[i] = NULL;
        }
    }
}