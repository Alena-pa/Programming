#include <stdio.h>
#include "HashTable.h"
#include "Tests.h"

int main(void) {
    if (!allTests()) {
        printf("Tests Failed!");
        return 1;
    }
    HashTable* table = createTable(100);
    analyzeFile(table, "file.txt");
    printTable(table);
    analyzeTable(table);
    deleteTable(table);
    return 0;
}