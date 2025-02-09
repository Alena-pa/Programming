#pragma once

#include <stdbool.h>
// Defines a structure for a stack
typedef struct Stack Stack;

// Creates and returns a new stack
Stack* createStack();

// Deletes the stack and frees memory
void deleteStack(Stack* stack);

// Pushes a value onto the stack
void push(Stack* stack, int value, int* errorCode);

// Removes the top element from the stack
void pop(Stack* stack, int* errorCode);

// Returns the top element of the stack without removing it
int top(Stack* stack, int* errorCode);

// Check if stack is emty
bool isEmpty(Stack* stack);
