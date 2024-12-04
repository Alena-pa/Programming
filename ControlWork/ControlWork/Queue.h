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

// Function to check if the queue full
bool isFull(struct Queue* queue);

// Function to create queue
void createQueue(struct Queue* queue);

// Function to loop the queue
void incrementQueue(struct Queue* queue);

// Function to remove an element from the queue
int dequeue(struct Queue* queue);

// Function to add an element to the queue 
void enqueue(struct Queue* queue, int value);

// Function to print current queue
void printQueue(struct Queue* queue);
