#include <stdio.h>
#include "Queue.h"

// Function to create queue
void createQueue(struct Queue* queue) {
    queue->head = -1;
    queue->tail = 0;
}

// Function to check if the queue full
bool isFull(struct Queue* queue) {
    if (queue->length != 0) {
        return true;
    }
    return false;
}

// Function to loop the queue
void incrementQueue(int *index) {
    *index++;
    if (*index == MAX_SIZE) {
        *index = 0;
    }
    return;
}

// Function to remove an element from the queue
void dequeue(struct Queue* queue) {
    if (queue->length == 0) {
        printf("Queue is empty\n");
        return;
    }
    queue->head++;
    queue->length--;
}
// Function to add an element to the queue 
void enqueue(struct Queue* queue, int value) {
    if (queue->length == MAX_SIZE) {
        printf("Queue is full!\n");
        return;
    }
    queue->array[queue->tail] = value;
    queue->tail++;
    queue->length++;
}

// Function to print current queue
void printQueue(struct Queue* queue) {
    if (queue->length == 0) {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue: ");
    for (int i = queue->head + 1; i < queue->tail; i++) {
        printf("%d ", queue->array[i]);
    }
    printf("\n");
}
