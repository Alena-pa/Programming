#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct StackElement {
    int value;
    struct StackElement* next;
} StackElement;

struct Stack {
    StackElement* head;
};

Stack* createStack() {
    return (Stack*)calloc(1, sizeof(Stack));
}

void deleteStack(Stack* stack) {
    if (!stack) {
        return;
    }

    StackElement* current = stack->head;
    while (current != NULL) {
        StackElement* tmp = current;
        current = current->next;
        free(tmp);
    }

    free(stack);
}

void push(Stack* stack, int value, int* errorCode) {
    StackElement* element = (StackElement*)calloc(1, sizeof(StackElement));
    if (element == NULL) {
        *errorCode = -1;
        return;
    }
    element->value = value;
    element->next = stack->head;
    stack->head = element;
}

void pop(Stack* stack, int* errorCode) {
    StackElement* tmp = stack->head;
    if (tmp == NULL) {
        *errorCode = -2;
        return;
    }
    stack->head = stack->head->next;
    free(tmp);
}

int top(Stack* stack, int* errorCode) {
    if (stack->head == NULL) {
        *errorCode = -2;
        return 0;
    }
    return stack->head->value;
}

bool isEmpty(Stack* stack) {
    return NULL == stack->head;
}