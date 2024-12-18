#include <stdio.h>
#include <stdbool.h>

typedef struct StackElement {
    int value;
    struct StackElement* next;
} StackElement;

typedef struct Stack {
    StackElement* head;
} Stack;

typedef struct {
    int head;
    int tail;
    int length;
    Stack firstStack;
    Stack secondStack;
} Queue;

Stack* createStack() {
    return (Stack*)calloc(1, sizeof(Stack));
}

void createQueue(Queue* queue) {
    queue->head = 0;
    queue->tail = 0;
    queue->length = 0;
    createStack(&(queue->firstStack));
    createStack(&(queue->secondStack));
}

bool isFull(Queue* queue) {
    if (queue->length != 0) {
        return true;
    }
    return false;
}

int dequeue(Stack* stack) {

}

int enqueue(struct firstStack* stack, int value);

void push(Stack* stack, int value) {
    StackElement* element = malloc(sizeof(StackElement));
    element->value = 1;
    element->next = stack->head;
    stack->head = element;
}

void pop(Stack* stack) {
    StackElement* tmp = stack->head;
    stack->head = stack->head->next;
    free(tmp);
}

void deleteQueue(struct Queue* queue);