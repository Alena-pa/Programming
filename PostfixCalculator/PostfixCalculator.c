#include <stdio.h>
#include <stdbool.h>

int postfixCalculator(char *string){
    
}


bool test(){
    char firstString[5] = {"1", "2", "+", "3", "-"};
    char secondString[5] = {"+", "1", "2", "-", "3"};
    char thirdString[5] = {"1", "2", "+", "3", "4"};
    if (postfixCalculator(firstString) == 0 && postfixCalculator(secondString) == 1 && postfixCalculator(thirdString) == 1){
        return true;
    }
    return false;
}

int main(){
    if (!test){
        printf("Test Failed!");
    }
}