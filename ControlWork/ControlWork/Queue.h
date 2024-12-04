#pragma once
#include <stdbool.h>
#define MAX_SIZE 100

// Defining the Queue structure
typedef struct Queue {
    int array[MAX_SIZE];
    int head;
    int tail;
    int length;
} Queue;

bool isFull(struct Queue* queue);

void createQueue(struct Queue* queue);

void incrementQueue(struct Queue* queue);

void dequeue(struct Queue* queue);

void enqueue(struct Queue* queue, int value);

void printQueue(struct Queue* queue);
