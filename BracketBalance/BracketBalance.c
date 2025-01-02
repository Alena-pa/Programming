#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isBalanced(const char* string) {
    int countOfOpeningBrackets = 0;
    int countOfClosingBrackets = 0;

    for (int i = 0; i < strlen(string); i++) {
        if (countOfClosingBrackets <= countOfOpeningBrackets) {
            if (string[i] == '(') {
                countOfOpeningBrackets++;
            }
            if (string[i] == ')') {
                countOfClosingBrackets++;
            }
        }
    }
    
    return countOfOpeningBrackets == countOfClosingBrackets;
}

bool test() {
    return(isBalanced("()()") && !isBalanced(")()") && !isBalanced("())(())"));
}

int main()
{
    if (!test()) {
        printf("test failed!");
        return 1;
    }
    if (!isBalanced(")()()()")) {
        printf("Bracket balance doesn`t complete :(");
        return 1;
    }
    printf("Bracket balance complete!");
    return 0;
}