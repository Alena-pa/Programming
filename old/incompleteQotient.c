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
        int absFirstNumber = firstNumber;
        int absSecondNumber = secondNumber;
        if (firstNumber < 0){
            absFirstNumber = -firstNumber;
        }

        if (secondNumber < 0){
            absSecondNumber = -secondNumber;
        }

        int count = divide(absFirstNumber, absSecondNumber);
        int remain = absFirstNumber - absSecondNumber * count;

        if (signOfNumbers == -1 && remain != 0){
            count += 1;
        }

        printf("Div = %d\nremain = %d\n", count * signOfNumbers, remain);
    }
    else{
        printf("Incorrect condition! Division by zero!");
    }
}

int main(){
    int firstNumber = 59;
    int secondNumber = 9;
    incompleteQotient(firstNumber, secondNumber);
}
