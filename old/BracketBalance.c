#include <stdio.h>
#include <stdbool.h>

bool checkIfBracketBalanceComplete(const char *string){
    int countOfOpeningBrackets = 0;
    int countOfClosingBrackets = 0;

    for (int i = 0; i < strlen(string); i++){
            if (countOfClosingBrackets <= countOfOpeningBrackets){
            if (string[i] == '('){
                countOfOpeningBrackets++;
            }
            if (string[i] == ')'){
                countOfClosingBrackets++;
            }
        }
    }
    if (countOfOpeningBrackets == countOfClosingBrackets){
        return true;
    }
    return false;
}

bool test(){
    return(checkIfBracketBalanceComplete("()()") && !checkIfBracketBalanceComplete(")()") && !checkIfBracketBalanceComplete("())(())"))
}

int main()
{
    if (!test()){
        printf("test failed!")
        return 1;
    }
    if (!checkIfBracketBalanceComplete(")()()()")){
        print("Bracket balance doesn`t complete :(");
        retrun 1;
    }
    printf("Bracket balance complete!");
    return 0;
}
