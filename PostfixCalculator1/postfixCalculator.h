#pragma once
#include <stdbool.h>
#include "stack.h"

bool isOperation(char element);

bool isDigit(char element);

void takeLastTwoElementsFromTheStack(Stack* stack, int* firstNumber, int* secondNumber);

int postfixCalculator(char* string);