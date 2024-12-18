#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

int main(void) {
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("error opening file!\n");
        return 1;
    }

    int numberOfCapitals;
    int* capitals;

    Graph* graph = readFromFile(file, &numberOfCapitals, &capitals);
    if (graph == NULL) {
        return 2;
    }
    fclose(file);

    distributeCities(graph, capitals, numberOfCapitals);
    if (!distributeCities) {
        return 2;
    }

    printResults(graph, numberOfCapitals, capitals);

    free(capitals);
    deleteGraph(graph);
}