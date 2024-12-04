#include <stdio.h>
#include <stdbool.h>
#include "Tests.h"
#include "Queue.h"

// Funciton to test the function Enqueue
bool testEnqueue() {
    Queue queue;
    createQueue(&queue);
    enqueue(&queue, 1);
    if (isFull) {
        return true;
    }
    printf("Error at function enqueue");
    return false;
}

// Function to test the function dequeue
bool testDequeue() {
    Queue queue;
    createQueue(&queue);
    enqueue(&queue, 1);
    int removedElement = dequeue(&queue);
    if (!isFull) {
        return true;
    }
    printf("Error at function dequeue");
    return false;
}

// Function to gain together all tests
bool allTests() {
    return testDequeue() && testEnqueue();
}