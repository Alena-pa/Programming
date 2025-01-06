#pragma once
typedef struct Stack Stack;

Stack* createStack();

void deleteStack(Stack* stack);

void push(Stack* stack, int value);

void pop(Stack* stack);

int top(Stack* stack);

int isEmpty(Stack* stack);