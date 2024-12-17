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
    List* array;
} Graph;

ListNode* newListNode(int city, int distance, int capital) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));

    newNode->distance = distance;
    newNode->city = city;
    newNode->capital = capital;
    newNode->next = NULL;

    return newNode;
}

Graph* createGraph(int numberOfCities) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->numberOfCities = numberOfCities;
    graph->array = (List*)malloc(numberOfCities * sizeof(List));
    for (int i = 0; i < numberOfCities; i++) {
        graph->array[i].head = NULL;
    }

    return graph;
}

void addEdge(Graph* graph, int from, int to, int distance);

void deleteGraph(Graph* graph);

int nearestCity(Graph* graph, int indexOfCapital, int** states, int numberOfCities, int numberOfCapitals);

int addingACityToAState(Graph* graph, int indexOfCapital, int** states, int numberOfCities, int numberOfCapitals);

void readFromFile(FILE* fileName, int* numberOfCities, int numberOfCapitals);