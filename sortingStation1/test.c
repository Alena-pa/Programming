#include <stdbool.h>
#include "stack.h"
#include "sortingStation.h"
#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

bool test(void) {
    const char* firstString = { "(1 + 2) * 3" };
    char firstOutputString[MAX_SIZE];
    convertStringFromInfixToPostfixNotation(firstString, firstOutputString);
    const char* expectedResultOfFirstString = { "12+3*" };
    if (strcmp(firstOutputString, expectedResultOfFirstString) != 0) {
        printf("first test failed! Expected output string 12+3* , but actual output string %s\n", firstOutputString);
        return false;
    }
    const char* secondString = { "1 + 2 * 3" };
    char secondOutputString[MAX_SIZE];
    convertStringFromInfixToPostfixNotation(secondString, secondOutputString);
    const char* expectedResultOfSecondString = { "123*+" };
    if (strcmp(secondOutputString, expectedResultOfSecondString) != 0) {
        printf("second test failed! Expected output string 23*1+ , but actual output string %s\n", secondOutputString);
        return false;
    }
    const char* thirdString = { "(1 + 2) - (1 + 1)" };
    char thirdOutputString[MAX_SIZE];
    convertStringFromInfixToPostfixNotation(thirdString, thirdOutputString);
    const char* expextedResultOfThirdString = { "12+11+-" };
    if (strcmp(thirdOutputString, expextedResultOfThirdString) != 0) {
        printf("third test failed! Expected output string 12+11+- , but actual output string %s\n", thirdOutputString);
        return false;
    }
    return true;
}
