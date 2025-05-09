#pragma once
#include <stdbool.h>

typedef struct HashNode HashNode;

typedef struct HashTable HashTable;

void initHashTable(HashTable* table);

void insertNode(HashTable* table, char value);

int hashFunction(char* value);

bool searchNode(HashTable* table, char value);

void deleteTable(HashTable* table);
