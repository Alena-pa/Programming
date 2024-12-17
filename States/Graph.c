#include <stdio.h>
#include "Graph.h"

typedef struct Node {
    int city;
    int distance;
    int capital;
    struct Node* next;
} Node;

typedef struct Graph {
    Node* adjacencyList;
    int numberOfCities;
} Graph;
