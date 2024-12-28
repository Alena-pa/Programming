#pragma once
#include <stdbool.h>

typedef struct ListNode ListNode;
typedef struct List List;
typedef struct Graph Graph;

ListNode* newListNode(int city, int distance);

Graph* createGraph(int numberOfCities);

void addEdge(Graph* graph, int from, int to, int distance);

void deleteGraph(Graph* graph);

int nearestCity(Graph* graph, int indexOfCapital);

void addingACityToAState(Graph* graph, int indexOfCapital);

bool distributeCities(Graph* graph, int* capitals, int numberOfCapitals);

Graph* readFromFile(FILE* fileName, int** capitals, int* numberOfCapitals);

void printResults(Graph* graph, int numberOfCapitals, int* capitals);