#include <stdio.h>
#include "HashTable.h"
#include "Tests.h"

int main(void) {
    HashTable* table = createTable(100);
    analyzeFile(table, "file.txt");
    printTable(table);
    analyzeTable(table);

    return 0;
}