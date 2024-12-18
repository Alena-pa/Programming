#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
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

ListNode* newListNode(int city, int distance) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));

    newNode->distance = distance;
    newNode->city = city;
    newNode->capital = -1;
    newNode->next = NULL;

    return newNode;
}

Graph* createGraph(int numberOfCities) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    if (graph == NULL) {
        printf("Memory allocation!");
        return graph;
    }

    graph->numberOfCities = numberOfCities;
    graph->cities = (List*)malloc(numberOfCities * sizeof(List));
    if (graph->cities == NULL) {
        printf("Memory allocation!");
        return graph->cities;
    }

    graph->ownership = (int*)malloc(graph->numberOfCities * sizeof(int));
    if (graph->ownership == NULL) {
        printf("Memory allocation!");
        return graph->ownership;
    }
    for (int i = 0; i < graph->numberOfCities; i++) {
        graph->ownership[i] = -1;
    }

    for (int i = 0; i < numberOfCities; i++) {
        graph->cities[i].head = NULL;
    }

    return graph;
}

void addEdge(Graph* graph, int from, int to, int distance) {
    ListNode* newEdgeTo = newListNode(to, distance);
    newEdgeTo->next = graph->cities[from].head;
    graph->cities[from].head = newEdgeTo;

    ListNode* newEdgeFrom = newListNode(from, distance);
    newEdgeFrom->next = graph->cities[to].head;
    graph->cities[to].head = newEdgeFrom;
}

void deleteGraph(Graph* graph) {
    if (graph == NULL) {
        return;
    }

    for (int i = 0; i < graph->numberOfCities; i++) {
        ListNode* current = graph->cities[i].head;
        while (current != NULL) {
            ListNode* tmp = current;
            current = current->next;
            free(tmp);
        }
    }

    free(graph->cities);
    free(graph);
}

int nearestCity(Graph* graph, int indexOfCapital) {
    int nearestCity = -1;
    int minDistance = INT_MAX;

    bool* visitedCities = (bool*)calloc(graph->numberOfCities, sizeof(bool));
    if (visitedCities == NULL) {
        printf("memory allocation!");
        return -2;
    }

    int* queue = (int*)malloc(graph->numberOfCities * sizeof(int));
    if (queue == NULL) {
        printf("memory allocation!");
        return -2;
    }

    int front = 0;
    int rear = 0;

    for (int city = 0; city < graph->numberOfCities; city++) {
        if (graph->ownership[city] == indexOfCapital) {
            queue[rear++] = city;
            visitedCities[city] = true;
        }
    }

    while (front < rear) {
        int currentCity = queue[front++];
        ListNode* neighbor = graph->cities[currentCity].head;

        while (neighbor != NULL) {
            if (!visitedCities[neighbor->city]) {
                if (graph->ownership[neighbor->city] == -1) {
                    if (neighbor->distance < minDistance) {
                        minDistance = neighbor->distance;
                        nearestCity = neighbor->city;
                    }
                }
                queue[rear++] = neighbor->city;
                visitedCities[neighbor->city] = true;
            }
            neighbor = neighbor->next;
        }
    }

    free(visitedCities);
    free(queue);

    return nearestCity;
}

void addingACityToAState(Graph* graph, int indexOfCapital) {
    int nearest = nearestCity(graph, indexOfCapital);
    if (nearest == -2) {
        return;
    }
    if (nearest != -1) {
        graph->ownership[nearest] = indexOfCapital;
    }
}

bool distributeCities(Graph* graph, int* cities, int numberOfCapitals) {
    if (cities == NULL) {
        printf("Capitals array is NULL\n");
        return false;
    }

    for (int i = 0; i < numberOfCapitals; i++) {
        
        if (cities[i] < 0 || cities[i] >= graph->numberOfCities) {
            printf("Incorrect index!\n", cities[i]);
            return false;
        }
        graph->ownership[cities[i]] = cities[i];
    }

    int remainingCitites = graph->numberOfCities - numberOfCapitals;

    while (remainingCitites > 0) {
        for (int i = 0; i < numberOfCapitals; i++) {
            int capital = cities[i];
            int city = nearestCity(graph, capital);
            if (city == -2) {
                return false;
            }
            if (city != -1) {
                graph->ownership[city] = capital;
                remainingCitites--;
            }
        }
    }

    return true;
}

Graph* readFromFile(FILE* fileName, int** cities, int* numberOfCapitals) {
    int numberOfCities, numberOfRoads;
    fscanf(fileName, "%d %d", &numberOfCities, &numberOfRoads);

    Graph* graph = createGraph(numberOfCities);
    if (graph == NULL) {
        return graph;
    }

    for (int i = 0; i < numberOfRoads; i++) {
        int from, to, distance;
        fscanf(fileName, "%d %d %d", &from, &to, &distance);
        addEdge(graph, from, to, distance);
    }

    fscanf(fileName, "%d", numberOfCapitals);
    *cities = (int*)malloc(*numberOfCapitals * sizeof(int));
    if (*cities == NULL) {
        return *cities;
    }
    for (int i = 0; i < *numberOfCapitals; i++) {
        fscanf(fileName, "%d", &(*cities)[i]);
    }

    return graph;
}

void printResults(Graph* graph, int numberOfCapitals, int* cities) {
    for (int i = 0; i < numberOfCapitals; i++) {
        int capital = cities[i];
        printf("State %d\nCapital %d:\n    Cities: ", i + 1, capital);
        for (int city = 0; city < graph->numberOfCities; city++) {
            if (graph->ownership[city] == capital) {
                printf("%d", city);
            }
        }
        printf("\n");
    }
}