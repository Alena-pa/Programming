#pragma once
typedef struct Stack Stack;

Stack* createStack();

void deleteStack(Stack* stack);

void push(Stack* stack, char* value);

void pop(Stack* stack);

char* top(Stack* stack);