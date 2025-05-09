#pragma once

typedef struct Stack Stack;

typedef struct Queue Queue;

Stack* createStack();

void createQueue(struct Queue* queue);

bool isFull(struct Queue* queue);

int dequeue(struct secondStack* stack);

int enqueue(struct firstStack* stack, int value);

void push(struct firstStack* stack, int value);

void pop(struct secondStack* stack);

void deleteQueue(struct Queue* queue);