#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

typedef struct StackElement {
    int value;
    struct StackElement* next;
} StackElement;

struct Stack {
    StackElement* head;
};

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

Stack* createStack() {
    return (Stack*)calloc(1, sizeof(Stack));
}
int main(void) {
    Stack* stack = createStack();
    push(stack, 1);
}