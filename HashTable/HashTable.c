#include <stdio.h>
#include <string.h>
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

int hashFunction(char* word, int size) {
    int hash = 0;
    while (*word) {
        hash = (hash * 31 + *word) % size;
        word++;
    }

    return hash;
}

void addWord(HashTable* table, char* word) {
    int indexOfWord = hashFunction(word, table->countOfSegments);
    Node* current = table->segments[indexOfWord];

    while (current) {
        if (strcmp(current->word, word) == 0) {
            current->count++;
            return;
        }
        current = current->next;
    }
}

void printTable(HashTable* table);

void analyzeTable(HashTable* table);

void analyzeFile(HashTable* table, char* filename);