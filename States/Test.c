#include <stdio.h>
#include <stdbool.h>
#include "Tests.h"
#include "Graph.h"

typedef struct ListNode {
    int city;
    int distance;
    int capital;
    ListNode* next;
} ListNode;

typedef struct List {
    ListNode* head;
} List;

typedef struct Graph {
    int numberOfCities;
    List* cities;
    int* ownership;
} Graph;

bool testCreateGraph() {
    Graph* graph = createGraph(5);
    if (graph == NULL) {
        return false;
    }

    if (graph->numberOfCities != 5) {
        return false;
    }

    for (int i = 0; i < graph->numberOfCities; i++) {
        if (graph->ownership[i] != -1) {
            return false;
        }
        if (graph->cities[i].head != NULL) {
            return false;
        }
    }

    deleteGraph(graph);
    return true;
}

bool testAddEdge() {
    Graph* graph = createGraph(3);
    if (graph == NULL) {
        return false;
    }

    addEdge(graph, 0, 1, 10);
    addEdge(graph, 1, 2, 5);

    if (graph->cities[0].head->city != 1 || graph->cities[0].head->distance != 10) {
        return false;
    }
    if (graph->cities[1].head->city != 2 || graph->cities[1].head->distance != 5) {
        return false;
    }

    if (graph->cities[1].head->city != 2 || graph->cities[1].head->distance != 5) {
        return false;
    }
    if (graph->cities[2].head->city != 1 || graph->cities[2].head->distance != 5) {
        return false;
    }

    deleteGraph(graph);
    return true;
}

bool testNearestCity() {
    Graph* graph = createGraph(3);
    if (graph == NULL) {
        return false;
    }

    addEdge(graph, 0, 1, 5);
    addEdge(graph, 1, 2, 10);

    graph->ownership[0] = 0;
    int nearest = nearestCity(graph, 0);
    if (nearest != 1) {
        return false;
    }

    deleteGraph(graph);
    return true;
}

bool testDistributeCities() {
    Graph* graph = createGraph(5);
    if (graph == NULL) {
        return false;
    }

    addEdge(graph, 0, 1, 5);
    addEdge(graph, 1, 2, 10);
    addEdge(graph, 2, 3, 15);
    addEdge(graph, 3, 4, 20);

    int capitals[] = { 0, 3 };
    if (!distributeCities(graph, capitals, 2)) {
        return false;
    }

    if (graph->ownership[0] != 0 || graph->ownership[1] != 0 || graph->ownership[2] != 3 || graph->ownership[3] != 3 || graph->ownership[4] != 3) {
        printf("error at third if");
        return false;
    }

    deleteGraph(graph);
    return true;
}

bool testReadFromFile() {
    FILE* testFile = fopen("test.txt", "r");
    if (testFile == NULL) {
        return false;
    }

    int* capitals = NULL;
    int numberOfCapitals;
    Graph* graph = readFromFile(testFile, &capitals, &numberOfCapitals);
    fclose(testFile);

    if (graph == NULL || capitals == NULL) {
        return false;
    }

    if (graph->numberOfCities != 4 || numberOfCapitals != 1 || capitals[0] != 0) {
        return false;
    }

    deleteGraph(graph);
    free(capitals);
    return true;
}

bool allTests() {
    if (!testCreateGraph()) {
        printf("Error at creating Graph");
        return false;
    }
    if (!testAddEdge()) {
        printf("Error at adding edge");
        return false;
    }
    if (!testDistributeCities()) {
        printf("Error at Distributing cities");
        return false;
    }
    if (!testNearestCity()) {
        printf("Error at finging nearest city");
        return false;
    }
    if (!testReadFromFile) {
        printf("Error at reading from file");
        return false;
    }
    return true;
}