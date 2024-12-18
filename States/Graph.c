#include <stdio.h>
#include <stdlib.h>
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
    List* capitals;
    int* ownership;
} Graph;

ListNode* newListNode(int city, int distance) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));

    newNode->distance = distance;
    newNode->city = city;
    newNode->capital = NULL;
    newNode->next = NULL;

    return newNode;
}

Graph* createGraph(int numberOfCities) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numberOfCities = numberOfCities;
    graph->capitals = (List*)malloc(numberOfCities * sizeof(List));
    for (int i = 0; i < numberOfCities; i++) {
        graph->capitals[i].head = NULL;
    }

    return graph;
}

void addEdge(Graph* graph, int from, int to, int distance) {
    ListNode* newEdge = newListNode(to, distance);
    newEdge->next = graph->capitals[from].head;
    graph->capitals[from].head = newEdge;

    ListNode* newEdge = newListNode(from, distance);
    newEdge->next = graph->capitals[to].head;
    graph->capitals[to].head = newEdge;
}

void deleteGraph(Graph* graph) {
    if (graph == NULL) {
        return;
    }

    for (int i = 0; i < graph->numberOfCities; i++) {
        ListNode* current = graph->capitals[i].head;
        while (current != NULL) {
            ListNode* tmp = current;
            current = current->next;
            free(tmp);
        }
    }

    free(graph->capitals);
    free(graph);
}

int nearestCity(Graph* graph, int indexOfCapital) {
    int nearestCity = -1;
    int minDistance = 10 ^ 10;

    for (int i = 0; i < graph->numberOfCities; i++) {
        if (graph->capitals[i].head == NULL || graph->capitals[i].head->capitals != indexOfCapital) {
            ListNode* node = graph->capitals[i].head;
            while (node != NULL) {
                if (node->capital != indexOfCapital && node->distance < minDistance) {
                    minDistance = node->distance;
                    nearestCity = node->city;
                }
                node = node->next;
            }
        }
    }

    return nearestCity;
}

void addingACityToAState(Graph* graph, int indexOfCapital) {
    int nearest = nearestCity(graph, indexOfCapital);
    if (nearestCity != -1) {
        graph->ownership[nearest] = indexOfCapital;
    }
}

void distributeCities(Graph* graph, int* capitals, int numberOfCapitals) {
    for (int i = 0; i < numberOfCapitals; i++) {
        graph->ownership[capitals[i]] = capitals[i];
    }

    int remainingCitites = graph->numberOfCities - numberOfCapitals;

    while (remainingCitites > 0) {
        for (int i = 0; i < numberOfCapitals; i++) {
            int capital = capitals[i];
            int city = nearestCity(graph, capital);
            if (city != -1) {
                graph->ownership[city] = capital;
                remainingCitites--;
            }
        }
    }
}

Graph* readFromFile(FILE* fileName, int** capitals, int* numberOfCapitals) {
    int numberOfCities, numberOfRoads;
    fscanf(fileName, "%d %d", &numberOfCities, &numberOfRoads);

    Graph* graph = createGraph(numberOfCities);

    for (int i = 0; i < numberOfRoads; i++) {
        int from, to, distance;
        fscanf(fileName, "%d %d %d", &from, &to, &distance);
        addEdge(graph, from, to, distance);
    }

    fscanf(fileName, "%d", numberOfCapitals);
    *capitals = (int*)malloc(*numberOfCapitals * sizeof(int));
    for (int i = 0; i < *numberOfCapitals; i++) {
        fscanf(fileName, "%d", &(*capitals)[i]);
    }

    return graph;
}

void printResults(Graph* graph, int numberOfCapitals, int* capitals) {
    for (int i = 0; i < numberOfCapitals; i++) {
        int capital = capitals[i];
        printf("State %d\nCapital %d:\n    Cities: ", i + 1, capital);
        for (int city = 0; city < graph->numberOfCities; city++) {
            if (graph->ownership[city] == capital) {
                printf("%d", city);
            }
        }
        printf("\n");
    }
}