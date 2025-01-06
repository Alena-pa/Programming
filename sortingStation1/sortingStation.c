#include <stdio.h>
#include <stdbool.h>
#include "stack.h"
#include <string.h>

bool isOperation(char element) {
    return (element == '+' || element == '-' || element == '*' || element == '/');
}

bool isDigit(char element) {
    return (element == '0' || element == '1' || element == '2' || element == '3' || element == '4' || element == '5' || element == '6' || element == '7' || element == '8' || element == '9');
}

int precedence(char element) {
    if (element == '+' || element == '-') {
        return 1;
    }
    else if (element == '*' || element == '/') {
        return 2;
    }
    return 0;
}

void convertStringFromInfixToPostfixNotation(const char* stringToConvert, char* outputString) {
    Stack* stack = createStack();
    int elementsRead = 0;
    int indexOfOutputString = 0;
    while (stringToConvert[elementsRead] != '\0') {
        if (isDigit(stringToConvert[elementsRead])) {
            outputString[indexOfOutputString] = stringToConvert[elementsRead];
            indexOfOutputString++;
        }
        else if (isOperation(stringToConvert[elementsRead])) {
            while (!isEmpty(stack) && precedence(stringToConvert[elementsRead]) <= precedence(top(stack))) {
                outputString[indexOfOutputString] = top(stack);
                pop(stack);
                indexOfOutputString++;
            }
            push(stack, stringToConvert[elementsRead]);
        }
        switch (stringToConvert[elementsRead]) {
        case '(':
            push(stack, stringToConvert[elementsRead]);
            break;
        case ')':
            while (!isEmpty(stack) && top(stack) != '(') {
                outputString[indexOfOutputString] = top(stack);
                pop(stack);
                indexOfOutputString++;
            }
            pop(stack);
            break;
        }
        elementsRead++;
    }
    while (!isEmpty(stack)) {
        outputString[indexOfOutputString] = top(stack);
        pop(stack);
        indexOfOutputString++;
    }
    outputString[indexOfOutputString] = '\0';
    deleteStack(stack);
}