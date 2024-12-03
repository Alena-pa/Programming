#include <stdio.h>
#include "HashTable.h"

HashTable* createTable(int size) {
    HashTable* table = malloc(sizeof(HashTable));
    table->countOfSegments = size;
    table->countOfElements = 0;
    table->segments = malloc(size * sizeof(Node*));
    for (int i = 0; i < size; i++) {
        table->segments[i] = NULL;
    }
    return table;
}

int hashFunction(char* word, int size);

void addWord(HashTable* table, char* word);

void printTable(HashTable* table);

void analyzeTable(HashTable* table);

void analyzeFile(HashTable* table, char* filename);