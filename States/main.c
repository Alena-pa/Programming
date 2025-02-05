#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"
#include "Tests.h"

int main(void) {
    if (!testGraph()) {
        return -1;
    }
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("error opening file!\n");
        return 1;
    }

    int numberOfCapitals = 0;
    int* capitals = NULL;

    Graph* graph = readFromFile(file, &numberOfCapitals, &capitals);
    if (graph == NULL) {
        printf("Memory allocation!");
        return 2;
    }
    fclose(file);

    bool result = distributeCities(graph, capitals, numberOfCapitals);
    if (!result) {
        return 2;
    }

    printResults(graph, numberOfCapitals, capitals);

    free(capitals);
    deleteGraph(graph);
}