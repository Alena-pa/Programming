#include "stack.h"
#include "postfixCalculator.h"
#include "test.h"
#include <stdio.h>

int main() {
    if (!test()) {
        printf("Test Failed!");
        return -1;
    }
    int errorCode = 0;
    int result = calculatePostfix("9 6 - 1 2 + *", &errorCode);
    switch (errorCode) {
    case -1:
        printf("Memory Allocation!");
        break;
    case -2:
        printf("Error: stack->head is NULL");
        break;
    case 1:
        printf("First or Second number is NULL\n");
        break;
    case 2:
        printf("Incorrect condition: elements are not correct\n");
        break;
    case 3:
        printf("Incorrect condition: too little elements");
        break;
    case 4:
        printf("Incorrect condition: incorrect number of elements or operations");
        break;
    case 5:
        printf("Division by zero");
        break;
    default:
        break;
    }
}