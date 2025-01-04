#include <stdio.h>
#include <stdlib.h>

#include "Stack.h"

typedef struct StackElement {
    char* value;
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

void push(Stack* stack, char* value) {
    StackElement* element = malloc(sizeof(StackElement));
    if (!element) {
        printf("Memory Allocation!");
        return;
    }
    element->value = value;
    element->next = stack->head;
    stack->head = element;
}

void pop(Stack* stack) {
    StackElement* tmp = stack->head;
    if (!tmp) {
        printf("Error: stack->head is NULL");
        return;
    }
    stack->head = stack->head->next;
    free(tmp);
}

char* top(Stack* stack) {
    if (stack->head == NULL) {
        return NULL;
    }
    return stack->head->value;
}