#include <stdio.h>
#include <stdbool.h>
#include "stack.c"
#include <string.h>

#define MAX_SIZE 100

bool isOperation(char element){
    if (element == '+' || element == '-' || element == '*' || element == '/'){
        return true;
    }
    return false;
}

bool isDigit(char element){
    if (element == '0' || element == '1' || element == '2' || element == '3' || element == '4' || element == '5' || element == '6' || element == '7' || element == '8' || element == '9'){
        return true;
    }
    return false;
}

int precedence(char element) {
    if (element == '+' || element == '-'){
         return 1;
    }
    else if (element == '*' || element == '/'){
        return 2;
    }
    return 0;
}

void takeLasttwoElementsFromTheStack(Stack* stack, int* firstNumber, int* secondNumber){
    *firstNumber = theLastElementOfStack(stack);
    pop(stack);
    *secondNumber = theLastElementOfStack(stack);
    pop(stack);
}

void convertStringFromInfixToPostfixNotation(const char* stringToConvert, char* outputString){
    Stack* stack = createStack();
    int elementsRead = 0;
    int indexOfOutputString = 0;
    while (stringToConvert[elementsRead] != '\0'){
        if (isDigit(stringToConvert[elementsRead])){
            outputString[indexOfOutputString] = stringToConvert[elementsRead];
            indexOfOutputString++;
        }
        else if (isOperation(stringToConvert[elementsRead])){
            while (!isEmpty(stack) && precedence(stringToConvert[elementsRead]) < precedence(theLastElementOfStack(stack))){
                outputString[indexOfOutputString] = theLastElementOfStack(stack);
                pop(stack);
                indexOfOutputString++;
            }
            push(stack, stringToConvert[elementsRead]);
        }
        switch (stringToConvert[elementsRead]){
            case '(':
                push(stack, stringToConvert[elementsRead]);
                break;
            case ')':
                while (!isEmpty(stack) && theLastElementOfStack(stack) != '('){
                    outputString[indexOfOutputString] = theLastElementOfStack(stack);
                    pop(stack);
                    indexOfOutputString++;
                }
                pop(stack);
                break;
        }
        elementsRead++;
    }
    while (!isEmpty(stack)){
        outputString[indexOfOutputString] = theLastElementOfStack(stack);
        pop(stack);
    }
    outputString[indexOfOutputString] = '\0';
}

bool firstTest(){
    const char* firstString = {"(1 + 2) * 3"};
    char firstOutputString[MAXSIZE];
    convertStringFromInfixToPostfixNotation(firstString, firstOutputString);
    const char* expectedResultOfFirstString = {"12+3*"};
    if (strcmp(firstOutputString, expectedResultOfFirstString) != 0){
        printf("first test failed! Expected output string 12+3* , but actual output string %s\n", firstOutputString);
        return false;
    }
    return true;
}

bool secondTest(){
    const char* secondString = {"1 + 2 * 3"};
    char secondOutputString[MAXSIZE];
    convertStringFromInfixToPostfixNotation(secondString, secondOutputString);
    const char* expectedResultOfSecondString = {"23*1+"};
    if (strcmp(secondOutputString, expectedResultOfSecondString) != 0){
        printf("second test failed! Expected output string 23*1+ , but actual output string %s\n", secondOutputString);
        return false;
    }
    return true;
}

bool thirdTest(){
    const char* thirdString = {"(1 + 2) - (1 + 1)"};
    char thirdOutputString[MAXSIZE];
    convertStringFromInfixToPostfixNotation(thirdString, thirdOutputString);
    const char* expextedResultOfThirdString = {"12+11+-"};
    if (strcmp(thirdOutputString, expextedResultOfThirdString) != 0){
        printf("third test failed! Expected output string 12+11+- , but actual output string %s\n", thirdOutputString);
        return false;
    }
    return true;
}

bool test(){
    if (!firstTest && !secondTest && !thirdTest){
        return false;
    }
    return true;
}

int main(void){
    if (!test()){
        return 1;
    }
    return 0;
}