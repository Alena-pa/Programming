#include <stdio.h>
#include <string.h>
#include "Tests.h"
#include "HashTable.h"

typedef struct Node {
    char* word;
    int count;
    struct Node* next;
} Node;

typedef struct HashTable {
    Node** segments;
    int countOfSegments;
    int countOfElements;
} HashTable;

bool testHashFunction() {
    int result = hashFunction("test", 10);
    return result >= 0 && result < 10;
}

bool testAddWord() {
    HashTable* table = createTable(10);

    addWord(table, "firstWord");
    addWord(table, "word");
    addWord(table, "firstWord");

    Node* node = table->segments[hashFunction("firsWord", table->countOfSegments)];
    if (node == NULL || node->count != 1) {
        printf("Error at adding Word");
        return false;
    }

    node = table->segments[hashFunction("word", table->countOfSegments)];
    if (node == NULL || node->count != 1) {
        printf("Error at adding Word");
        return false;
    }

    deleteTable(table);
    return true;
}

bool testAnalyzeTable() {
    HashTable* table = createTable(10);

    addWord(table, "firstWord");
    addWord(table, "word");
    addWord(table, "firstWord");

    double loadFactor = getLoadFactor(table);
    double averageLength = getAverageLength(table);
    double maxLength = getMaxLength(table);

    bool result = loadFactor == 0.2 && averageLength == 1 && maxLength == 2;
    if (!result) {
        printf("error at analyzing");
        return false;
    }
    deleteTable(table);
    return true;
}

bool allTests() {
    return (testAddWord && testAnalyzeTable && testHashFunction);
}