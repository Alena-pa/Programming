#include <stdio.h>
#include <stdbool.h>
#include "Stack.h"

bool advancedBracketBalance(const char* brackets) {
    Stack* stack = createStack();
    int bracketsRead = 0;
    while (brackets[bracketsRead] != '\0') {
        switch (brackets[bracketsRead]) {
            case '(':
                push(stack, "(");
                break;
            case ')':
                if (top(stack) != NULL && top(stack) == "(") {
                    pop(stack);
                    break;
                }
                else {
                    deleteStack(stack);
                    return false;
                }
            case '{':
                push(stack, "{");
                break;
            case '}':
                if (top(stack) != NULL && top(stack) == "{") {
                    pop(stack);
                    break;
                }
                else {
                    deleteStack(stack);
                    return false;
                }
            case '[':
                push(stack, "[");
                break;
            case ']':
                if (top(stack) != NULL && top(stack) == "[") {
                    pop(stack);
                    break;
                }
                else {
                    deleteStack(stack);
                    return false;
                }
         default:
             break;
        }
        bracketsRead++;
    }
    bool result = top(stack) == NULL;
    deleteStack(stack);
    return result;
}

bool test(void) {
    return (!advancedBracketBalance("{){}") && !advancedBracketBalance("}{") && advancedBracketBalance("[]{}({})"));
}

int main(void) {
    if (!test()) {
        printf("Test Failed!");
        return 1;
    }
}