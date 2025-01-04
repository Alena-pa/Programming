#include <stdio.h>
#include <stdbool.h>
#include "Stack.h"

int advancedBracketBalance(char* brackets) {
    Stack* stack = createStack();
    int bracketsRead = 0;
    while (brackets[bracketsRead] != '\0') {
        switch (brackets[bracketsRead]) {
            case '(':
                push(stack, "(");
                break;
            case ')':
                if (top(stack) != 1 && top(stack) == "(") {
                    pop(stack);
                    break;
                }
                else {
                    deleteStack(stack);
                    return 1;
                }
            case '{':
                push(stack, "{");
                break;
            case '}':
                if (top(stack) != 1 && top(stack) == "{") {
                    pop(stack);
                    break;
                }
                else {
                    deleteStack(stack);
                    return 1;
                }
            case '[':
                push(stack, "[");
                break;
            case ']':
                if (top(stack) != 1 && top(stack) == "[") {
                    pop(stack);
                    break;
                }
                else {
                    deleteStack(stack);
                    return 1;
                }
         default:
             break;
        }
        bracketsRead++;
    }
    if (top(stack) == 1) {
        deleteStack(stack);
        return 0;
    }
    deleteStack(stack);
    return 1;
}

bool test(void) {
    char string1 = "{){}";
    char string2 = "}{";
    char string3 = "[]{}({})";
    if (advancedBracketBalance(string1) == 1 && advancedBracketBalance(string2) == 1 && advancedBracketBalance(string3) == 0) {
        return true;
    }
    else {
        return false;
    }
}

int main(void) {
    if (!test()) {
        printf("Test Failed!");
        return 1;
    }
    char stringOfBrackets[100];
    printf("Enter string of brackets: ");
    scanf("%s", stringOfBrackets, 100);
}