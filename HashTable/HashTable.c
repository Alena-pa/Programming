#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
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

HashTable* createTable(int size) {
    HashTable* table = malloc(sizeof(HashTable));
    if (table == NULL) {
        return NULL;
    }
    table->countOfSegments = size;
    table->countOfElements = 0;
    table->segments = malloc(size * sizeof(Node*));
    if (table->segments == NULL) {
        return NULL;
    }
    for (int i = 0; i < size; i++) {
        table->segments[i] = NULL;
    }
    return table;
}

unsigned int hashFunction(char* word, int size) {
    unsigned int hash = 0;
    for (int i = 0; word[i] != '\0'; i++) {
        hash = (hash * 31 + word[i]) % size;
    }
    return hash;
}

void resizeHashTable(HashTable* table) {
    int oldSegmentCount = table->countOfSegments;
    Node** oldSegments = table->segments;

    int newSegmentCount = oldSegmentCount * 2;
    table->segments = calloc(newSegmentCount, sizeof(Node*));
    table->countOfSegments = newSegmentCount;
    table->countOfElements = 0;

    for (int i = 0; i < oldSegmentCount; ++i) {
        Node* current = oldSegments[i];
        while (current) {
            addWord(table, current->word);
            Node* temp = current;
            current = current->next;
            free(temp->word);
            free(temp);
        }
    }

    free(oldSegments);
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

    Node* newNode = malloc(sizeof(Node));
    newNode->word = strdup(word);
    newNode->count = 1;
    newNode->next = table->segments[indexOfWord];
    table->segments[indexOfWord] = newNode;

    table->countOfElements++;
    double loadFactor = table->countOfElements / table->countOfSegments;
    if (loadFactor > 0.75) {
        resizeHashTable(table);
    }
}

void printTable(HashTable* table) {
    for (int i = 0; i < table->countOfSegments; i++) {
        Node* current = table->segments[i];
        while (current) {
            printf("%s: %d\n", current->word, current->count);
            current = current->next;
        }
    }
}
double getLoadFactor(HashTable* table) {
    if (table->countOfSegments == 0) {
        return 0.0;
    }
    return (double)table->countOfElements / (double)table->countOfSegments;
}

double getAverageLength(HashTable* table) {
    int filledSegments = 0;
    int totalLength = 0;

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
        }
    }

    if (filledSegments == 0) {
        return 0.0;
    }

    return (double)totalLength / (double)filledSegments;
}

int getMaxLength(HashTable* table) {
    int maxLength = 0;

    for (int i = 0; i < table->countOfSegments; i++) {
        int length = 0;
        Node* current = table->segments[i];
        while (current) {
            length++;
            current = current->next;
        }
        if (length > maxLength) {
            maxLength = length;
        }
    }

    return maxLength;
}

void analyzeTable(HashTable* table) {
    double loadFactor = getLoadFactor(table);
    double averageLength = getAverageLength(table);
    int maxLength = getMaxLength(table);

    printf("Load factor: %.2f\n", loadFactor);
    printf("Average list length: %.2f\n", averageLength);
    printf("Max list length: %d\n", maxLength);
}

void cleanWord(char* word) {
    int i = 0;
    int j = 0;
    while (word[i] != '\0') {
        if (isalnum(word[i])) {
            word[j++] = tolower(word[i]);
        }
        i++;
    }
}

void analyzeFile(HashTable* table, char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Unable to open file!");
        return;
    }

    char word[256] = {0};
    while (fscanf(file, "%255s", word) == 1) {
        cleanWord(word);
        if (strlen(word) > 0) {
            addWord(table, word);
        }
    }
    fclose(file);
}


void deleteTable(HashTable* table) {
    if (!table) {
        return;
    }

    for (int i = 0; i < table->countOfSegments; i++) {
        Node* current = table->segments[i];

        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp->word);
            free(temp);
        }
    }

    free(table->segments);
    free(table);
}