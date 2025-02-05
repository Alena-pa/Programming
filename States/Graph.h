#pragma once
#include <stdbool.h>

typedef struct ListNode ListNode;
typedef struct List List;
typedef struct Graph Graph;

// Creates a new node with a city and distance  
ListNode* newListNode(int city, int distance);

// Creates a graph with a given number of cities
Graph* createGraph(int numberOfCities);

// Adds a road between two cities
int addEdge(Graph* graph, int from, int to, int distance);

// Deletes the graph
void deleteGraph(Graph* graph);

// Finds the closest city to a capital
int nearestCity(Graph* graph, int indexOfCapital);

// Adds a city to a capital's region
void addACityToAState(Graph* graph, int indexOfCapital);

// Distributes cities between capitals
bool distributeCities(Graph* graph, int* capitals, int numberOfCapitals);

// Reads the graph and capitals from a file
Graph* readFromFile(FILE* fileName, int** capitals, int* numberOfCapitals);

// Prints the results
void printResults(Graph* graph, int numberOfCapitals, int* capitals);