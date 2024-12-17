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
    List* states;
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
    graph->states = (List*)malloc(numberOfCities * sizeof(List));
    for (int i = 0; i < numberOfCities; i++) {
        graph->states[i].head = NULL;
    }

    return graph;
}

void addEdge(Graph* graph, int from, int to, int distance) {
    ListNode* newNode = newListNode(to, distance);
    newNode->next = graph->states[from].head;
    graph->states[from].head = newNode;

    ListNode* newNode = newListNode(from, distance);
    newNode->next = graph->states[to].head;
    graph->states[to].head = newNode;
}

void deleteGraph(Graph* graph) {
    if (graph == NULL) {
        return;
    }

    for (int i = 0; i < graph->numberOfCities; i++) {
        ListNode* current = graph->states[i].head;
        while (current != NULL) {
            ListNode* tmp = current;
            current = current->next;
            free(tmp);
        }
    }

    free(graph->states);
    free(graph);
}

int nearestCity(Graph* graph, int indexOfCapital) {

}

int addingACityToAState(Graph* graph, int indexOfCapital, int** states, int numberOfCities, int numberOfCapitals);

void readFromFile(FILE* fileName, int* numberOfCities, int numberOfCapitals);