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

void printTable(HashTable* table) {
    for (int i = 0; i < table->countOfSegments; i++) {
        Node* current = table->segments[i];
        while (current) {
            printf("%s: %d\n", current->word, current->count);
            current->next;
        }
    }
}

void analyzeTable(HashTable* table) {
    int filledSegments = 0;
    int maxLength = 0;
    int totalLength = 0;

    double loadFactor = table->countOfElements / table->countOfSegments;
    double averageLength;

    for (int i = 0; i < table->countOfSegments; i++) {
        int length = 0;
        Node* current = table->segments[i];
        while (current) {
            length++;
            current = current->next;
        }

        if (length > 0) {
            filledSegments++;
            totalLength += length;
            if (length > maxLength) {
                maxLength = length;
            }
        }
    }

    if (filledSegments) {
        averageLength = totalLength / filledSegments;
    }
    else {
        averageLength = 0;
    }

    printf("Load factor: %.2f\n", loadFactor);
    printf("Average list length: %.2f\n", averageLength);
    printf("Max list length: %d\n", maxLength);
}

void analyzeFile(HashTable* table, char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Unable to open file!");
        return;
    }

    char word[256];
    while (fscanf(file, "%255s", word) == 1) {
        addWord(table, word);
    }

    fclose(file);
}