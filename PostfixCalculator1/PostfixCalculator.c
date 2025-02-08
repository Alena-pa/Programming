#include <stdio.h>
#include <stdbool.h>
#include "stack.h"
#include "postfixCalculator.h"

bool isOperation(char element) {
    return element == '+' || element == '-' || element == '*' || element == '/';
}

bool isDigit(char element) {
    return element >= '0' && element <= '9';
}

void takeLastTwoElementsFromTheStack(Stack* stack, int* firstNumber, int* secondNumber, int* errorCode) {
    *firstNumber = top(stack, errorCode);
    if (*errorCode == -2) {
        *errorCode = 1;
        return;
    }
    pop(stack, errorCode);
    *secondNumber = top(stack, errorCode);
    if (*errorCode == -2) {
        *errorCode = 1;
        return;
    }
    pop(stack, errorCode);
}

int calculatePostfix(const char* string, int* errorCode) {
    Stack* stack = createStack();
    if (stack == NULL) {
        *errorCode = -1;
        return -1;
    }
    int elementsRead = 0;
    while (string[elementsRead] != '\0') {
        if (string[elementsRead] == ' ') {
            elementsRead++;
        }
        else if (!isOperation(string[elementsRead]) && !isDigit(string[elementsRead])) {
            *errorCode = 2;
            deleteStack(stack);
            return 2;
        }
        else if (isDigit(string[elementsRead])) {
            push(stack, string[elementsRead] - '0', errorCode);
            if (errorCode == -1) {
                deleteStack(stack);
                return -1;
            }
            elementsRead++;
        }
        else if (isOperation(string[elementsRead])) {
            if (isEmpty(stack)) {
                *errorCode = 3;
                deleteStack(stack);
                return 3;
            }
            int firstNumber = 0;
            int secondNumber = 0;
            takeLastTwoElementsFromTheStack(stack, &firstNumber, &secondNumber, errorCode);
            switch (string[elementsRead]) {
            case '+':
                push(stack, firstNumber + secondNumber, errorCode);
                break;
            case '-':
                push(stack, firstNumber - secondNumber, errorCode);
                break;
            case '*':
                push(stack, firstNumber * secondNumber, errorCode);
                break;
            case '/':
                if (firstNumber == 0) {
                    *errorCode = 5;
                    deleteStack(stack);
                    return 5;
                }
                push(stack, firstNumber / secondNumber, errorCode);
                break;
            default:
                break;
            }
            elementsRead++;
        }
    }
    if (*errorCode != 0 || isEmpty(stack)) {
        deleteStack(stack);
        *errorCode = 4;
        return 4;
    }
    int result = top(stack, errorCode);
    deleteStack(stack);
    return result;
}