#include <stdio.h>
#include <stdbool.h>
#include "Tests.h"
#include "Graph.h"

bool testGraph() {
    int numberOfCapitals = 0;
    int* capitals = NULL;

    FILE* file = fopen("test.txt", "r");
    Graph* graph = readFromFile(file, &numberOfCapitals, &capitals);
    if (graph == NULL) {
        printf("Memory allocation!");
        return 2;
    }
    fclose(file);

    int firstEdge = addEdge(graph, 0, 1, 2);
    int secondEdge = addEdge(graph, 1, 2, 1);
    if (!(firstEdge && secondEdge)) {
        deleteGraph(graph);
        return false;
    }

    bool resultOfDistribution = distributeCities(graph, capitals, numberOfCapitals);
    if (!resultOfDistribution) {
        deleteGraph(graph);
        return false;
    }

    printResults(graph, numberOfCapitals, capitals);

    deleteGraph(graph);
    free(capitals);

    return true;
}
