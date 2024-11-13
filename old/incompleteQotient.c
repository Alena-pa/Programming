#include <stdio.h>
#include <math.h>

int divide(int firstNumber, int secondNumber){
    int count = 0;
    while (firstNumber >= secondNumber){
        firstNumber = firstNumber - secondNumber;
        count++;
    }
    return count;
}

void incompleteQotient(int firstNumber, int secondNumber){
    if (secondNumber != 0){
        int signOfNumbers = 1;
        if (firstNumber < 0 && secondNumber > 0 || firstNumber > 0 && secondNumber < 0){
            signOfNumbers = -1;
        }
        int tempFirstNumber = firstNumber;
        int tempSecondNumber = secondNumber;
        if (firstNumber < 0){
            tempFirstNumber = -firstNumber;
        }

        if (secondNumber < 0){
            tempSecondNumber = -secondNumber;
        }

        int count = divide(tempFirstNumber, tempSecondNumber);
        int remain = tempFirstNumber - tempSecondNumber * count;

        if (secondNumber < 0 && remain != 0){
            count += 1;
        }

        printf("Div = %d\nremain = %d\n", count * signOfNumbers, remain * signOfNumbers);
    }
    else{
        printf("Incorrect condition! Division by zero!");
    }
}

int main(){
    int firstNumber = -12;
    int secondNumber = 5;
    incompleteQotient(firstNumber, secondNumber);
}