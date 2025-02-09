#include <stdbool.h>
#include "stack.h"
#include "sortingStation.h"
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

bool test(void) {
    int errorCode = 0;

    const char* firstString = { "(1 + 2) * 3" };
    char firstOutputString[MAX_SIZE] = { 0 };
    convertStringFromInfixToPostfixNotation(firstString, firstOutputString, &errorCode);
    if (errorCode == 1) {
        printf("Invalid expression at first string\n");
        return false;
    }

    const char* expectedResultOfFirstString = { "12+3*" };
    if (strcmp(firstOutputString, expectedResultOfFirstString) != 0) {
        printf("first test failed! Expected output string 12+3* , but actual output string %s\n", firstOutputString);
        return false;
    }

    const char* secondString = { "1 + 2 * 3" };
    char secondOutputString[MAX_SIZE] = { 0 };
    convertStringFromInfixToPostfixNotation(secondString, secondOutputString, &errorCode);
    if (errorCode == 1) {
        printf("Invalid expression at second string\n");
        return false;
    }

    const char* expectedResultOfSecondString = { "123*+" };
    if (strcmp(secondOutputString, expectedResultOfSecondString) != 0) {
        printf("second test failed! Expected output string 23*1+ , but actual output string %s\n", secondOutputString);
        return false;
    }

    const char* thirdString = { "(1 + 2) - (1 + 1) a" };
    char thirdOutputString[MAX_SIZE] = { 0 };
    convertStringFromInfixToPostfixNotation(thirdString, thirdOutputString, &errorCode);
    if (errorCode == 1) {
        return true;
    }
}
