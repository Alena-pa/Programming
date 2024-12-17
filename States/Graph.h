#pragma once

Graph* createGraph(int numebrOfCities);

void addEdge(Graph* graph, int from, int to, int distance);

void deleteGraph(Graph* graph);

int nearestCity(Graph* graph, int indexOfCapital, int** states, int numberOfCities, int numberOfCapitals);

int addingACityToAState(Graph* graph, int indexOfCapital, int** states, int numberOfCities, int numberOfCapitals);

void readFromFile(FILE* fileName, int* numberOfCities, int numberOfCapitals);