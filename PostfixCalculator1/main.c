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
    calculatePostfix("9 6 - 1 2 + *", &errorCode);
    if (errorCode == -1) {
        printf("Memory Allocation!");
    }
    if (errorCode == -2) {
        printf("Error: stack->head is NULL");
    }
    if (errorCode == 1) {
        printf("First or Second number is NULL\n");
    }
    if (errorCode == 2) {
        printf("Incorrect condition: elements are not correct\n");
    }
    if (errorCode == 3) {
        printf("Incorrect condition: too little elements");
    }
    if (errorCode == 4) {
        printf("Incorrect condition: incorrect number of elements or operations");
    }
    if (errorCode == 5) {
        printf("Division by zero");
    }
}