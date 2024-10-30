#include <stdio.h>
#include <stdbool.h>
#include "stack.c"

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

void takeLasttwoElementsFromTheStack(Stack* stack, int* firstNumber, int* secondNumber){
    *firstNumber = theLastElementOfStack(stack);
    pop(stack);
    *secondNumber = theLastElementOfStack(stack);
    pop(stack);
}

int postfixCalculator(char* string) {
    Stack* stack = createStack();
    int elementsRead = 0;
    while (string[elementsRead] != EOF){
        if (string[elementsRead] == ' '){
            elementsRead++;
        }
        else if(!isOperation(string[elementsRead] && !isDigit(string[elementsRead]))){
            printf("Incorrect condition");
            return 1;
        }
        else if(isOperation(string[elementsRead]) && elementsRead < 2){
            printf("Incorrect condition!");
            return 1;
        }
        else if(isDigit(string[elementsRead])){
            push(stack, string[elementsRead]);
            elementsRead++;
            }
        else if(isOperation(string[elementsRead])){
            int firstNumber = 0;
            int secondNumber = 0;
            switch (string[elementsRead])
            {
            case '+':
                takeLasttwoElementsFromTheStack(stack, &firstNumber, &secondNumber);
                push(stack, firstNumber + secondNumber);
                break;
            case '-':
                takeLasttwoElementsFromTheStack(stack, &firstNumber, &secondNumber);
                push(stack, firstNumber - secondNumber);
                break;
            case '*':
                takeLasttwoElementsFromTheStack(stack, &firstNumber, &secondNumber);
                push(stack, firstNumber * secondNumber);
                break;
            case '/':
                takeLasttwoElementsFromTheStack(stack, &firstNumber, &secondNumber);
                push(stack, firstNumber / secondNumber);
                break;
            default:
                break;
            elementsRead++;
            }
            }
        }
    if (theLastElementOfStack(stack) == 1){
        printf("Incorrect condition!");
        return 1;
    }
    return theLastElementOfStack(stack);
}

bool test() {
    char firstString[] = { "1 2 + 3 -" };
    char secondString[] = { "+ 1 2 - 3 +" };
    char thirdString[] = { "1 2 + 3 4" };
    if (postfixCalculator(firstString) == 0 && postfixCalculator(secondString) == 1 && postfixCalculator(thirdString) == 1) {
        return true;
    }
    return false;
}

int main() {
    if (!test) {
        printf("Test Failed!");
    }
}