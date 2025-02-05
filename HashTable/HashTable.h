#pragma once

typedef struct Node Node;

typedef struct HashTable HashTable;

// Creates a new hash table with the given size.
HashTable* createTable(int size);

// Calculates the hash value for a word.
int hashFunction(char* word, int size);

// Adds a word to the table or increases its count if it already exists.
void addWord(HashTable* table, char* word);

// Prints all words and their counts from the hash table.
void printTable(HashTable* table);

// Calculates the load factor of the hash table.
double getLoadFactor(HashTable* table);

// Finds the average length of linked lists in the table.
double getAverageLength(HashTable* table);

// Finds the maximum length of linked lists in the table.
int getMaxLength(HashTable* table);

// Prints statistics about the hash table
void analyzeTable(HashTable* table);

// Cleans and normalizes a word .
void cleanWord(char* word);

// Reads words from a file, adds them to the hash table, and analyzes the table.
void analyzeFile(HashTable* table, char* filename);

// Frees all memory used by the hash table.
void deleteTable(HashTable* table);