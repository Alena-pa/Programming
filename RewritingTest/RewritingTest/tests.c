#include "Hashtable.h"
#include "tests.h"
#include <stdio.h>
#define TABLESIZE 100

typedef struct HashNode {
    char* value;
    bool isUsed;
} HashNode;

typedef struct HashTable {
    HashNode* table[TABLESIZE];
} HashTable;

bool testInsertNode() {
    HashTable* table;
    HashTable* tablePtr = &table;
    initHashTable(table);

    insertNode(table, "test1");
    insertNode(table, "test2");

    bool result = false;
    for (int i = 0; i < TABLESIZE; i++) {
        if (table->table[i] != NULL) {
            result = true;
        }
    }
    deleteTable(table);
    return result;
}

bool testSearchNode() {
    HashTable* table;
    HashTable* tablePtr = &table;
    initHashTable(table);

    insertNode(table, "test1");
    insertNode(table, "test2");

    bool result = searchNode(table, "test1") && searchNode(table, "test2") && !searchNode(table, "test3");
    deleteTable(table);
    return result;
}

bool allTests() {
    if (!testInsertNode()) {
        printf("Error at inserting\n");
        return false;
    }
    if (!testSearchNode()) {
        printf("error at seraching\n");
    }
    return true;
}