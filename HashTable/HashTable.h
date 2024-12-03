#pragma once

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

HashTable* createTable(int size); 

int hashFunction(char* word, int size);

void addWord(HashTable* table, char* word);

void printTable(HashTable* table);

void analyzeTable(HashTable* table);

void analyzeFile(HashTable* table, char* filename);