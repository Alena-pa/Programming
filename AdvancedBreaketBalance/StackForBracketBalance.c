#include <stdio.h>
#include <stdlib.h>

#include "StackForBracketBalance.h"

typedef struct StackElement {
    int value;
    struct StackElement* next;
} StackElement;

struct Stack {
    StackElement* head;
};

Stack* createStack()
{
    return (Stack*)calloc(1, sizeof(Stack));
}

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

int theLastElementOfStack(Stack* stack)
{
    if (stack->head == NULL)
    {
        return 1;
    }
    return stack->head->value;
}
