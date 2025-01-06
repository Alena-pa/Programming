#include <stdio.h>
#include <stdbool.h>
#include "stack.h"
#include "postfixCalculator.h"

bool isOperation(char element) {
    if (element == '+' || element == '-' || element == '*' || element == '/') {
        return true;
    }
    return false;
}

bool isDigit(char element) {
    if (element == '0' || element == '1' || element == '2' || element == '3' || element == '4' || element == '5' || element == '6' || element == '7' || element == '8' || element == '9') {
        return true;
    }
    return false;
}

void takeLastTwoElementsFromTheStack(Stack* stack, int* firstNumber, int* secondNumber) {
    *firstNumber = top(stack);
    if (!firstNumber) {
        return;
    }
    pop(stack);
    *secondNumber = top(stack);
    if (!secondNumber) {
        return;
    }
    pop(stack);
}

int postfixCalculator(char* string) {
    Stack* stack = createStack();
    int elementsRead = 0;
    while (string[elementsRead] != '\0') {
        if (string[elementsRead] == ' ') {
            elementsRead++;
        }
        else if (!isOperation(string[elementsRead] && !isDigit(string[elementsRead]))) {
            printf("Incorrect condition\n");
            return 1;
        }
        else if (isOperation(string[elementsRead]) && elementsRead < 2) {
            printf("Incorrect condition!");
            return 1;
        }
        else if (isDigit(string[elementsRead])) {
            push(stack, string[elementsRead]);
            elementsRead++;
        }
        else if (isOperation(string[elementsRead])) {
            int firstNumber = 0;
            int secondNumber = 0;
            switch (string[elementsRead]) {
            case '+':
                takeLastTwoElementsFromTheStack(stack, &firstNumber, &secondNumber);
                push(stack, firstNumber + secondNumber);
                break;
            case '-':
                takeLastTwoElementsFromTheStack(stack, &firstNumber, &secondNumber);
                push(stack, firstNumber - secondNumber);
                break;
            case '*':
                takeLastTwoElementsFromTheStack(stack, &firstNumber, &secondNumber);
                push(stack, firstNumber * secondNumber);
                break;
            case '/':
                takeLastTwoElementsFromTheStack(stack, &firstNumber, &secondNumber);
                push(stack, firstNumber / secondNumber);
                break;
            default:
                break;
                elementsRead++;
            }
        }
    }
    if (!top(stack)) {
        printf("Incorrect condition!");
        deleteStack(stack);
        return 1;
    }
    return top(stack);
}