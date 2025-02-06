#include <stdio.h>
#include <stdbool.h>
#include "stack.h"
#include "postfixCalculator.h"

bool isOperation(char element) {
    return element == '+' || element == '-' || element == '*' || element == '/';
}

bool isDigit(char element) {
    return element == '0' || element == '1' || element == '2' || element == '3' || element == '4' || element == '5' || element == '6' || element == '7' || element == '8' || element == '9';
}

void takeLastTwoElementsFromTheStack(Stack* stack, int* firstNumber, int* secondNumber, int* errorCode) {
    *firstNumber = top(stack, &errorCode);
    if (firstNumber == NULL && errorCode == -2) {
        *errorCode = 1;
        return;
    }
    pop(stack);
    *secondNumber = top(stack, &errorCode);
    if (secondNumber == NULL && errorCode == -2) {
        *errorCode = 1;
        return;
    }
    pop(stack);
}

int calculatePostfix(const char* string, int* errorCode) {
    Stack* stack = createStack();
    int elementsRead = 0;
    while (string[elementsRead] != '\0') {
        if (string[elementsRead] == ' ') {
            elementsRead++;
        }
        else if (!isOperation(string[elementsRead]) && !isDigit(string[elementsRead])) {
            *errorCode = 2;
            return 2;
        }
        else if (isOperation(string[elementsRead]) && elementsRead < 2) {
            *errorCode = 3;
            return 3;
        }
        else if (isDigit(string[elementsRead])) {
            push(stack, string[elementsRead], &errorCode);
            elementsRead++;
        }
        else if (isOperation(string[elementsRead])) {
            int firstNumber = 0;
            int secondNumber = 0;
            takeLastTwoElementsFromTheStack(stack, &firstNumber, &secondNumber, &errorCode);
            switch (string[elementsRead]) {
            case '+':
                push(stack, firstNumber + secondNumber, &errorCode);
                break;
            case '-':
                push(stack, firstNumber - secondNumber, &errorCode);
                break;
            case '*':
                push(stack, firstNumber * secondNumber, &errorCode);
                break;
            case '/':
                if (firstNumber == 0) {
                    *errorCode = 5;
                    deleteStack(stack);
                    return 5;
                }
                push(stack, firstNumber / secondNumber, &errorCode);
                break;
            default:
                break;
            }
            elementsRead++;
        }
    }
    if (top(stack, &errorCode) == NULL && errorCode == -2) {
        deleteStack(stack);
        *errorCode = 4;
        return 4;
    }
    int result = top(stack, &errorCode);
    deleteStack(stack);
    return result;
}